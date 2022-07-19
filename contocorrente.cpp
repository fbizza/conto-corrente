#include "contocorrente.h"
#include <ctime>
#include <QIODevice>
#include <QFile>
#include <QTextStream>
#include <iostream>

void ContoCorrente::diminuisciSaldo(int x) {
    if (Saldo - x >= 0) {
        Saldo -= x;
    }
    else throw "Saldo contabile non sufficiente!";
}

void ContoCorrente::aumentaSaldo(int x) {
        Saldo += x;
}

void ContoCorrente::aggiungiVersamento(Versamento& t) {
    ListaVeramenti.push_back(t);
    std::cout << ListaVeramenti.size() << std::endl;
}

void ContoCorrente::annullaUltimoVersamento() {
    ListaVeramenti.back().annulla();
    ListaVeramenti.pop_back();
    std::cout << ListaVeramenti.size() << std::endl;
}

void ContoCorrente::aggiungiPrelievo(Prelievo& p) {
    ListaPrelievi.push_back(p);
    std::cout << ListaPrelievi.size() << std::endl;
}

void ContoCorrente::annullaUltimoPrelievo() {
    ListaPrelievi.back().annulla();
    ListaPrelievi.pop_back();
    std::cout << ListaPrelievi.size() << std::endl;
}

void ContoCorrente::aggiungiInvestimento(Investimento& i) {
    ListaInvestimenti.push_back(i);
    std::cout << ListaInvestimenti.size() << std::endl;
}

void ContoCorrente::annullaUltimoInvestimento() {
    ListaInvestimenti.back().annulla();
    ListaInvestimenti.pop_back();
    std::cout << ListaInvestimenti.size() << std::endl;
}

void ContoCorrente::aggiungiBonifico(Bonifico& b) {
    ListaBonifici.push_back(b);
    std::cout << ListaBonifici.size() << std::endl;
}

void ContoCorrente::annullaUltimoBonifico() {
    ListaBonifici.back().annulla();
    ListaBonifici.pop_back();
    std::cout << ListaBonifici.size() << std::endl;
}

