#include "verification.h"
#include "ui_verification.h"
#include <QPushButton>
#include <QFileDialog>
#include <QGraphicsView>

Verification::Verification(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Verification)
{
    ui->setupUi(this);
    QPushButton *button = new QPushButton("Preprocessing");
    QLabel *label1 = new QLabel("<u>Match Score</u>");
    label1->setStyleSheet("font-size: 10pt;");
    QLabel *label2 = new QLabel("0,76 ...");
    ui->gridLayout->setRowMinimumHeight(0,10);
    ui->gridLayout->setRowMinimumHeight(1,50);
    ui->gridLayout->setRowMinimumHeight(2,0);
    ui->gridLayout->addWidget(label1,0,0,0,0,Qt::AlignCenter);
    ui->gridLayout->addWidget(button,1,0,1,1,Qt::AlignCenter);
    ui->gridLayout->addWidget(label2,2,0,1,1,Qt::AlignCenter);

    scene1 = new QGraphicsScene();
    scene2 = new QGraphicsScene();

    connect(ui->comboBox_2,SIGNAL(activated(const QString&)),
            this,SLOT(switchDevice1(const QString&)));
    connect(ui->comboBox,SIGNAL(activated(const QString&)),
            this,SLOT(switchDevice2(const QString&)));

    if (isSenzorSelected(ui->comboBox))
    {
        image1 = executeTheScanner(scanner);
        drawTheImageFromTheScanner(image1,ui->graphicsView,scene1);
    }
    else
    {
        QString imageFile = readImageFromComputer();
        ui->graphicsView->setScene(scene1);
    }

    if (isSenzorSelected(ui->comboBox_2))
    {
        image2 = executeTheScanner(scanner);
        drawTheImageFromTheScanner(image2,ui->graphicsView_2,scene2);
    }
    else
    {
        QString imageFile = readImageFromComputer();
        ui->graphicsView_2->setScene(scene2);
    }
    //layout->addWidget(checkBox3,2,0,2,2,Qt::AlignTop);
}

Verification::~Verification()
{
    delete ui;
    delete image1;
    delete image2;
    delete scene1;
    delete scene2;
    delete scanner;
}

bool Verification::isSenzorSelected(QComboBox *comboBox){
    if (comboBox->itemText(ui->comboBox->currentIndex()) == "Senzor")
    {
        return true;
    }
    else
    {
        return false;
    }

}

unsigned char *Verification::executeTheScanner(FingerPrintScanner *scanner){
    unsigned char *buffer;
    scanner = new FingerPrintScanner();
    scanner->inicializeScanner();
    scanner->runTheScanner();
    scanner->saveCapturedFingerIntoBuffer();
    buffer = scanner->getBuffer();
    scanner->deinicializeScanner();
    delete scanner;
    return buffer;
}

void Verification::drawTheImageFromTheScanner(unsigned char *image,QGraphicsView *graphicsView,QGraphicsScene* scene){
    QImage Img(image, 500, 500, QImage::Format_Grayscale8);
    QPixmap item = QPixmap::fromImage(Img);
    scene->addPixmap(item);
    graphicsView->setScene(scene);
}

void Verification::switchDevice1(QString name){
    if (name == "Senzor")
    {
        unsigned char *buffer;
        buffer = executeTheScanner(scanner);
        drawTheImageFromTheScanner(buffer,ui->graphicsView_2,scene2);
    }
    else
    {
         QString imageFile = readImageFromComputer();
         drawImageFromTheComputer(imageFile,ui->graphicsView_2,scene2);
    }
}


void Verification::switchDevice2(QString name){
    if (name == "Senzor")
    {
        unsigned char *buffer;
        buffer = executeTheScanner(scanner);
        drawTheImageFromTheScanner(buffer,ui->graphicsView,scene1);
    }
    else
    {
         QString imageFile = readImageFromComputer();
         drawImageFromTheComputer(imageFile,ui->graphicsView,scene1);
    }
}

QString Verification::readImageFromComputer(){
    QString imageFile;
    imageFile = QFileDialog::getOpenFileName(this,
                                             tr("Open Image"), "",
                                             tr("(*.png *.jpg *.bmp *.tif);;All files (*.*)"));
    return imageFile;
}

void Verification::drawImageFromTheComputer(QString imageFile,QGraphicsView *graphicsView,QGraphicsScene* scene){
    QPixmap image(imageFile);
    scene->addPixmap(image);
    graphicsView->setScene(scene);
}


