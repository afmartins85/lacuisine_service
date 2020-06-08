#include "operation.h"

/**
 * @brief Operation::Operation
 */
Operation::Operation() {
  this->setDriver("QPSQL");
  this->setDbName("lacuisine_db");
  this->setUser("postgres");
  this->setPasswd("LCrasp1b14n");
  this->setHost("127.0.0.1");
  this->setPort(5432);

  this->connect();
}
