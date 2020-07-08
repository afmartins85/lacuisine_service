#ifndef QUTILITYTOOLS_H
#define QUTILITYTOOLS_H

#include <QObject>

class QUtilityTools : public QObject {
  Q_OBJECT
 public:
  explicit QUtilityTools(QObject *parent = nullptr);

  //! Transfor hex QString representation to ASCII
  static QString hexToAscii(const QString &str);
  //! Transfor ASCII QString representation to Hex
  static QString AsciiToHex(const QString &str);
 signals:
};

#endif  // QUTILITYTOOLS_H
