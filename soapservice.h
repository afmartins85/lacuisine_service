#ifndef SOAPSERVICE_H
#define SOAPSERVICE_H

#include <QObject>

class SoapService : public QObject
{
public:
    explicit SoapService(QObject *parent = nullptr);
    virtual ~SoapService();

    //! Web service Start
    void start (int port);

signals:

};

#endif // SOAPSERVICE_H
