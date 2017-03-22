#include "verification.h"
#include "ui_verification.h"

Verification::Verification(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Verification)
{
    ui->setupUi(this);
    QLabel *label1 = new QLabel("<u>Match Score</u>");
    label1->setStyleSheet("font-size: 10pt;");
    QLabel *label2 = new QLabel("0,76 ...");
    ui->gridLayout->setRowMinimumHeight(0,50);
    ui->gridLayout->setRowMinimumHeight(1,0);
    ui->gridLayout->addWidget(label1,0,0,0,0,Qt::AlignCenter);
    ui->gridLayout->addWidget(label2,1,0,1,1,Qt::AlignCenter);
    //layout->addWidget(checkBox3,2,0,2,2,Qt::AlignTop);
}

Verification::~Verification()
{
    delete ui;
}
