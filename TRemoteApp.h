//
// Created by kiril on 19.05.2023.
//

#ifndef OOP_KURS_REMOTE_TREMOTEAPP_H
#define OOP_KURS_REMOTE_TREMOTEAPP_H
#include <QObject>
#include <QApplication>
#include "Comms.h"
#include "tremoteinterface.h"

class TRemoteApp : public QApplication {
    Q_OBJECT
    TComms* comm;
    TRemoteInterface* interface;
public:
    TRemoteApp(int, char**);
public slots:
    void fromComms(const QByteArray&);
    void toComms(const QString&);
};


#endif //OOP_KURS_REMOTE_TREMOTEAPP_H
