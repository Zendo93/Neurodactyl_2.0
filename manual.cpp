#include "manual.h"
#include "ui_manual.h"
#include <QFileDialog>
#include "./FingerPrintScanner/fingerprintscanner.h"
#include "./FingerPrintScanner/fxISOdll.h"
#include "./FingerPrintScanner/fxISOenrdlg.h"
#include "./FingerPrintScanner/fxISOAFIS.h"
#include "./FingerPrintScanner/fxISO_Interchange.h"

Manual::Manual(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Manual)
{
    ui->setupUi(this);
    createListForPreProcessing();
    createListForExtractionLevel2();
    createListForExtractionLevel1();
    createListForTrainingSettings();

    scene1 = new QGraphicsScene();
    scene2 = new QGraphicsScene();
    counter = 1;

    connect(ui->comboBox,SIGNAL(activated(const QString&)),
            this,SLOT(switchDevice1(const QString&)));

    connect(ui->comboBox_2,SIGNAL(activated(const QString&)),
            this,SLOT(switchDevice2(const QString&)));

    connect(ui->checkBox, SIGNAL(clicked(bool)), this, SLOT(switchGPU(bool)));
    connect(ui->checkBox_2, SIGNAL(clicked(bool)), this, SLOT(switchCPU(bool)));
}

Manual::~Manual()
{
    delete ui;
    delete scanner;
    delete image1;
    delete image2;
    delete scene1;
    delete scene2;
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

bool Manual::isSenzorSelected(QComboBox *comboBox){
    if (comboBox->itemText(ui->comboBox->currentIndex()) == "Senzor")
    {
        return true;
    }
    else
    {
        return false;
    }
}

unsigned char *Manual::executeTheScanner(FingerPrintScanner *scanner){
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

void Manual::drawTheImageFromTheScanner(unsigned char *image,QGraphicsView *graphicsView, QGraphicsScene* scene){
    QImage Img(image, 500, 500, QImage::Format_Grayscale8);
    QPixmap item = QPixmap::fromImage(Img);
    scene->addPixmap(item);
    graphicsView->setScene(scene);
}

void Manual::switchDevice1(QString name){
    if (name == "Senzor")
    {
        image1 = executeTheScanner(scanner);
        drawTheImageFromTheScanner(image1,ui->graphicsView,scene1);
    }
    else
    {
        QString imageFile = readImageFromComputer();
        drawImageFromTheComputer(imageFile,ui->graphicsView,scene1);
    }
}

void Manual::switchDevice2(QString name){
    if (name == "Senzor")
    {
        image2 = executeTheScanner(scanner);
        drawTheImageFromTheScanner(image2,ui->graphicsView_3,scene2);
    }
    else
    {
         QString imageFile = readImageFromComputer();
         drawImageFromTheComputer(imageFile,ui->graphicsView_3,scene2);
    }
}

QString Manual::readImageFromComputer(){
    QString imageFile;
    imageFile = QFileDialog::getOpenFileName(this,
                                             tr("Open Image"), "",
                                             tr("(*.png *.jpg *.bmp *.tif);;All files (*.*)"));
    return imageFile;
}

void Manual::drawImageFromTheComputer(QString imageFile,QGraphicsView *graphicsView,QGraphicsScene* scene){
    QPixmap image(imageFile);
    scene->addPixmap(image);
    graphicsView->setScene(scene);
}

void Manual::switchGPU(bool checked){

    if (checked)
    {
        ui->checkBox_2->setChecked(false);
    }

}

void Manual::switchCPU(bool checked){

    if (checked)
    {
        ui->checkBox->setChecked(false);
    }

}
