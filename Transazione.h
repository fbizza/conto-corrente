#ifndef CONTO_CORRENTE_TRANSAZIONE_H
#define CONTO_CORRENTE_TRANSAZIONE_H

class Transazione
{
public:
    Transazione() {};

    virtual void esegui() = 0;

    virtual void annulla() = 0;

};

#endif //CONTO_CORRENTE_TRANSAZIONE_H
