#ifndef SOAPSERVICE_H
#define SOAPSERVICE_H

#include <QMap>
#include <QObject>
#include <QSet>
#include <QString>

class SoapService : public QObject {
 public:
  explicit SoapService(QObject *parent = nullptr);
  virtual ~SoapService();

  //! Web service Start
  void start(int port);

 signals:

 private:
  QSet<QString> m_SessionOpened;
};

#endif  // SOAPSERVICE_H
