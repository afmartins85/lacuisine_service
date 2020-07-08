#ifndef USERDATA_H
#define USERDATA_H

#include <QObject>

class UserData : public QObject {
  Q_OBJECT
 public:
  explicit UserData(QObject *parent = nullptr);

  //! Return user name
  QString userDataName() const;
  //! Set user name
  void setUserDataName(const QString &userDataName);
  //! Return user full name
  QString userDataFullName() const;
  //! Set user full name
  void setUserDataFullName(const QString &userDataFullName);
  //! Return user profile
  QString userDataProfile() const;
  //! Set user profile
  void setUserDataProfile(const QString &userDataProfile);
  //! Return user-linked company
  QString userDataCompany() const;
  //! Set user-linked company
  void setUserDataCompany(const QString &userDataCompany);

 signals:

 private:
  QString m_userDataName;
  QString m_userDataFullName;
  QString m_userDataProfile;
  QString m_userDataCompany;
};

#endif  // USERDATA_H
