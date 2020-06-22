
#include "LacuisineBinding.nsmap"
#include "soapLacuisineBindingService.h"
#include <QString>
#include <loguru.hpp>
#include <operation.h>

int LacuisineBindingService::AccessAuthentication(
    ns1__AccessAuthenticationRequestType *ns1__AccessAuthenticationRequest,
    ns1__AccessAuthenticationResponseType &ns1__AccessAuthenticationResponse) {
  QString company(ns1__AccessAuthenticationRequest->AuthRequest->company.c_str());
  QString credentials(ns1__AccessAuthenticationRequest->AuthRequest->credentials.c_str());
  xsd__base64Binary b64 = ns1__AccessAuthenticationRequest->AuthRequest->signature;

  Operation *database_handle_ptr = static_cast<Operation *>(this->soap->user);
  LOG_F(INFO, "Operation in database: %s", database_handle_ptr->dbName().toLatin1().data());

  LOG_F(INFO, "AccessAuthentication Request from: %s | %s",
        ns1__AccessAuthenticationRequest->AuthRequest->company.c_str(),
        ns1__AccessAuthenticationRequest->AuthRequest->credentials.c_str());

  ns1__AccessAuthenticationResponse.success = true;
  ns1__AccessAuthenticationResponse.response = true;

  return SOAP_OK;
}
