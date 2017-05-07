#include "identification.h"
#include "ui_identification.h"
#include <QCheckBox>

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

    connect(ui->comboBox,SIGNAL(currentIndexChanged(const QString&)),
            this,SLOT(switchDevice(const QString&)));

    if (isSenzorSelected())
    {
        image = executeTheScanner(scanner);
        drawTheImageFromTheScanner(image,ui);
    }
}

Identification::~Identification()
{
    delete ui;
}

bool Identification::isSenzorSelected(){
    if (ui->comboBox->itemText(ui->comboBox->currentIndex()) == "Senzor")
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

void Identification::drawTheImageFromTheScanner(unsigned char *image,Ui::Identification *ui){
    QGraphicsScene* scene = new QGraphicsScene();
    QImage Img(image, 500, 500, QImage::Format_Grayscale8);
    QPixmap item = QPixmap::fromImage(Img);
    scene->addPixmap(item);
    ui->graphicsView_2->setScene(scene);
    //delete scene;
}

void Identification::switchDevice(QString name){
    if (name == "Senzor")
    {
        unsigned char *buffer;
        buffer = executeTheScanner(scanner);
        drawTheImageFromTheScanner(buffer,ui);
    }
    else
    {
         QGraphicsScene* scene = new QGraphicsScene();
         ui->graphicsView_2->setScene(scene);
    }
}

