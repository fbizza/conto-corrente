#include "investimento.h"
#include <QIODevice>
#include <QFile>
#include <QTextStream>
#include <ctime>

void Investimento::esegui() {
    if (this->Importo >= 0)
        compraAzioni();
    else
        vendiAzioni();
}

void Investimento::annulla() {
    if (this->Importo >= 0) {
        contoCorrente.aumentaSaldo(Importo);
        QString Azione = QString::fromStdString(CodiceAzione);
        QFile file("../ListaMovimenti.txt");
              if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
                  QTextStream stream(&file);
                  stream << "\n" << Data_E_Ora << "È stato annullato l'acquisto di " << Importo << "€ in azioni " << Azione;
                  stream << "\nNuovo saldo: " << contoCorrente.getSaldo() << "€\n";
                  file.close();
              }
    }
    else {
        contoCorrente.aumentaSaldo(Importo);
        QString Azione = QString::fromStdString(CodiceAzione);
        QFile file("../ListaMovimenti.txt");
              if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
                  QTextStream stream(&file);
                  stream << "\n" << Data_E_Ora << "È stata annullata la vendita di azioni " << Azione << " per un valore di " << -Importo << "€";
                  stream << "\nNuovo saldo: " << contoCorrente.getSaldo() << "€\n";
                  file.close();
              }
    }


}

void Investimento::compraAzioni() {
    contoCorrente.diminuisciSaldo(Importo);
    QString Azione = QString::fromStdString(CodiceAzione);
    QFile file("../ListaMovimenti.txt");
          if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
              QTextStream stream(&file);
              stream << "\n" << Data_E_Ora << "Sono stati investiti " << Importo << "€ in azioni " << Azione;
              stream << "\nNuovo saldo: " << contoCorrente.getSaldo() << "€\n";
              file.close();
          }
    contoCorrente.aggiungiInvestimento(*this);
}

void Investimento::vendiAzioni() {
    contoCorrente.diminuisciSaldo(Importo);
    QString Azione = QString::fromStdString(CodiceAzione);
    QFile file("../ListaMovimenti.txt");
          if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
              QTextStream stream(&file);
              stream << "\n" << Data_E_Ora << "Sono state vendute azioni " << Azione << " per un valore di " << -Importo << "€";
              stream << "\nNuovo saldo: " << contoCorrente.getSaldo() << "€\n";
              file.close();
          }
    contoCorrente.aggiungiInvestimento(*this);
}
