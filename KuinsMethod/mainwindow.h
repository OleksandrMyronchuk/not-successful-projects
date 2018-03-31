#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "customtextedit.h"
#include <QMainWindow>

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
    void on_pushButtonRun_clicked();

    void on_pushButtonStop_clicked();

    void on_pushButtonExit_clicked();

    void on_pushButtonX_clicked();

    void on_pushButtonNotX_clicked();    

    void on_radioButtonPDNF_clicked();

    void on_radioButtonPCNF_clicked();

    void on_spinBoxVarNum_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
