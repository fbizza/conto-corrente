#ifndef CONTOCORRENTE_H
#define CONTOCORRENTE_H
#include <string>
#include <vector>
#include "transazione.h"
#include "versamento.h"
#include "prelievo.h"
#include "investimento.h"
#include "bonifico.h"

class Bonifico;
class Investimento;
class Versamento;
class Prelievo;

class ContoCorrente
{
public:
    ContoCorrente(int saldo = 0, std::string iban = "IT3476849748575922774", std::string nome = "Francesco Bizzarri")
            : Saldo(saldo), IBAN(iban), Intestatario(nome) {};

    void diminuisciSaldo(int x);

    void aumentaSaldo(int x);

    int getSaldo() const {
        return Saldo;
    }

    void setSaldo(int x) {
        ContoCorrente::Saldo = x;
    }

    std::string getIBAN() const {
        return IBAN;
    }

    std::string getIntestatario() const {
        return Intestatario;
    }

    void aggiungiVersamento(Versamento&);

    void annullaUltimoVersamento();

    void aggiungiPrelievo(Prelievo&);

    void annullaUltimoPrelievo();

    void aggiungiInvestimento(Investimento&);

    void annullaUltimoInvestimento();

    void aggiungiBonifico(Bonifico&);

    void annullaUltimoBonifico();

private:
    int Saldo;
    std::string Intestatario, IBAN;
    std::vector<Versamento> ListaVersamenti;
    std::vector<Prelievo> ListaPrelievi;
    std::vector<Investimento> ListaInvestimenti;
    std::vector<Bonifico> ListaBonifici;
};

#endif // CONTOCORRENTE_H
