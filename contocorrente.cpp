#include "contocorrente.h"
#include <ctime>
#include <QIODevice>
#include <QFile>
#include <QTextStream>

void ContoCorrente::preleva(int x) {
    if (Saldo - x > 0) {
        Saldo -= x;
    }
    else throw "Saldo contabile non sufficiente!";
    time_t now = time(0);
    std::string dt = ctime(&now);
    QString DataEOra = QString::fromStdString(dt);
    QFile file("C:/Users/bizza/Desktop/Laboratorio di Programmazione/conto-corrente-gui/ListaMovimenti.txt");
          if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
              QTextStream stream(&file);
              stream << "\n" << DataEOra << "Sono stati prelevati " << x << "€";
              stream << "\nNuovo saldo: " << Saldo << "€\n";
              file.close();
          }
}

void ContoCorrente::versamentoBancomat(int x) {
    Saldo += x;
    time_t now = time(0);
    std::string dt = ctime(&now);
    QString DataEOra = QString::fromStdString(dt);
    QFile file("C:/Users/bizza/Desktop/Laboratorio di Programmazione/conto-corrente-gui/ListaMovimenti.txt");
          if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
              QTextStream stream(&file);
              stream << "\n" << DataEOra << "Sono stati versati " << x << "€";
              stream << "\nNuovo saldo: " << Saldo << "€\n";
              file.close();
          }
}

void ContoCorrente::diminuisciSaldo(int x) {
    if (Saldo - x > 0) {
        Saldo -= x;
    }
    else throw "Saldo contabile non sufficiente!";
}

void ContoCorrente::aumentaSaldo(int x) {
        Saldo += x;
}
