#include "operation.h"
#include "loguru.hpp"
#include "qutilitytools.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlRelationalTableModel>
#include <QSqlTableModel>

/**
 * @brief Operation::Operation
 */
Operation::Operation() {
  this->setDriver("QPSQL");
  this->setDbName("lacuisine_db");
  this->setUser("lacuisine_admin");
  this->setPasswd("rasp1b14n");
  this->setHost("127.0.0.1");
  this->setPort(5432);

  this->connectDatabase();
}

Operation::~Operation() { LOG_F(INFO, "Operation Destructor"); }

/**
 * @brief Operation::identifyUser
 * @param userName
 * @return
 */
bool Operation::identifyUser(QString& userName, QString& passwd) {
  LOG_SCOPE_F(INFO, "IdentifyUser");
  QSqlRelationalTableModel model;

  model.setTable("users");
  model.setFilter(QString("user_name=\'%1\'").arg(userName));
  model.setRelation(5, QSqlRelation("profiles", "profile_id", "profile_description"));
  model.setRelation(6, QSqlRelation("companies", "company_id", "company_sample_name"));
  model.select();

  if (model.rowCount() <= 0) {
    LOG_F(WARNING, "USER NOT FOUND!!");
    return false;
  }

  for (int i = 0; i < model.rowCount(); ++i) {
    LOG_F(INFO, "user_id: %d", model.record(i).value("user_id").toInt());
    LOG_F(INFO, "user_name: %s", model.record(i).value("user_name").toString().toLatin1().data());
    LOG_F(INFO, "user_full_name: %s", model.record(i).value("user_full_name").toString().toLatin1().data());
    LOG_F(INFO, "user_passwd: %s", model.record(i).value("user_passwd").toString().toLatin1().data());
    LOG_F(INFO, "user_added: %s", model.record(i).value("user_added").toString().toLatin1().data());
    LOG_F(INFO, "Profile: %s", model.record(i).value("profile_description").toString().toLatin1().data());
    LOG_F(INFO, "Company: %s", model.record(i).value("company_sample_name").toString().toLatin1().data());
  }

  if (passwd.compare(model.record(0).value("user_passwd").toString().toLatin1())) {
    LOG_F(WARNING, "PASSWORD NOT MATCHING!!");
    return false;
  }

  this->setUserDataName(model.record(0).value("user_name").toString());
  this->setUserDataFullName(model.record(0).value("user_full_name").toString());
  this->setUserDataProfile(model.record(0).value("profile_description").toString());
  this->setUserDataCompany(model.record(0).value("profile_description").toString());
  LOG_F(INFO, "USER FOUND!");

  return true;
}

/**
 * @brief Operation::getUserSessionList
 * @return
 */
QMap<QString, int>& Operation::getUserSessionList() { return this->m_userSessionList; }

/**
 * @brief Operation::isSessionUserOpened
 * @return
 */
bool Operation::isSessionUserOpened(const QString& userName) {
  // Check if session is opened for user
  auto it = this->m_userSessionList.find(userName);
  if (it != this->m_userSessionList.end()) {
    return true;
  }
  return false;
}

/**
 * @brief Operation::closeUserSession
 * @param userName
 * @return
 */
bool Operation::closeUserSession(const QString& userName) {
  // Check if session is opened for user
  auto it = this->m_userSessionList.find(userName);
  if (it != this->m_userSessionList.end()) {
    this->m_userSessionList.erase(it);
    return true;
  }

  return false;
}
