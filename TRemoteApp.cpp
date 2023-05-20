//
// Created by kiril on 19.05.2023.
//

#include "TRemoteApp.h"
#include <QMessageBox>

TRemoteApp::TRemoteApp(int argc, char* argv[]) : QApplication(argc, argv) {
    TCommParams pars = { QHostAddress("127.0.0.1"),10001,QHostAddress("127.0.0.1"),10000 };
    comm = new TComms(pars, this);
    interface = new TRemoteInterface();
    interface->show();
    connect(comm, SIGNAL(received(QByteArray)), this, SLOT(fromComms(QByteArray)));
    connect(interface, SIGNAL(request(QString)), this, SLOT(toComms(QString)));
}

void TRemoteApp::fromComms(QByteArray msg) {
    //interface->answer(QString(msg));
}

void TRemoteApp::toComms(QString msg) {
    comm->send(QByteArray().append(QByteArray().fromStdString(msg.toStdString())));
}
