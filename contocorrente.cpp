#include "contocorrente.h"
#include <ctime>
#include <QIODevice>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <iterator>

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
    ListaVersamenti.push_back(t);
    std::cout << "LISTA VERSAMENTI: " << ListaVersamenti.size() << std::endl;
}

void ContoCorrente::annullaUltimoVersamento() {
    ListaVersamenti.back().annulla();
    ListaVersamenti.pop_back();
    std::cout << "LISTA VERSAMENTI: " << ListaVersamenti.size() << std::endl;
}

void ContoCorrente::aggiungiPrelievo(Prelievo& p) {
    ListaPrelievi.push_back(p);
    std::cout << "LISTA PRELIEVI: " << ListaPrelievi.size() << std::endl;
}

void ContoCorrente::annullaUltimoPrelievo() {
    ListaPrelievi.back().annulla();
    ListaPrelievi.pop_back();
    std::cout << "LISTA PRELIEVI: " << ListaPrelievi.size() << std::endl;
}

void ContoCorrente::aggiungiInvestimento(Investimento& i) {
    ListaInvestimenti.push_back(i);
    std::cout << "LISTA INVESTIMENTI: " << ListaInvestimenti.size() << std::endl;
}

void ContoCorrente::annullaUltimoInvestimento() {
    ListaInvestimenti.back().annulla();
    ListaInvestimenti.pop_back();
    std::cout << "LISTA INVESTIMENTI: " << ListaInvestimenti.size() << std::endl;
}

void ContoCorrente::aggiungiBonifico(Bonifico& b) {
    ListaBonifici.push_back(b);
    std::cout << "LISTA BONIFICI: " << ListaBonifici.size() << std::endl;
}

void ContoCorrente::annullaUltimoBonifico() {
    ListaBonifici.back().annulla();
    ListaBonifici.pop_back();
    std::cout << "LISTA BONIFICI: " << ListaBonifici.size() << std::endl;
}

