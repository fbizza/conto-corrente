#ifndef BONIFICO_H
#define BONIFICO_H
#include <string>
#include "contocorrente.h"
#include "transazione.h"

class ContoCorrente;

class Bonifico : public Transazione {
public:
    Bonifico(ContoCorrente &cc, int importo = 0, std::string iban = "IT34768497485769201774") : contoCorrente(cc), Importo(importo), IbanDestinatario(iban) {};

    void esegui() override;

    void annulla() override;

    int getImporto() const {
        return Importo;
    }

    std::string getIbanDestinatario() const {
        return IbanDestinatario;
    }

    Bonifico& operator=(const Bonifico& v) {
            return *this;
    }


private:
    int Importo;
    ContoCorrente &contoCorrente;
    std::string IbanDestinatario;
};

#endif // BONIFICO_H
