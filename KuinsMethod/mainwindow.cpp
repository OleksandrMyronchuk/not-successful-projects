#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <kuinsmethod.h>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEditInput->setPNFtype(ePNF::PDNF);
    ui->textEditInput->setNumVars(ui->spinBoxVarNum->value());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonRun_clicked()
{
    MLF::kuinsMethod *prob =
    new MLF::kuinsMethod(ui->textEditInput->getExpression());

    delete prob;
}

void MainWindow::on_pushButtonStop_clicked()
{

}

void MainWindow::on_pushButtonExit_clicked()
{
    exit(1);
}

void MainWindow::on_pushButtonX_clicked()
{
    ui->textEditInput->input(eVar::X);
    ui->textEditInput->setFocus();
}

void MainWindow::on_pushButtonNotX_clicked()
{
    ui->textEditInput->input(eVar::notX);
    ui->textEditInput->setFocus();
}

void MainWindow::on_radioButtonPDNF_clicked()
{
    ui->textEditInput->setPNFtype(ePNF::PDNF);
}

void MainWindow::on_radioButtonPCNF_clicked()
{
    ui->textEditInput->setPNFtype(ePNF::PCNF);
}

void MainWindow::on_spinBoxVarNum_valueChanged(int arg1)
{
    ui->textEditInput->setNumVars(arg1);
}
