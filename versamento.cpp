#include "versamento.h"
#include <QIODevice>
#include <QFile>
#include <QTextStream>

void Versamento::esegui() {
    contoCorrente.aumentaSaldo(Importo);
    time_t now = time(0);
    std::string dt = ctime(&now);
    QString DataEOra = QString::fromStdString(dt);
    QFile file("C:/Users/bizza/Desktop/Laboratorio di Programmazione/conto-corrente-gui/ListaMovimenti.txt");
          if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
              QTextStream stream(&file);
              stream << "\n" << DataEOra << "Sono stati versati " << Importo << "€";
              stream << "\nNuovo saldo: " << contoCorrente.getSaldo() << "€\n";
              file.close();
          }
}


void Versamento::annulla() {

}
