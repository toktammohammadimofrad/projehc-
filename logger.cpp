#include "Logger.h"
#include <QDebug>

Logger::Logger()
    : m_logFile("game_log.txt")
{
    if (m_logFile.open(QIODevice::Append | QIODevice::Text)) {
        m_logStream.setDevice(&m_logFile);
    } else {
        qWarning() << "Failed to open log file.";
    }
}

void Logger::writeLog(const QString& message) {
    if (m_logFile.isOpen()) {
        m_logStream << message << "\n";
        m_logStream.flush();
    } else {
        qWarning() << "Log file is not open.";
    }
}
