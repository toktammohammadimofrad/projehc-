#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QFile>
#include <QTextStream>

class Logger : public QObject {
    Q_OBJECT
public:
    static Logger& instance() {
        static Logger instance;
        return instance;
    }

    void writeLog(const QString& message);

private:
    Logger();
    QFile m_logFile;
    QTextStream m_logStream;
};

#endif
