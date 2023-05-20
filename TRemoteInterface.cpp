//
// Created by kiril on 19.05.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TRemoteInterface.h" resolved

#include "tremoteinterface.h"
#include "ui_TRemoteInterface.h"


TRemoteInterface::TRemoteInterface(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::TRemoteInterface) {
    ui->setupUi(this);
}

TRemoteInterface::~TRemoteInterface() {
    delete ui;
}
