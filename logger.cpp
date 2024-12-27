#include "Logger.h"
#include <QDateTime>

Logger::Logger() : m_logFile("game.log") {
    if (m_logFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        m_logStream.setDevice(&m_logFile);
    }
}

void Logger::writeLog(const QString& message) {
    m_logStream << QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") << " - " << message << "\n";
    m_logStream.flush();
}
