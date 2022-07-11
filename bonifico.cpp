#include "bonifico.h"
#include <ctime>
#include <QIODevice>
#include <QFile>
#include <QTextStream>

void Bonifico::eseguiBonifico() {
    contoCorrente.diminuisciSaldo(Importo);;
    time_t now = time(0);
    std::string dt = ctime(&now);
    QString DataEOra = QString::fromStdString(dt);
    QString IBAN = QString::fromStdString(IbanDestinatario);
    QFile file("C:/Users/bizza/Desktop/Laboratorio di Programmazione/conto-corrente-gui/ListaMovimenti.txt");
          if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
              QTextStream stream(&file);
              stream << "\n" << DataEOra << "È stato inviato un bonifico da " << Importo << "€ a " << IBAN;
              stream << "\nNuovo saldo: " << contoCorrente.getSaldo() << "€\n";
              file.close();
          }
}

