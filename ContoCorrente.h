#ifndef CONTO_CORRENTE_CONTOCORRENTE_H
#define CONTO_CORRENTE_CONTOCORRENTE_H
#include <string>

class ContoCorrente {
public:
    ContoCorrente(int saldo = 0, std::string iban = "IT3476849748575922774", std::string nome = "Francesco Bizzarri")
            : Saldo(saldo), IBAN(iban), Intestatario(nome) {};

    void preleva(int x);

    void versamentoBancomat(int x);

    void diminuisciSaldo(int x);

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

private:
    int Saldo;
    std::string Intestatario, IBAN;
};


#endif //CONTO_CORRENTE_CONTOCORRENTE_H
