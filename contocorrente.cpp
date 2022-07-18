#include "contocorrente.h"
#include <ctime>
#include <QIODevice>
#include <QFile>
#include <QTextStream>


void ContoCorrente::diminuisciSaldo(int x) {
    if (Saldo - x >= 0) {
        Saldo -= x;
    }
    else throw "Saldo contabile non sufficiente!";
}

void ContoCorrente::aumentaSaldo(int x) {
        Saldo += x;
}
