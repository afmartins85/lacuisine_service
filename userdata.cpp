#include "userdata.h"
#include "loguru.hpp"

UserData::UserData(QObject *parent) : QObject(parent) {}

/**
 * @brief UserData::userDataName
 * @return
 */
QString UserData::userDataName() const { return m_userDataName; }

/**
 * @brief UserData::setUserDataName
 * @param userDataName
 */
void UserData::setUserDataName(const QString &userDataName) { m_userDataName = userDataName; }

/**
 * @brief UserData::userDataFullName
 * @return
 */
QString UserData::userDataFullName() const { return m_userDataFullName; }

/**
 * @brief UserData::setUserDataFullName
 * @param userDataFullName
 */
void UserData::setUserDataFullName(const QString &userDataFullName) { m_userDataFullName = userDataFullName; }

/**
 * @brief UserData::userDataProfile
 * @return
 */
QString UserData::userDataProfile() const { return m_userDataProfile; }

/**
 * @brief UserData::setUserDataProfile
 * @param userDataProfile
 */
void UserData::setUserDataProfile(const QString &userDataProfile) { m_userDataProfile = userDataProfile; }

/**
 * @brief UserData::userDataCompany
 * @return
 */
QString UserData::userDataCompany() const { return m_userDataCompany; }

/**
 * @brief UserData::setUserDataCompany
 * @param userDataCompany
 */
void UserData::setUserDataCompany(const QString &userDataCompany) { m_userDataCompany = userDataCompany; }
