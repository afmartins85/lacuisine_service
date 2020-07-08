#ifndef OPERATION_H
#define OPERATION_H

#include "userdata.h"
#include <QByteArray>
#include <QMap>
#include <QSet>
#include <QString>
#include <databaseConnection.h>

class Operation : public DatabaseConnection, public UserData {
 public:
  Operation();
  ~Operation();
  //! Check user from user name and password received
  bool identifyUser(QString &, QString &);
  //! Return the user session list
  QMap<QString, int> &getUserSessionList();
  //! Check if there is an open user session
  bool isSessionUserOpened(const QString &userName);
  //! Check and close user session
  bool closeUserSession(const QString &userName);

 private:
  QMap<QString, int> m_userSessionList;
};

#endif  // OPERATION_H
