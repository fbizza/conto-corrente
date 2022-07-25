#ifndef CONTO_CORRENTE_TRANSAZIONE_H
#define CONTO_CORRENTE_TRANSAZIONE_H
class Transazione
{
public:
    Transazione(int importo = 0) : Importo(importo) {};

    virtual void esegui() = 0;

    virtual void annulla() = 0;

    virtual ~Transazione() = 0;

protected:
    int Importo;
};

#endif //CONTO_CORRENTE_TRANSAZIONE_H
