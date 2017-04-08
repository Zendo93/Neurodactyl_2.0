#include "manual.h"
#include "ui_manual.h"

Manual::Manual(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Manual)
{
    ui->setupUi(this);
    createListForPreProcessing();
    createListForExtractionLevel2();
    createListForExtractionLevel1();
    createListForTrainingSettings();
}

Manual::~Manual()
{
    delete ui;
}

void Manual::createListForPreProcessing(){
    QCheckBox *checkBox1 = new QCheckBox("Parameter 1");
    QCheckBox *checkBox2 = new QCheckBox("Parameter 2");
    QCheckBox *checkBox3 = new QCheckBox("Parameter 3");

    QGridLayout * layout = new QGridLayout(ui->graphicsView_2);
    layout->setRowMinimumHeight(0,20);
    layout->setRowMinimumHeight(1,20);
    layout->addWidget(checkBox1,0,0,0,0,Qt::AlignTop);
    layout->addWidget(checkBox2,1,0,1,1,Qt::AlignTop);
    layout->addWidget(checkBox3,2,0,2,2,Qt::AlignTop);
}

void Manual::createListForExtractionLevel2(){
    QCheckBox *checkBox1 = new QCheckBox("Parameter 1");
    QCheckBox *checkBox2 = new QCheckBox("Parameter 2");
    QCheckBox *checkBox3 = new QCheckBox("Parameter 3");

    QGridLayout * layout = new QGridLayout(ui->graphicsView_5);
    layout->setRowMinimumHeight(0,20);
    layout->setRowMinimumHeight(1,20);
    layout->addWidget(checkBox1,0,0,0,0,Qt::AlignTop);
    layout->addWidget(checkBox2,1,0,1,1,Qt::AlignTop);
    layout->addWidget(checkBox3,2,0,2,2,Qt::AlignTop);
}

void Manual::createListForExtractionLevel1(){
    QLabel *label1 = new QLabel("Parameter 1");
    QLabel *label2 = new QLabel("Parameter 2");
    QLabel *label3 = new QLabel("Parameter 3");

    QGridLayout * layout = new QGridLayout(ui->graphicsView_4);
    layout->setRowMinimumHeight(0,20);
    layout->setRowMinimumHeight(1,20);
    layout->addWidget(label1,0,0,0,0,Qt::AlignTop);
    layout->addWidget(label2,1,0,1,1,Qt::AlignTop);
    layout->addWidget(label3,2,0,2,2,Qt::AlignTop);
}

void Manual::createListForTrainingSettings(){
    QCheckBox *checkBox1 = new QCheckBox("Parameter 1");
    QCheckBox *checkBox2 = new QCheckBox("Parameter 2");
    QCheckBox *checkBox3 = new QCheckBox("Parameter 3");

    QGridLayout * layout = new QGridLayout(ui->graphicsView_7);
    layout->setRowMinimumHeight(0,20);
    layout->setRowMinimumHeight(1,20);
    layout->addWidget(checkBox1,0,0,0,0,Qt::AlignTop);
    layout->addWidget(checkBox2,1,0,1,1,Qt::AlignTop);
    layout->addWidget(checkBox3,2,0,2,2,Qt::AlignTop);
}
