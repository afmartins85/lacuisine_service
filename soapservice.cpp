#include "soapservice.h"
#include "gsoapserverthread.h"
#include "loguru.hpp"
#include <gsoap/soapLacuisineBindingService.h>
#include <QDebug>

SoapService::SoapService(QObject *parent) : QObject(parent)
{

}

SoapService::~SoapService()
{

}

/**
 * @brief SoapService::start
 * @param port
 */
void SoapService::start(int port)
{
    LacuisineBindingService service(SOAP_IO_KEEPALIVE);
    service.soap->send_timeout = 30;
    service.soap->recv_timeout = 30;
    service.soap->transfer_timeout = 30;

    LOG_F(INFO, "Sarting to listen on port: %d", port);
    if (soap_valid_socket(service.bind(NULL, port, 100))) {
        LacuisineBindingService *servicePtr = nullptr;
        for (;;) {
            if (soap_valid_socket(service.accept())) {
                servicePtr = service.copy();
                if (servicePtr == NULL) {
                    //TODO: Implementar um tratamento de erro aqui
                    service.soap_print_fault(stderr);
                }
                // Criar Thread
                GSoapServerThread *thread = new GSoapServerThread(*servicePtr, this);
                connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
                thread->start();
            }
        }
    } else {
        service.soap_print_fault(stderr);
    }
}
