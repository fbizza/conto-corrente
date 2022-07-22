#ifndef TRANSAZIONE_H
#define TRANSAZIONE_H

class Transazione
{
public:
    Transazione() {};

    virtual void esegui() = 0;

    virtual void annulla() = 0;

};

#endif // TRANSAZIONE_H
