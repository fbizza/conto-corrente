#ifndef PRELIEVO_H
#define PRELIEVO_H
#include "transazione.h"
#include "contocorrente.h"

class ContoCorrente;

class Prelievo : public Transazione {
public:
    Prelievo(ContoCorrente &cc, int importo = 0) : contoCorrente(cc), Importo(importo) {};

    void esegui() override;

    void annulla() override;

    Prelievo& operator=(const Prelievo& v) {
            return *this;
        }

private:
    int Importo;
    ContoCorrente &contoCorrente;
};

#endif // PRELIEVO_H
