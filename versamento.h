#ifndef VERSAMENTO_H
#define VERSAMENTO_H
#include "transazione.h"
#include "contocorrente.h"

class ContoCorrente;

class Versamento : public Transazione {
public:  
    Versamento(ContoCorrente &cc, int importo = 0) : contoCorrente(cc), Importo(importo) {};

    void esegui() override;

    void annulla() override;

    Versamento& operator=(const Versamento& v) {
        return *this;
    }

private:
    int Importo;
    ContoCorrente &contoCorrente;
};

#endif // VERSAMENTO_H
