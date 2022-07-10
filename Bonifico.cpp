#include "Bonifico.h"
#include <fstream>
#include <ctime>

void Bonifico::eseguiBonifico() {
    contoCorrente.diminuisciSaldo(Importo);
    time_t now = time(0);
    std::string dt = ctime(&now);
    std::fstream file;
    file.open("ListaMovimenti.txt", std::ios::app);
    if (file.is_open()) {
        file << "\n" << dt << "È stato inviato un bonifico da " << Importo << "€ a " << IbanDestinatario << std::endl;
        file << "Nuovo saldo: " << contoCorrente.getSaldo() << "€" << std::endl;
        file.close();
    }
}

