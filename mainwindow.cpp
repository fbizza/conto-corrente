#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cc = ContoCorrente(0, "IT3475769587480012", "Francesco Bizzarri");
    QString SaldoAttuale = QString::fromStdString(std::to_string(cc.getSaldo()));
    ui->label_6->setText(SaldoAttuale);
    QString NomeIntestatario = QString::fromStdString(cc.getIntestatario());
    ui->label_2->setText(NomeIntestatario);
    QString IBAN = QString::fromStdString(cc.getIBAN());
    ui->label_4->setText(IBAN);
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_11->setText("");
    ui->label_13->setText("");
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


void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}



void MainWindow::on_pushButton_6_clicked()  //PRELEVA
{
    if (ui->radioButton->isChecked()) {
        try {
            Prelievo p(cc, 20);
            p.esegui();
            ui->label_11->setText("SONO STATI CORRETTAMENTE PRELEVATI 20€");
            }  catch (const char* messaggio) {
                std::cout << messaggio << std::endl;
                ui->label_11->setText("NESSUNA OPERAZIONE EFFETTUATA");
        }
    }
    else if (ui->radioButton_2->isChecked()){
        try {
            Prelievo p(cc, 50);
            p.esegui();
            ui->label_11->setText("SONO STATI CORRETTAMENTE PRELEVATI 50€");
            }  catch (const char* messaggio) {
                std::cout << messaggio << std::endl;
                ui->label_11->setText("NESSUNA OPERAZIONE EFFETTUATA");
        }
    }
    else if (ui->radioButton_3->isChecked()){
        try {
            Prelievo p(cc, 75);
            p.esegui();
            ui->label_11->setText("SONO STATI CORRETTAMENTE PRELEVATI 75€");
            }  catch (const char* messaggio) {
                std::cout << messaggio << std::endl;
                ui->label_11->setText("NESSUNA OPERAZIONE EFFETTUATA");
        }
    }
    else if (ui->radioButton_4->isChecked()){
        try {
            Prelievo p(cc, 100);
            p.esegui();
            ui->label_11->setText("SONO STATI CORRETTAMENTE PRELEVATI 100€");
            }  catch (const char* messaggio) {
                std::cout << messaggio << std::endl;
                ui->label_11->setText("NESSUNA OPERAZIONE EFFETTUATA");
        }
    }
    else if (ui->radioButton_5->isChecked()){
        try {
            Prelievo p(cc, 250);
            p.esegui();
            ui->label_11->setText("SONO STATI CORRETTAMENTE PRELEVATI 250€");
            }  catch (const char* messaggio) {
                std::cout << messaggio << std::endl;
                ui->label_11->setText("NESSUNA OPERAZIONE EFFETTUATA");
        }
    }
    else if (ui->radioButton_6->isChecked()){
        try {
            Prelievo p(cc, 500);
            p.esegui();
            ui->label_11->setText("SONO STATI CORRETTAMENTE PRELEVATI 500€");
            }  catch (const char* messaggio) {
                std::cout << messaggio << std::endl;
                ui->label_11->setText("NESSUNA OPERAZIONE EFFETTUATA");
        }
    }
    else if (ui->radioButton_7->isChecked()){
        try {
            Prelievo p(cc, ui->spinBox->value());
            p.esegui();
            std::string s = "SONO STATI CORRETTAMENTE PRELEVATI " + std::to_string(ui->spinBox->value()) + "€";
            ui->label_11->setText(QString::fromStdString(s));
        } catch (const char* messaggio) {
            std::cout << messaggio << std::endl;
            ui->label_11->setText("NESSUNA OPERAZIONE EFFETTUATA");
        }
    }
    else ui->label_11->setText("NESSUNA OPERAZIONE EFFETTUATA");
}


void MainWindow::on_pushButton_7_clicked()  //VERSA
{
    if (ui->radioButton_8->isChecked()) {
        Versamento v(cc, 20);
        v.esegui();
        ui->label_13->setText("SONO STATI CORRETTAMENTE VERSATI 20€");
    }
    else if (ui->radioButton_9->isChecked()){
        Versamento v(cc, 50);
        v.esegui();
        ui->label_13->setText("SONO STATI CORRETTAMENTE VERSATI 50€");
    }
    else if (ui->radioButton_10->isChecked()){
        Versamento v(cc, 75);
        v.esegui();
        ui->label_13->setText("SONO STATI CORRETTAMENTE VERSATI 75€");
    }
    else if (ui->radioButton_11->isChecked()){
        Versamento v(cc, 100);
        v.esegui();
        ui->label_13->setText("SONO STATI CORRETTAMENTE VERSATI 100€");
    }
    else if (ui->radioButton_12->isChecked()){
        Versamento v(cc, 250);
        v.esegui();
        ui->label_13->setText("SONO STATI CORRETTAMENTE VERSATI 250€");
    }
    else if (ui->radioButton_13->isChecked()){
        Versamento v(cc, 500);
        v.esegui();
        ui->label_13->setText("SONO STATI CORRETTAMENTE VERSATI 500€");
    }
    else if (ui->radioButton_14->isChecked()){
        Versamento v(cc, ui->spinBox_2->value());
        v.esegui();
        std::string s = "SONO STATI CORRETTAMENTE VERSATI " + std::to_string(ui->spinBox_2->value()) + "€";
        ui->label_13->setText(QString::fromStdString(s));
    }
    else ui->label_13->setText("NESSUNA OPERAZIONE EFFETTUATA");
}


void MainWindow::on_pushButton_9_clicked() //ESEGUI BONIFICO
{
    std::string iban = ui->lineEdit->text().toStdString();
    try {
        Bonifico b(cc, ui->spinBox_3->value(), iban);
        b.esegui();
    }  catch (const char* messaggio) {
        std::cout << messaggio << std::endl;
    }
}



void MainWindow::on_pushButton_10_clicked()  //COMPRA AZIONI
{
    std::string Codice = ui->lineEdit_2->text().toStdString();
    try {
        Investimento i(cc, ui->spinBox_4->value(), Codice);
        i.esegui();
    }  catch (const char* messaggio) {
        std::cout << messaggio << std::endl;
    }
}


void MainWindow::on_pushButton_11_clicked() //VENDI AZIONI
{
    std::string Codice = ui->lineEdit_4->text().toStdString();
    Investimento i(cc, -(ui->spinBox_6->value()), Codice);
    i.esegui();
}




void MainWindow::on_pushButton_33_clicked()
{
    try {
        cc.annullaUltimoPrelievo();
    }  catch (const char* messaggio) {
        std::cout << messaggio << std::endl;
    }

}


void MainWindow::on_pushButton_34_clicked()
{
    try {
        cc.annullaUltimoVersamento();
    }  catch (const char* messaggio) {
        std::cout << messaggio << std::endl;
    }

}


void MainWindow::on_pushButton_35_clicked()
{
    try {
        cc.annullaUltimoBonifico();
    }  catch (const char* messaggio) {
        std::cout << messaggio << std::endl;
    }

}


void MainWindow::on_pushButton_32_clicked()
{
    try {
        cc.annullaUltimoInvestimento();
    }  catch (const char* messaggio) {
        std::cout << messaggio << std::endl;
    }
}

