#include "gtest/gtest.h"
#include "../Versamento.h"

TEST(Versamento, EseguiVersamentoTest) {
    ContoCorrente c(2000);
    Versamento v(c, 200);
    ASSERT_TRUE(c.getListaVersamenti().empty());
    v.esegui();
    ASSERT_EQ(1, c.getListaVersamenti().size());
    ASSERT_EQ(2200, c.getSaldo());
}

TEST(Versamento, AnnullaVersamentoTest) {
    ContoCorrente c(5000);
    Versamento v(c, 950);
    int before = c.getSaldo();
    v.esegui();
    ASSERT_FALSE(before == c.getSaldo());
    c.annullaUltimoVersamento();
    ASSERT_TRUE(c.getListaPrelievi().empty());
    ASSERT_TRUE(before == c.getSaldo());
}

