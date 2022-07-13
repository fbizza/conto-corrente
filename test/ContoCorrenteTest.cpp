#include "gtest/gtest.h"

#include "../ContoCorrente.h"

TEST(ContoCorrente, CostruttoreSenzaParametri) {
    ContoCorrente c;
    ASSERT_EQ(0, c.getSaldo()); //Verifica che il costruttore, senza parametri, crea un conto corrente vuoto.
}

TEST(ContoCorrente, CostruttoreConParametri) {
    ContoCorrente c(10500, "IT23D00482891474902", "Mario Rossi");
    ASSERT_EQ(10500, c.getSaldo());
    ASSERT_EQ("IT23D00482891474902", c.getIBAN());
    ASSERT_EQ("Mario Rossi", c.getIntestatario());
}

TEST(ContoCorrente, TestPreleva) {
    ContoCorrente c(1000);
    c.preleva(900);
    ASSERT_EQ(100, c.getSaldo());
    ASSERT_ANY_THROW(c.preleva(5000)); //Lancia eccezione se prelevo più del saldo corrente
}

TEST(ContoCorrente, TestVersamentoBancomat) {
    ContoCorrente c;
    c.versamentoBancomat(750);
    ASSERT_EQ(750, c.getSaldo());
}
