#include "investimento.h"
//#include <QIODevice>
//#include <QFile>
//#include <QTextStream>
//#include <ctime>

void Investimento::compraAzioni() {
    contoCorrente.diminuisciSaldo(Importo);
    time_t now = time(0);
    std::string dt = ctime(&now);
//    QString DataEOra = QString::fromStdString(dt);
//    QString Azione = QString::fromStdString(CodiceAzione);
//    QFile file("C:/Users/bizza/Desktop/Laboratorio di Programmazione/conto-corrente-gui/ListaMovimenti.txt");
//    if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
//        QTextStream stream(&file);
//        stream << "\n" << DataEOra << "Sono stati investiti " << Importo << "€ in azioni " << Azione;
//        stream << "\nNuovo saldo: " << contoCorrente.getSaldo() << "€\n";
//        file.close();
//    }
}

void Investimento::vendiAzioni() {
    contoCorrente.aumentaSaldo(Importo);
    time_t now = time(0);
    std::string dt = ctime(&now);
//    QString DataEOra = QString::fromStdString(dt);
//    QString Azione = QString::fromStdString(CodiceAzione);
//    QFile file("C:/Users/bizza/Desktop/Laboratorio di Programmazione/conto-corrente-gui/ListaMovimenti.txt");
//    if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
//        QTextStream stream(&file);
//        stream << "\n" << DataEOra << "Sono state vendute azioni " << Azione << " per un valore di " << Importo << "€";
//        stream << "\nNuovo saldo: " << contoCorrente.getSaldo() << "€\n";
//        file.close();
//    }
}
