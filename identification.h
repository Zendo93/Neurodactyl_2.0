#ifndef IDENTIFICATION_H
#define IDENTIFICATION_H

#include <QWidget>
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
    bool isSenzorSelected();
    unsigned char *executeTheScanner(FingerPrintScanner *scanner);
    void drawTheImageFromTheScanner(unsigned char *image,Ui::Identification *ui);
};

#endif // IDENTIFICATION_H
