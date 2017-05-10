#include "identification.h"
#include "ui_identification.h"
#include <QCheckBox>
#include <QFileDialog>
#include "./FingerPrintScanner/fingerprintscanner.h"
#include "./FingerPrintScanner/fxISOdll.h"
#include "./FingerPrintScanner/fxISOenrdlg.h"
#include "./FingerPrintScanner/fxISOAFIS.h"
#include "./FingerPrintScanner/fxISO_Interchange.h"

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

    scene = new QGraphicsScene();
    connect(ui->comboBox,SIGNAL(activated(const QString&)),
            this,SLOT(switchDevice(const QString&)));

    if (isSenzorSelected(ui->comboBox))
    {
        image = executeTheScanner(scanner);
        if (image != NULL)
        {
            drawTheImageFromTheScanner(image,ui->graphicsView_2,scene);
        }
    }
    else
    {
        QString imageFile = readImageFromComputer();
        ui->graphicsView_2->setScene(scene);
    }
}

Identification::~Identification()
{
    delete ui;
    delete scanner;
    delete image;
    delete scene;
}

bool Identification::isSenzorSelected(QComboBox *comboBox){
    if (comboBox->itemText(ui->comboBox->currentIndex()) == "Senzor")
    {
        return true;
    }
    else
    {
        return false;
    }
}

unsigned char *Identification::executeTheScanner(FingerPrintScanner *scanner){
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

void Identification::drawTheImageFromTheScanner(unsigned char *image,QGraphicsView *graphicsView, QGraphicsScene* scene){
    QImage Img(image, 500, 500, QImage::Format_Grayscale8);
    QPixmap item = QPixmap::fromImage(Img);
    scene->addPixmap(item);
    graphicsView->setScene(scene);
}

void Identification::switchDevice(QString name){
    if (name == "Senzor")
    {
        unsigned char *buffer;
        buffer = executeTheScanner(scanner);
        drawTheImageFromTheScanner(buffer,ui->graphicsView_2,scene);
    }
    else
    {
        QString imageFile = readImageFromComputer();
        drawImageFromTheComputer(imageFile,ui->graphicsView_2,scene);
    }
}

QString Identification::readImageFromComputer(){
    QString imageFile;
    imageFile = QFileDialog::getOpenFileName(this,
                                             tr("Open Image"), "",
                                             tr("(*.png *.jpg *.bmp *.tif);;All files (*.*)"));
    return imageFile;
}

void Identification::drawImageFromTheComputer(QString imageFile,QGraphicsView *graphicsView,QGraphicsScene* scene){
    QPixmap image(imageFile);
    scene->addPixmap(image);
    graphicsView->setScene(scene);
}
