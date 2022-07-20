
#ifndef CONTO_CORRENTE_VERSAMENTO_H
#define CONTO_CORRENTE_VERSAMENTO_H

#include "transazione.h"
#include "contocorrente.h"
class ContoCorrente;

class Versamento : public Transazione {
public:
    Versamento(ContoCorrente &cc, int importo = 0) : contoCorrente(cc), Importo(importo) {};

    void esegui() override;

    void annulla() override;

private:
    int Importo;
    ContoCorrente &contoCorrente;
};

#endif //CONTO_CORRENTE_VERSAMENTO_H
