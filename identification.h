#ifndef IDENTIFICATION_H
#define IDENTIFICATION_H

#include <QWidget>

namespace Ui {
class Identification;
}

class Identification : public QWidget
{
    Q_OBJECT

public:
    explicit Identification(QWidget *parent = 0);
    ~Identification();

private:
    Ui::Identification *ui;
};

#endif // IDENTIFICATION_H
