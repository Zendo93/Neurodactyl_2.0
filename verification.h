#ifndef VERIFICATION_H
#define VERIFICATION_H

#include <QWidget>
#include <QGraphicsView>
#include <QComboBox>
#include "FingerPrintScanner/fingerprintscanner.h"

namespace Ui {
class Verification;
}

class Verification : public QWidget
{
    Q_OBJECT

public:
    explicit Verification(QWidget *parent = 0);
    ~Verification();

public slots:
    void switchDevice1(QString name);
    void switchDevice2(QString name);

private:
    Ui::Verification *ui;
    FingerPrintScanner *scanner;
    unsigned char *image1;
    unsigned char *image2;
    bool isSenzorSelected(QComboBox *comboBox);
    unsigned char *executeTheScanner(FingerPrintScanner *scanner);
    void drawTheImageFromTheScanner(unsigned char *image, QGraphicsView *graphicsView);
    void drawImageFromTheComputer(QString imageFile,QGraphicsView *graphicsView);
    QString readImageFromComputer();
};

#endif // VERIFICATION_H
