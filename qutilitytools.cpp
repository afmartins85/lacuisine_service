#include "qutilitytools.h"

QUtilityTools::QUtilityTools(QObject *parent) : QObject(parent) {}

/**
 * @brief QUtilityTools::hexToAscii
 *  Transfor hex QString representation to ASCII
 * @param str
 * @return
 */
QString QUtilityTools::hexToAscii(const QString &str) {
  QByteArray ByteArray1 = str.toUtf8();
  const char *chArr1 = ByteArray1.constData();
  QByteArray ByteArray2 = QByteArray::fromHex(chArr1);
  const char *chArr2 = ByteArray2.constData();
  return QString::fromUtf8(chArr2);
}

/**
 * @brief QUtilityTools::AsciiToHex
 * Transfor ASCII QString representation to Hex
 * @param str
 * @return
 */
QString QUtilityTools::AsciiToHex(const QString &str) {
  QByteArray ByteArray1 = str.toUtf8();
  QByteArray ByteArray2 = ByteArray1.toHex();
  const char *chArr1 = ByteArray2.constData();
  return QString::fromUtf8(chArr1);
}
