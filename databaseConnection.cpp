#include "databaseConnection.h"

/**
 * @brief DatabaseConnection::DatabaseConnection
 * @param parent
 */
DatabaseConnection::DatabaseConnection(QObject *parent) : QObject(parent) {
  this->m_driver.clear();
  this->m_dbName.clear();
  this->m_user.clear();
  this->m_passwd.clear();
  this->m_host.clear();
  this->m_port = 0;
}

/**
 * @brief DatabaseConnection::DatabaseConnection
 * @param driver
 * @param dbName
 * @param user
 * @param passwd
 * @param host
 * @param port
 * @param parent
 */
DatabaseConnection::DatabaseConnection(const QString &driver, const QString &dbName, const QString &user,
                                       const QString &passwd, const QString &host, int port, QObject *parent)
    : QObject(parent) {
  this->setDriver(driver);
  this->setDbName(dbName);
  this->setUser(user);
  this->setPasswd(passwd);
  this->setHost(host);
  this->setPort(port);

  QSqlError err = this->connectDatabase();

  if (!err.isValid()) {
    LOG_F(ERROR, "%s", err.text().toLatin1().data());
  } else {
    LOG_F(INFO, "%s", err.text().toLatin1().data());
  }
}

/**
 * @brief DatabaseConnection::~DatabaseConnection
 */
DatabaseConnection::~DatabaseConnection() {
  if (this->m_db.isOpen() == true) {
    this->m_db.close();
  }

  this->m_driver.clear();
  this->m_dbName.clear();
  this->m_user.clear();
  this->m_passwd.clear();
  this->m_host.clear();
  this->m_port = 0;
}

/**
 * @brief DatabaseConnection::driver
 * @return
 */
QString DatabaseConnection::driver() const { return m_driver; }

/**
 * @brief DatabaseConnection::setDriver
 * @param driver
 */
void DatabaseConnection::setDriver(const QString &driver) { m_driver = driver; }

/**
 * @brief DatabaseConnection::dbName
 * @return
 */
QString DatabaseConnection::dbName() const { return m_dbName; }

/**
 * @brief DatabaseConnection::setDbName
 * @param dbName
 */
void DatabaseConnection::setDbName(const QString &dbName) { m_dbName = dbName; }

/**
 * @brief DatabaseConnection::user
 * @return
 */
QString DatabaseConnection::user() const { return m_user; }

/**
 * @brief DatabaseConnection::setUser
 * @param user
 */
void DatabaseConnection::setUser(const QString &user) { m_user = user; }

/**
 * @brief DatabaseConnection::passwd
 * @return
 */
QString DatabaseConnection::passwd() const { return m_passwd; }

/**
 * @brief DatabaseConnection::setPasswd
 * @param passwd
 */
void DatabaseConnection::setPasswd(const QString &passwd) { m_passwd = passwd; }

/**
 * @brief DatabaseConnection::host
 * @return
 */
QString DatabaseConnection::host() const { return m_host; }

/**
 * @brief DatabaseConnection::setHost
 * @param host
 */
void DatabaseConnection::setHost(const QString &host) { m_host = host; }

/**
 * @brief DatabaseConnection::port
 * @return
 */
int DatabaseConnection::port() const { return m_port; }

/**
 * @brief DatabaseConnection::setPort
 * @param port
 */
void DatabaseConnection::setPort(int port) { m_port = port; }

/**
 * @brief DatabaseConnection::getDbInstance
 * @return
 */
const QSqlDatabase &DatabaseConnection::getDbInstance() { return this->m_db; }

/**
 * @brief DatabaseConnection::connectDatabase
 * @return
 */
QSqlError DatabaseConnection::connectDatabase(void) {
  QSqlError err;
  this->m_db = QSqlDatabase::addDatabase(this->driver());
  this->m_db.setDatabaseName(this->dbName());
  this->m_db.setHostName(this->host());
  this->m_db.setPort(this->port());
  if (!this->m_db.open(this->user(), this->passwd())) {
    err = this->m_db.lastError();
    LOG_F(ERROR, "%s", err.text().toLatin1().data());
  }

  return err;
}
