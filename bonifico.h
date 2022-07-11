#ifndef BONIFICO_H
#define BONIFICO_H
#include <string>
#include "contocorrente.h"

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

#endif // BONIFICO_H
