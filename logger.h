#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

class Logger
{
public:
    static Logger& instance();
    void writeLog(const QString& message);

private:
    Logger();
    QFile m_logFile;
};

#endif // LOGGER_H
