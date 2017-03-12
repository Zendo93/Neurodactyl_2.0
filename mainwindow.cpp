#include "mainwindow.h"
#include "ui_mainwindow.h"
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
