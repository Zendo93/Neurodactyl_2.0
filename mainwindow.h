#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "identification.h"

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

private:
    Ui::MainWindow *ui;
    QWidget *createLayout();
    Identification *identification;

};

#endif // MAINWINDOW_H
