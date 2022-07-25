#ifndef INVESTIMENTO_H
#define INVESTIMENTO_H
#include <string>
#include "contocorrente.h"
#include "transazione.h"

class ContoCorrente;

class Investimento : public Transazione {
public:

    Investimento(ContoCorrente &cc, int importo = 0, std::string azione = "MSFT") : Transazione(importo), contoCorrente(cc), CodiceAzione(azione) {};

    void esegui() override;

    void annulla() override;

    void compraAzioni();

    void vendiAzioni();

    int getImporto() const {
        return Importo;
    }

    std::string getCodiceAzione() const {
        return CodiceAzione;
    }

    Investimento& operator=(const Investimento& v) {
        return *this;
    }

private:
    ContoCorrente &contoCorrente;
    std::string CodiceAzione;
};
#endif // INVESTIMENTO_H
