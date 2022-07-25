
#ifndef CONTO_CORRENTE_BONIFICO_H
#define CONTO_CORRENTE_BONIFICO_H
#include <string>
#include "contocorrente.h"
#include "transazione.h"

class ContoCorrente;

class Bonifico : public Transazione {
public:
    Bonifico(ContoCorrente &cc, int importo = 0, std::string iban = "IT34768497485769201774") : Transazione(importo), contoCorrente(cc), IbanDestinatario(iban) {};

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
    ContoCorrente &contoCorrente;
    std::string IbanDestinatario;
};
#endif //CONTO_CORRENTE_BONIFICO_H
