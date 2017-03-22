#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "identification.h"
#include "verification.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_Verifiaction_clicked();
    void on_pushButton_Identification_clicked();

private:
    Ui::MainWindow *ui;
    QWidget *createLayout();
    Identification *identification;
    Verification *verification;

};

#endif // MAINWINDOW_H
