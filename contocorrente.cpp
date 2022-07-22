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
    std::cout << "LISTA VERSAMENTI: " << ListaVersamenti.size() << std::endl;
}

void ContoCorrente::annullaUltimoVersamento() {
    if (!ListaVersamenti.empty()) {
        ListaVersamenti.back().annulla();
        ListaVersamenti.pop_back();
        std::cout << "LISTA VERSAMENTI: " << ListaVersamenti.size() << std::endl;
    } else throw "Nessun versamento da annullare!";
}

void ContoCorrente::aggiungiPrelievo(Prelievo& p) {
    ListaPrelievi.push_back(p);
    std::cout << "LISTA PRELIEVI: " << ListaPrelievi.size() << std::endl;
}

void ContoCorrente::annullaUltimoPrelievo() {
    if (!ListaPrelievi.empty()) {
        ListaPrelievi.back().annulla();
        ListaPrelievi.pop_back();
        std::cout << "LISTA PRELIEVI: " << ListaPrelievi.size() << std::endl;
    } else throw "Nessun prelievo da annullare!";
}

void ContoCorrente::aggiungiInvestimento(Investimento& i) {
    ListaInvestimenti.push_back(i);
    std::cout << "LISTA INVESTIMENTI: " << ListaInvestimenti.size() << std::endl;
}

void ContoCorrente::annullaUltimoInvestimento() {
    if (!ListaInvestimenti.empty()) {
        ListaInvestimenti.back().annulla();
        ListaInvestimenti.pop_back();
        std::cout << "LISTA INVESTIMENTI: " << ListaInvestimenti.size() << std::endl;
    } else throw "Nessun investimento da annullare!";

}

void ContoCorrente::aggiungiBonifico(Bonifico& b) {
    ListaBonifici.push_back(b);
    std::cout << "LISTA BONIFICI: " << ListaBonifici.size() << std::endl;
}

void ContoCorrente::annullaUltimoBonifico() {
    if (!ListaBonifici.empty()) {
        ListaBonifici.back().annulla();
        ListaBonifici.pop_back();
        std::cout << "LISTA BONIFICI: " << ListaBonifici.size() << std::endl;
    } else throw "Nessun bonifico da annullare!";

}

void ContoCorrente::annullaVersamento(int i) {
    ListaVersamenti.at(i).annulla();
    ListaVersamenti.erase((ListaVersamenti.begin() + i));
}

void ContoCorrente::annullaPrelievo(int i) {
    ListaPrelievi.at(i).annulla();
    ListaPrelievi.erase((ListaPrelievi.begin() + i));
}

void ContoCorrente::annullaBonifico(int i) {
    ListaBonifici.at(i).annulla();
    ListaBonifici.erase((ListaBonifici.begin() + i));
}

void ContoCorrente::annullaInvestimento(int i) {
    ListaInvestimenti.at(i).annulla();
    ListaInvestimenti.erase((ListaInvestimenti.begin() + i));
}
