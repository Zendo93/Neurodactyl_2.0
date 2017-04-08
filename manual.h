#ifndef MANUAL_H
#define MANUAL_H

#include <QWidget>

namespace Ui {
class Manual;
}

class Manual : public QWidget
{
    Q_OBJECT

public:
    explicit Manual(QWidget *parent = 0);
    ~Manual();

private:
    Ui::Manual *ui;
    void createListForPreProcessing();
    void createListForExtractionLevel2();
    void createListForExtractionLevel1();
    void createListForTrainingSettings();
};

#endif // MANUAL_H
