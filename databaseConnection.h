#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QString>
#include <loguru.hpp>

class DatabaseConnection : public QObject {
 public:
  explicit DatabaseConnection(QObject *parent = nullptr);
  explicit DatabaseConnection(const QString &driver, const QString &dbName, const QString &user, const QString &passwd,
                              const QString &host, int port, QObject *parent = nullptr);

  virtual ~DatabaseConnection();

  //! Get driver for database type
  QString driver() const;
  //! Set driver for connection database
  void setDriver(const QString &driver);

  //! Get database name
  QString dbName() const;
  //! Set database name
  void setDbName(const QString &dbName);

  //! Get user name
  QString user() const;
  //! Set user name
  void setUser(const QString &user);

  //! Get password
  QString passwd() const;
  //! Set password
  void setPasswd(const QString &passwd);

  //! Get host name
  QString host() const;
  //! Set host name
  void setHost(const QString &host);

  //! Get port number
  int port() const;
  //! Set port number
  void setPort(int port);

 public slots:
  //! Assert connection on database
  QSqlError connect(void);

 signals:

 private:
  QString m_driver;
  QString m_dbName;
  QString m_user;
  QString m_passwd;
  QString m_host;
  int m_port;
  QSqlDatabase m_db;
};

#endif  // DATABASECONNECTION_H
