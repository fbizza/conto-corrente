#ifndef TRANSAZIONE_H
#define TRANSAZIONE_H
#include <string>
#include <QString>
class Transazione
{
public:
    Transazione(int importo = 0) : Importo(importo) {
        time_t now = time(0);
        std::string dt = ctime(&now);
        QString DataEOra = QString::fromStdString(dt);
        Data_E_Ora = DataEOra;
    };

    virtual void esegui() = 0;

    virtual void annulla() = 0;

    virtual ~Transazione() = 0;

protected:
    int Importo;
    QString Data_E_Ora;

};

#endif // TRANSAZIONE_H
