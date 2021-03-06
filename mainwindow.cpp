#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "identification.h"
#include <QLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFormLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *layout = createLayout();
    setCentralWidget(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QWidget *MainWindow::createLayout(){
    QWidget *layout = new QWidget();
    QVBoxLayout *vertLayout = new QVBoxLayout();
    QHBoxLayout *hboxLayout = new QHBoxLayout();
    QHBoxLayout *bottomLayout = new QHBoxLayout();
    QPushButton *identification = new QPushButton();
    QPushButton *verification = new QPushButton();
    QPushButton *manual = new QPushButton();
    QPushButton *help = new QPushButton();

    QObject::connect(identification,SIGNAL(clicked()),this,SLOT(on_pushButton_Identification_clicked()));
    QObject::connect(verification,SIGNAL(clicked()),this,SLOT(on_pushButton_Verifiaction_clicked()));
    QObject::connect(manual,SIGNAL(clicked()),this,SLOT(on_pushButton_Manual_clicked()));

    identification->setText("Identification");
    verification->setText("Verification");
    manual->setText("Manual");
    help->setText("Help");
    help->setFixedWidth(150);
    hboxLayout->addWidget(identification);
    hboxLayout->addWidget(verification);
    hboxLayout->addWidget(manual);
    bottomLayout->addWidget(help);

    hboxLayout->setSpacing(20);
    hboxLayout->setAlignment(Qt::AlignCenter);
    bottomLayout->setAlignment(Qt::AlignCenter);
    vertLayout->addLayout(hboxLayout);
    vertLayout->addLayout(bottomLayout);
    layout->setLayout(vertLayout);
    return layout;
}

void MainWindow::on_pushButton_Identification_clicked()
{
    this->identification = new Identification();
    this->identification->show();
}

void MainWindow::on_pushButton_Verifiaction_clicked()
{
    this->verification = new Verification();
    this->verification->show();
}

void MainWindow::on_pushButton_Manual_clicked()
{
    this->manual = new Manual();
    this->manual->show();
}
