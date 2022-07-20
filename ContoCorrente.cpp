#include "contocorrente.h"
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
    ListaVersamenti.push_back(t);
}

void ContoCorrente::annullaUltimoVersamento() {
    if (!ListaVersamenti.empty()) {
        ListaVersamenti.back().annulla();
        ListaVersamenti.pop_back();
    } else throw "Nessun versamento da annullare!";
}

void ContoCorrente::aggiungiPrelievo(Prelievo& p) {
    ListaPrelievi.push_back(p);
}

void ContoCorrente::annullaUltimoPrelievo() {
    if (!ListaPrelievi.empty()) {
        ListaPrelievi.back().annulla();
        ListaPrelievi.pop_back();
    } else throw "Nessun prelievo da annullare!";
}

void ContoCorrente::aggiungiInvestimento(Investimento& i) {
    ListaInvestimenti.push_back(i);
}

void ContoCorrente::annullaUltimoInvestimento() {
    if (!ListaInvestimenti.empty()) {
        ListaInvestimenti.back().annulla();
        ListaInvestimenti.pop_back();
    } else throw "Nessun investimento da annullare!";

}

void ContoCorrente::aggiungiBonifico(Bonifico& b) {
    ListaBonifici.push_back(b);
}

void ContoCorrente::annullaUltimoBonifico() {
    if (!ListaBonifici.empty()) {
        ListaBonifici.back().annulla();
        ListaBonifici.pop_back();
    } else throw "Nessun bonifico da annullare!";

}



