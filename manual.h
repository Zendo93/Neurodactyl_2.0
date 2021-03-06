#ifndef MANUAL_H
#define MANUAL_H

#include <QWidget>
#include <QComboBox>
#include <QGraphicsView>
#include "FingerPrintScanner/fingerprintscanner.h"

namespace Ui {
class Manual;
}

class Manual : public QWidget
{
    Q_OBJECT

public:
    explicit Manual(QWidget *parent = 0);
    ~Manual();

public slots:
    void switchDevice1(QString name);
    void switchDevice2(QString name);
    void switchGPU(bool checked);
    void switchCPU(bool checked);

private:
    Ui::Manual *ui;
    FingerPrintScanner *scanner;
    unsigned char *image1;
    unsigned char *image2;
    QGraphicsScene* scene1;
    QGraphicsScene* scene2;
    int counter;
    bool isSenzorSelected(QComboBox *comboBox);
    unsigned char *executeTheScanner(FingerPrintScanner *scanner);
    void drawTheImageFromTheScanner(unsigned char *image, QGraphicsView *graphicsView, QGraphicsScene* scene);
    void drawImageFromTheComputer(QString imageFile,QGraphicsView *graphicsView, QGraphicsScene* scene);
    QString readImageFromComputer();
    void createListForPreProcessing();
    void createListForExtractionLevel2();
    void createListForExtractionLevel1();
    void createListForTrainingSettings();
};

#endif // MANUAL_H
