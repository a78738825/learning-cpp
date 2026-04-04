#include <iostream>

class Log {
  public:
    int logLevelError = 0;
    int logLevelWarn = 1;
    int logLevelInfo = 2;

  private:
    // 'm_' is a convention for "class member variable" aka private variable
    int m_logLevel = logLevelInfo;

  public:
    void setLevel(int level) { m_logLevel = level; }

    void Info(char *message) {
        if (m_logLevel >= logLevelInfo) {
            std::cout << "[INFO]" << message << std::endl;
        }
    }

    void Warn(char *message) {
        if (m_logLevel >= logLevelWarn) {
            std::cout << "[WARN]" << message << std::endl;
        }
    }

    void Error(char *message) {
        if (m_logLevel >= logLevelError) {
            std::cout << "[ERROR]" << message << std::endl;
        }
    }
};

// Example:
/*
void exampleFunc() {
    Log log;
    log.setLevel(log.logLevelError);
    log.Error("Error message!");
}
*/
