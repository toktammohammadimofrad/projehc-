#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

class Logger
{
public:
    static Logger& instance() {
        static Logger instance;
        return instance;
    }

    void writeLog(const QString& message) {
        if (logFile.isOpen()) {
            QTextStream out(&logFile);
            out << QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss.zzz") << " - " << message << "\n";
        }
    }

private:
    Logger() {
        logFile.setFileName("game.log");
        logFile.open(QIODevice::Append | QIODevice::Text);
    }

    ~Logger() {
        if (logFile.isOpen()) {
            logFile.close();
        }
    }

    QFile logFile;
};

#endif // LOGGER_H
