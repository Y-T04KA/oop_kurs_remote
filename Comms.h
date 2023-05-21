//
// Created by kiril on 19.05.2023.
//

#ifndef OOP_KURS_REMOTE_COMMS_H
#define OOP_KURS_REMOTE_COMMS_H
#include <QObject>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>

struct TCommParams {
    QHostAddress rHost;
    quint16 rPort;
    QHostAddress sHost;
    quint16 sPort;
};

class TComms : public QUdpSocket{
    Q_OBJECT
    bool ready;
    TCommParams params;
public:
    TComms(TCommParams&, QObject* parent = nullptr);
signals:
    void received(QByteArray);
public slots:
    void send(const QByteArray&);
private slots:
    void receive();
};


#endif //OOP_KURS_REMOTE_COMMS_H
