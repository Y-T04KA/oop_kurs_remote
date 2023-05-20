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

void TRemoteInterface::answer(QString msg) {
     ui->output->clear();
     ui->output->setText(msg);
}

void TRemoteInterface::manualBt() {
    unsigned ur, br, bl, ul;
    //red=0, yellow=1, green=2
    if (ui->ur_red->isChecked()) ur = 0; else
        if (ui->ur_yellow->isChecked()) ur = 1; else
            ur = 2;
    if (ui->br_red->isChecked()) br = 0; else
        if (ui->br_yellow->isChecked()) br = 1; else
         br = 2;
    if (ui->bl_red->isChecked()) bl = 0; else
        if (ui->bl_yellow->isChecked()) bl = 1; else
            bl = 2;
    if (ui->ul_red->isChecked()) ul = 0; else
        if (ui->ul_yellow->isChecked()) ul = 1; else
            ul = 2;
    messageBuild(ur,br,bl,ul);
    test.setText(QString().setNum(ur));
    test.show();
}

void TRemoteInterface::yellowBt() {
    //something-something
    messageBuild(1,1,1,1);
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



