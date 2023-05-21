//
// Created by kiril on 19.05.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TRemoteInterface.h" resolved

#include "tremoteinterface.h"
#include "ui_TRemoteInterface.h"
#include "common.h"


TRemoteInterface::TRemoteInterface(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::TRemoteInterface) {
    ui->setupUi(this);

}

TRemoteInterface::~TRemoteInterface() {
    delete ui;
}


void TRemoteInterface::manualBt() {
    unsigned ur, br, bl, ul;
    //red=1, yellow=2, green=3
    if (ui->ur_red->isChecked()) ur = 1; else
        if (ui->ur_yellow->isChecked()) ur = 2; else
            ur = 3;
    if (ui->br_red->isChecked()) br = 1; else
        if (ui->br_yellow->isChecked()) br = 2; else
         br = 3;
    if (ui->bl_red->isChecked()) bl = 1; else
        if (ui->bl_yellow->isChecked()) bl = 2; else
            bl = 3;
    if (ui->ul_red->isChecked()) ul = 1; else
        if (ui->ul_yellow->isChecked()) ul = 2; else
            ul = 3;
    messageBuild(ur,br,bl,ul);
    test.setText(QString().setNum(ur));
    test.show();
}

void TRemoteInterface::yellowBt() {
    //something-something
    messageBuild(2,2,2,2);
    test.setText("yellow");
    test.show();
}

void TRemoteInterface::autoBt() {
    unsigned time = ui->timeBox->value();
    messageBuildTime(time);
    test.setText(QString().setNum(time));
    test.show();
}

void TRemoteInterface::offBt() {
    messageBuildTime(0);
    test.setText("off");
    test.show();
}

void TRemoteInterface::messageBuild(unsigned int ur, unsigned int br, unsigned int bl, unsigned int ul) {
    QString msg; //1,1,1,1 OR 0 OR [TIME]
    msg << QString().setNum(ur);
    msg << QString().setNum(br);
    msg << QString().setNum(bl);
    msg << QString().setNum(ul);
    emit request(msg);
}

void TRemoteInterface::messageBuildTime(unsigned int time) {
    emit request(QString().setNum(time));
}



