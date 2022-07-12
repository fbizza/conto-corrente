#include <iostream>

#include "ContoCorrente.h"
#include "Bonifico.h"
#include "Investimento.h"

int main() {
    try {
        ContoCorrente c;
        c.versamentoBancomat(200);
        c.preleva(100);
        Bonifico b(c, 30);
        b.eseguiBonifico();
        std::cout << c.getSaldo() << std::endl;
        c.preleva(30);
        Investimento i(c, 5);
        i.compraAzioni();
        Investimento ii(c, 500);
        ii.vendiAzioni();
        std::cout << c.getSaldo() << std::endl;

    } catch (const char* messaggio) {
        std::cout << messaggio << std::endl;
    }


    return 0;
}