#include <iostream>
#include "iostream"
#include "ContoCorrente.h"
#include "Bonifico.h"
#include "Investimento.h"

int main() {
    ContoCorrente cc;
    Versamento v(cc, 1000);
    Bonifico b(cc, 20);
    Prelievo p(cc, 10);
    Investimento i(cc, 40);
    Investimento i2(cc, -60);
    v.esegui();
    b.esegui();
    p.esegui();
    i.esegui();
    i2.esegui();
    cc.annullaUltimoBonifico();
    cc.annullaUltimoInvestimento();
    std::cout << cc.getSaldo() << std::endl;
    return 0;
}