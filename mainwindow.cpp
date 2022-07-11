#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cc = ContoCorrente(38, "IT3475769587480012", "Francesco Bizzarri");
    cc.versamentoBancomat(10000);
    cc.preleva(300);
    Investimento i(cc, 2);
    i.compraAzioni();
    Investimento ii(cc, 589);
    ii.vendiAzioni();
    Bonifico b(cc, 257);
    b.eseguiBonifico();
    QString SaldoAttuale = QString::fromStdString(std::to_string(cc.getSaldo()));
    ui->label_6->setText(SaldoAttuale);
    QString NomeIntestatario = QString::fromStdString(cc.getIntestatario());
    ui->label_2->setText(NomeIntestatario);
    QString IBAN = QString::fromStdString(cc.getIBAN());
    ui->label_4->setText(IBAN);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString SaldoAttuale = QString::fromStdString(std::to_string(cc.getSaldo()));
    ui->label_6->setText(SaldoAttuale);
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

