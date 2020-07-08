#include "gsoapserverthread.h"
#include <operation.h>

GSoapServerThread::GSoapServerThread(LacuisineBindingService &service, QObject *parent) : QThread(parent) {
  m_servicePtr = &service;
}

/**
 * @brief GSoapServerThread::~GSoapServerThread
 */
GSoapServerThread::~GSoapServerThread() {}

/**
 * @brief GSoapServerThread::run
 */
void GSoapServerThread::run() {
  LOG_F(INFO, "Request Message");
  // TODO: How to Pass Application Data to Service Methods
  // The void *soap.user field can be used to pass application data to service methods. This field should be set before
  // the soap_serve() call.
  //    database_handle_type database_handle;
  //    soap_init(&soap);    soap.user = (void*)database_handle;

  if (m_servicePtr->ssl_accept()) {
    LOG_F(WARNING, "Connection refused! SSL request failed, requires a valid certificate!");
    m_servicePtr->soap_print_fault(stderr);
  } else {
    m_servicePtr->serve();
  }

  m_servicePtr->destroy();
  delete m_servicePtr;
}
