#include "soapservice.h"
#include "gsoapserverthread.h"
#include "loguru.hpp"
#include "operation.h"
#include <QDebug>
#include <gsoap/soapLacuisineBindingService.h>

SoapService::SoapService(QObject *parent) : QObject(parent) {}

SoapService::~SoapService() {}

/**
 * @brief SoapService::start
 * @param port
 */
void SoapService::start(int port) {
  LacuisineBindingService service(SOAP_IO_KEEPALIVE);
  service.soap->bind_flags = SO_REUSEADDR;
  service.soap->send_timeout = 30;
  service.soap->recv_timeout = 30;
  service.soap->transfer_timeout = 30;

  soap_ssl_init();
  if (soap_ssl_server_context(service.soap, SOAP_SSL_DEFAULT, "/root/ca-certificates/server.pem",
                              "dU7cOp!25JWp85RWRTKd", "/root/ca-certificates/cacert.pem", NULL, NULL, NULL,
                              "LaCuisine Web Service")) {
    service.soap_print_fault(stderr);
    exit(1);
  }

  Operation database_handle;
  service.soap->user = &database_handle;
  //  if (CRYPTO_thread_setup()) {

  //  }

  LOG_F(INFO, "Sarting to listen on port: %d", port);
  if (soap_valid_socket(service.bind(NULL, port, 100))) {
    LacuisineBindingService *servicePtr = nullptr;
    for (;;) {
      if (soap_valid_socket(service.accept())) {
        servicePtr = service.copy();
        if (servicePtr == NULL) {
          service.soap_force_close_socket();
          // TODO: Implementar um tratamento de erro aqui
          service.soap_print_fault(stderr);
          continue;
        } else {
          // Criar Thread
          GSoapServerThread *thread = new GSoapServerThread(*servicePtr, this);
          connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
          thread->start();
        }
      }
    }
  } else {
    service.soap_print_fault(stderr);
  }
}
