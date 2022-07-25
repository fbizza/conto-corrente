#include "bonifico.h"
#include <ctime>
#include <QIODevice>
#include <QFile>
#include <QTextStream>

void Bonifico::esegui() {
    contoCorrente.diminuisciSaldo(Importo);;
    QString IBAN = QString::fromStdString(IbanDestinatario);
    QFile file("../ListaMovimenti.txt");
          if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
              QTextStream stream(&file);
              stream << "\n" << Data_E_Ora << "È stato inviato un bonifico da " << Importo << "€ a " << IBAN;
              stream << "\nNuovo saldo: " << contoCorrente.getSaldo() << "€\n";
              file.close();
          }
    contoCorrente.aggiungiBonifico(*this);

}

void Bonifico::annulla() {
    contoCorrente.aumentaSaldo(Importo);;
    QString IBAN = QString::fromStdString(IbanDestinatario);
    QFile file("../ListaMovimenti.txt");
          if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
              QTextStream stream(&file);
              stream << "\n" << Data_E_Ora << "È stato annullato il bonifico da " << Importo << "€ a " << IBAN;
              stream << "\nNuovo saldo: " << contoCorrente.getSaldo() << "€\n";
              file.close();
          }

}

