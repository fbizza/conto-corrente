#include "prelievo.h"
#include <ctime>
#include <QIODevice>
#include <QFile>
#include <QTextStream>

void Prelievo::esegui() {
    contoCorrente.diminuisciSaldo(Importo);
    time_t now = time(0);
    std::string dt = ctime(&now);
    QString DataEOra = QString::fromStdString(dt);
    QFile file("../ListaMovimenti.txt");
          if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
              QTextStream stream(&file);
              stream << "\n" << DataEOra << "Sono stati prelevati " << Importo << "€";
              stream << "\nNuovo saldo: " << contoCorrente.getSaldo() << "€\n";
              file.close();
          }
    contoCorrente.aggiungiPrelievo(*this);
}


void Prelievo::annulla() {
    contoCorrente.aumentaSaldo(Importo);
    QFile file("../ListaMovimenti.txt");
          if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
              QTextStream stream(&file);
              stream << "\n" << Data_E_Ora << "È stato annullato il prelievo di " << Importo << "€";
              stream << "\nNuovo saldo: " << contoCorrente.getSaldo() << "€\n";
              file.close();
          }

}
