#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "contocorrente.h"
#include "bonifico.h"
#include "investimento.h"
#include "prelievo.h"
#include "versamento.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //---------BOTTONI MENU IN ALTO-----------//

    void on_pushButton_clicked();  // VA ALLA PAGINA DELLE INFORMAZIONI

    void on_pushButton_2_clicked(); // VA ALLA PAGINA DEI PRELIEVI

    void on_pushButton_3_clicked(); // VA ALLA PAGINA DEI VERSAMENTI

    void on_pushButton_4_clicked(); // VA ALLA PAGINA DEI BONIFICI

    void on_pushButton_5_clicked(); // VA ALLA PAGINA DEGLI INVESTIMENTI

    //---------------------------------------//

    void on_pushButton_6_clicked(); // PRELEVA

    void on_pushButton_7_clicked(); // VERSA

    void on_pushButton_9_clicked(); // ESEGUE BONIFICO

    void on_pushButton_10_clicked(); // COMPRA AZIONI

    void on_pushButton_11_clicked(); // VENDI AZIONI

    void on_pushButton_8_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_32_clicked();

private:
    Ui::MainWindow *ui;
    ContoCorrente cc;
};
#endif // MAINWINDOW_H
