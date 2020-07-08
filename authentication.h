#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <QDebug>

class Authentication {
 public:
  explicit Authentication();
  ~Authentication();

  QByteArray genMD5(QString passwd);
  QString md5ToString(const QByteArray &array);
  //! Encrypt data user
  static QString genCipher(const QString &data, int k);
  //! Decrypt data user
  static QString decodeCipher(const QString &data, int k);
 public slots:

 private:
  bool m_isAcvive;
};

#endif  // AUTHENTICATION_H
