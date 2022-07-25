
#include "versamento.h"
#include <QIODevice>
#include <QFile>
#include <QTextStream>

void Versamento::esegui() {
    contoCorrente.aumentaSaldo(Importo);
    QFile file("../ListaMovimenti.txt");
          if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
              QTextStream stream(&file);
              stream << "\n" << Data_E_Ora << "Sono stati versati " << Importo << "€";
              stream << "\nNuovo saldo: " << contoCorrente.getSaldo() << "€\n";
              file.close();
          }
    contoCorrente.aggiungiVersamento(*this);
}

void Versamento::annulla() {
    contoCorrente.diminuisciSaldo(Importo);
    QFile file("../ListaMovimenti.txt");
          if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
              QTextStream stream(&file);
              stream << "\n" << Data_E_Ora << "È stato annullato il versamento di " << Importo << "€";
              stream << "\nNuovo saldo: " << contoCorrente.getSaldo() << "€\n";
              file.close();
          }
}
