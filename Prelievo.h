#ifndef CONTO_CORRENTE_PRELIEVO_H
#define CONTO_CORRENTE_PRELIEVO_H
#include "transazione.h"
#include "contocorrente.h"

class ContoCorrente;

class Prelievo : public Transazione {
public:
    Prelievo(ContoCorrente &cc, int importo = 0) : Transazione(importo), contoCorrente(cc) {};

    void esegui() override;

    void annulla() override;

    Prelievo& operator=(const Prelievo& v) {
        return *this;
    }

private:
    ContoCorrente &contoCorrente;
};

#endif //CONTO_CORRENTE_PRELIEVO_H