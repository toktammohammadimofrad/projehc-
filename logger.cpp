#include "Logger.h"

Logger::Logger()
    : m_logFile("game.log")
{
    if (!m_logFile.open(QIODevice::Append | QIODevice::Text)) {
        // Handle error opening the log file
    }
}

Logger& Logger::instance()
{
    static Logger logger;
    return logger;
}

void Logger::writeLog(const QString& message)
{
    if (m_logFile.isOpen()) {
        QTextStream out(&m_logFile);
        out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << ": " << message << "\n";
    }
}
