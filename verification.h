#ifndef VERIFICATION_H
#define VERIFICATION_H

#include <QWidget>

namespace Ui {
class Verification;
}

class Verification : public QWidget
{
    Q_OBJECT

public:
    explicit Verification(QWidget *parent = 0);
    ~Verification();

private:
    Ui::Verification *ui;
};

#endif // VERIFICATION_H
