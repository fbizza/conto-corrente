#include "ContoCorrente.h"
#include <fstream>
#include <ctime>

void ContoCorrente::preleva(int x) {
    if (Saldo - x > 0) {
        Saldo -= x;
    }
    else throw "Saldo contabile non sufficiente!";
    time_t now = time(0);
    std::string dt = ctime(&now);
    std::fstream file;
    file.open("ListaMovimenti.txt", std::ios::app);
    if (file.is_open()) {
        file << "\n" << dt << "Sono stati prelevati " << x << "€" << std::endl;
        file << "Nuovo saldo: " << Saldo << "€" << std::endl;
        file.close();
    }
}

void ContoCorrente::versamentoBancomat(int x) {
    Saldo += x;
    time_t now = time(0);
    std::string dt = ctime(&now);
    std::fstream file;
    file.open("ListaMovimenti.txt", std::ios::app);
    if (file.is_open()) {
        file << "\n" << dt << "Sono stati versati " << x << "€" << std::endl;
        file << "Nuovo saldo: " << Saldo << "€" << std::endl;
        file.close();
    }
}

void ContoCorrente::diminuisciSaldo(int x) {
    if (Saldo - x > 0) {
        Saldo -= x;
    }
    else throw "Saldo contabile non sufficiente!";
}

