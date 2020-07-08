#include "authentication.h"
#include "loguru.hpp"
#include "simplecrypt.h"
#include <QCryptographicHash>
#include <QDebug>
#include <QString>
#include <qutilitytools.h>
/**
 * @brief Authentication::Authentication
 * @param parent
 */
Authentication::Authentication() { LOG_F(INFO, "Authentication CONSTRUCTOR"); }

/**
 * @brief Authentication::~Authentication
 */
Authentication::~Authentication() {}

/**
 * @brief Authentication::genMD5
 * @param passwd
 * @return
 */
QByteArray Authentication::genMD5(QString passwd) {
  QCryptographicHash md5(QCryptographicHash::Md5);
  QByteArray result;

  result = md5.hash(passwd.toLatin1(), QCryptographicHash::Md5);
  return result.toBase64(QByteArray::OmitTrailingEquals);
}

/**
 * @brief Authentication::md5ToString
 * @param array
 * @return
 */
QString Authentication::md5ToString(const QByteArray &array) { return QString::fromUtf8(array); }

/**
 * @brief Authentication::genCipher
 * @param data
 * @param k
 * @return
 */
QString Authentication::genCipher(const QString &data, int k) {
  // Generate a cypher with Sha256 to machine unique Id
  QByteArray cypher = QCryptographicHash::hash(data.toLatin1(), QCryptographicHash::Sha256);
  SimpleCrypt crypto(k);
  return crypto.encryptToString(cypher);
}

/**
 * @brief Authentication::decodeCipher
 * @param data
 * @param k
 * @return
 */
QString Authentication::decodeCipher(const QString &data, int k) {
  //  QByteArray passNoB64 = QByteArray::fromBase64(passwd.toLatin1(), QByteArray::OmitTrailingEquals);
  SimpleCrypt crypto(k);
  QString dataDecoded = crypto.decryptToString(data);
  LOG_F(INFO, "dataDecoded: %s", QUtilityTools::AsciiToHex(dataDecoded).toUtf8().data());
  return dataDecoded;
}
