#ifndef GSOAPSERVERTHREAD_H
#define GSOAPSERVERTHREAD_H

#include <QThread>
#include <gsoap/soapLacuisineBindingService.h>
#include <loguru.hpp>

class GSoapServerThread : public QThread
{
public:
    GSoapServerThread(LacuisineBindingService &service, QObject *parent);
    virtual ~GSoapServerThread();

    void run() override;

private:
    int m_port;
    LacuisineBindingService *m_servicePtr;

};

#endif // GSOAPSERVERTHREAD_H
