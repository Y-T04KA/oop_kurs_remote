//
// Created by kiril on 19.05.2023.
//

#ifndef OOP_KURS_REMOTE_TREMOTEINTERFACE_H
#define OOP_KURS_REMOTE_TREMOTEINTERFACE_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class TRemoteInterface; }
QT_END_NAMESPACE

class TRemoteInterface : public QMainWindow {
Q_OBJECT

public:
    explicit TRemoteInterface(QWidget *parent = nullptr);

    ~TRemoteInterface() override;

private:
    Ui::TRemoteInterface *ui;
};


#endif //OOP_KURS_REMOTE_TREMOTEINTERFACE_H
