
#include "LacuisineBinding.nsmap"
#include "soapLacuisineBindingService.h"
#include <QByteArray>
#include <QCryptographicHash>
#include <QMap>
#include <QString>
#include <QtGlobal>
#include <authentication.h>
#include <loguru.hpp>
#include <operation.h>
#include <qutilitytools.h>
#include <simplecrypt.h>

/**
 * @brief getProfileId
 * @param str
 * @return
 */
ns2__ProfileEnum getProfileId(const QString &str) {
  if (!str.compare("ProfileMaster")) {
    return ns2__ProfileEnum__ProfileMaster;
  } else if (!str.compare("ProfileAdministrador")) {
    return ns2__ProfileEnum__ProfileAdministrador;
  } else if (!str.compare("ProfileCheckout")) {
    return ns2__ProfileEnum__ProfileCheckout;
  } else if (!str.compare("ProfileKitchen")) {
    return ns2__ProfileEnum__ProfileKitchen;
  } else if (!str.compare("ProfileUser")) {
    return ns2__ProfileEnum__ProfileUser;
  }
  return ns2__ProfileEnum__ProfileUnknown;
}

/**
 * @brief LacuisineBindingService::OpenUserSession
 * @param ns1__OpenUserSessionRequest
 * @param ns1__OpenUserSessionResponse
 * @return
 */
int LacuisineBindingService::OpenUserSession(ns1__OpenUserSessionRequestType *ns1__OpenUserSessionRequest,
                                             ns1__OpenUserSessionResponseType &ns1__OpenUserSessionResponse) {
  QString userName(ns1__OpenUserSessionRequest->userName.c_str());
  QString deviceId(ns1__OpenUserSessionRequest->deviceId.c_str());
  QString passwd(ns1__OpenUserSessionRequest->passwd.c_str());
  LOG_SCOPE_F(INFO, "OpenUserSessionRequest:");
  LOG_F(INFO, "UserName: %s", userName.toLatin1().data());
  //  LOG_F(INFO, "password: %s", passwd.toLatin1().data());
  LOG_F(INFO, "sourceDeviceId: %s", deviceId.toLatin1().data());

  ns1__OpenUserSessionResponse.success = true;

  Operation *database_handle_ptr = static_cast<Operation *>(this->soap->user);

  // Check if session is opened for user
  if (database_handle_ptr->isSessionUserOpened(userName) == true) {
    LOG_F(WARNING, "Session is opened for user: %s", userName.toLatin1().data());
    ns1__OpenUserSessionResponse.response = ns2__SessionEnum::ns2__SessionEnum__SessionIsOpened;
    return SOAP_OK;
  }

  if (database_handle_ptr->identifyUser(userName, passwd) == true) {
    ns2__UserDataSession *userDataSession = new ns2__UserDataSession;
    userDataSession->fullName = database_handle_ptr->userDataFullName().toStdString();
    userDataSession->challenge = qrand();
    userDataSession->profileType = getProfileId(database_handle_ptr->userDataProfile());
    ns1__OpenUserSessionResponse.userDataSession = userDataSession;
    ns1__OpenUserSessionResponse.response = ns2__SessionEnum::ns2__SessionEnum__SessionOk;

    // Register the session opened
    database_handle_ptr->getUserSessionList().insert(userName, userDataSession->challenge);
  } else {
    ns1__OpenUserSessionResponse.response = ns2__SessionEnum::ns2__SessionEnum__SessionCannotBeOpened;
  }
  return SOAP_OK;
}

/**
 * @brief LacuisineBindingService::CloseUserSession
 * @param ns1__DataUserSessionRequest
 * @param ns1__CloseUserSessionResponse
 * @return
 */
int LacuisineBindingService::CloseUserSession(ns1__CloseUserSessionRequestType *ns1__CloseUserSessionRequest,
                                              ns1__CloseUserSessionResponseType &ns1__CloseUserSessionResponse) {
  QString userName(ns1__CloseUserSessionRequest->userName.c_str());
  QString deviceId(ns1__CloseUserSessionRequest->deviceId.c_str());
  QString passwd(ns1__CloseUserSessionRequest->passwd.c_str());

  LOG_SCOPE_F(INFO, "CloseUserSessionRequest:");
  ns1__CloseUserSessionResponse.success = true;

  Operation *database_handle_ptr = static_cast<Operation *>(this->soap->user);

  // Check if session is opened for user
  auto it = database_handle_ptr->getUserSessionList().find(userName);
  if (it == database_handle_ptr->getUserSessionList().end()) {
    LOG_F(WARNING, "Session not found for user: %s", userName.toLatin1().data());
    ns1__CloseUserSessionResponse.response = ns2__SessionEnum::ns2__SessionEnum__SessionNotFound;
    return SOAP_OK;
  }

  if (database_handle_ptr->identifyUser(userName, passwd) == true) {
    // Remove user from registers
    database_handle_ptr->getUserSessionList().erase(it);
    LOG_F(INFO, "Session closed to %s", userName.toLatin1().data());
  }

  ns1__CloseUserSessionResponse.response = ns2__SessionEnum::ns2__SessionEnum__SessionIsSuccessfullyClosed;
  return SOAP_OK;
}
