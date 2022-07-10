
#ifndef CONTO_CORRENTE_BONIFICO_H
#define CONTO_CORRENTE_BONIFICO_H

#include <string>
#include "ContoCorrente.h"

class Bonifico {
public:
    Bonifico(ContoCorrente &cc, int importo = 0, std::string iban = "IT34768497485769201774") : contoCorrente(cc), Importo(importo), IbanDestinatario(iban) {};

    void eseguiBonifico();

    int getImporto() const {
        return Importo;
    }

    std::string getIbanDestinatario() const {
        return IbanDestinatario;
    }


private:
    int Importo;
    ContoCorrente &contoCorrente;
    std::string IbanDestinatario;
};

#endif //CONTO_CORRENTE_BONIFICO_H
