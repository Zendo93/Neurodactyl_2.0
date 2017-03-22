#include "identification.h"
#include "ui_identification.h"
#include <QCheckBox>
Identification::Identification(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Identification)
{
    ui->setupUi(this);

    QCheckBox *checkBox1 = new QCheckBox("senzor option 1");
    QCheckBox *checkBox2 = new QCheckBox("senzor option 2");
    QCheckBox *checkBox3 = new QCheckBox("senzor option 3");

    QGridLayout * layout = new QGridLayout(ui->graphicsView);
    layout->setRowMinimumHeight(0,20);
    layout->setRowMinimumHeight(1,20);
    layout->addWidget(checkBox1,0,0,0,0,Qt::AlignTop);
    layout->addWidget(checkBox2,1,0,1,1,Qt::AlignTop);
    layout->addWidget(checkBox3,2,0,2,2,Qt::AlignTop);
}

Identification::~Identification()
{
    delete ui;
}
