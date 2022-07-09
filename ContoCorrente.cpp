#include "ContoCorrente.h"


void ContoCorrente::preleva(int x) {
    Saldo -= x;
}

void ContoCorrente::versa(int x) {
    Saldo += x;
}

