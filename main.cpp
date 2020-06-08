#include <QCoreApplication>
#include <soapservice.h>
#include <loguru.hpp>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SoapService service;

    loguru::init(argc, argv);

    LOG_F(INFO, "LaCuisine Server Starting...");
    service.start(9090);

    return a.exec();
}
