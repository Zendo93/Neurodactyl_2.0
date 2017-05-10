#ifndef IDENTIFICATION_H
#define IDENTIFICATION_H

#include <QWidget>
#include <QComboBox>
#include <QGraphicsView>
#include "FingerPrintScanner/fingerprintscanner.h"

namespace Ui {
class Identification;
}

class Identification : public QWidget
{
    Q_OBJECT

public:
    explicit Identification(QWidget *parent = 0);
    ~Identification();
public slots:
    void switchDevice(QString name);

private:
    Ui::Identification *ui;
    FingerPrintScanner *scanner;
    unsigned char *image;
    QGraphicsScene* scene;
    bool isSenzorSelected(QComboBox *comboBox);
    unsigned char *executeTheScanner(FingerPrintScanner *scanner);
    void drawTheImageFromTheScanner(unsigned char *image, QGraphicsView *graphicsView, QGraphicsScene* scene);
    void drawImageFromTheComputer(QString imageFile,QGraphicsView *graphicsView, QGraphicsScene* scene);
    QString readImageFromComputer();
};

#endif // IDENTIFICATION_H
