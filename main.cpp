#include <QCoreApplication>
#include <initializer_list>
#include <loguru.hpp>
#include <signal.h>
#include <soapservice.h>
#include <unistd.h>

static QMap<int, QString> sigMap{{1, "SIGHUP"},   {2, "SIGINT"},   {3, "SIGQUIT"},  {4, "SIGABRT"},
                                 {9, "SIGKILL"},  {10, "SIGBUS"},  {11, "SIGSEGV"}, {12, "SIGSYS"},
                                 {13, "SIGPIPE"}, {14, "SIGALRM"}, {15, "SIGTERM"}, {17, "SIGSTOP"}};

void ignoreUnixSignals(std::initializer_list<int> ignoreSignals) {
  // all these signals will be ignored.
  for (int sig : ignoreSignals) signal(sig, SIG_IGN);
}

void catchUnixSignals(std::initializer_list<int> quitSignals) {
  auto handler = [](int sig) -> void {
    QString sigString = sigMap.find(sig).value();
    // blocking and not aysnc-signal-safe func are valid
    LOG_F(INFO, "quit the application by signal(%d)(%s).\n", sig, sigString.toLatin1().data());
    QCoreApplication::quit();
  };

  sigset_t blocking_mask;
  sigemptyset(&blocking_mask);
  for (auto sig : quitSignals) sigaddset(&blocking_mask, sig);

  struct sigaction sa;
  sa.sa_handler = handler;
  sa.sa_mask = blocking_mask;
  sa.sa_flags = 0;

  for (auto sig : quitSignals) sigaction(sig, &sa, nullptr);
}

int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);

  SoapService service;

  loguru::init(argc, argv);
  catchUnixSignals({SIGQUIT, SIGINT, SIGTERM, SIGSEGV, SIGHUP});

  LOG_F(INFO, "LaCuisine Server Starting...");
  service.start(9090);

  return a.exec();
}
