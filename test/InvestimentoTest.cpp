#include "gtest/gtest.h"
#include "../Investimento.h"

TEST(Investimento, Costruttore) {
    ContoCorrente c(1000);
    Investimento i(c);
    i.esegui();
    ASSERT_EQ(0, i.getImporto());
    ASSERT_EQ(1000, c.getSaldo());
}

TEST(Investimento, CompraAzioniTest) {
    ContoCorrente c(1000);
    Investimento i1(c, 300);
    Investimento i2(c, 2000);
    int before = c.getListaInvestimenti().size();
    i1.esegui();
    ASSERT_EQ(c.getListaInvestimenti().size(), before + 1);
    ASSERT_EQ(700, c.getSaldo());
    EXPECT_THROW(i2.esegui(), std::logic_error);
}

TEST(Investimento, VendiAzioniTest) {
    ContoCorrente c(1000);
    Investimento i(c, -500);
    int before = c.getListaInvestimenti().size();
    i.esegui();
    ASSERT_EQ(1500, c.getSaldo());
    ASSERT_EQ(c.getListaInvestimenti().size(), before + 1);
}

TEST(Investimento, AnnullaInvestimentoTest) {
    ContoCorrente c(5000);
    Investimento i(c, 400);
    int before = c.getListaInvestimenti().size();
    i.esegui();
    ASSERT_EQ(4600, c.getSaldo());
    ASSERT_EQ(c.getListaInvestimenti().size(), before + 1);
    c.annullaUltimoInvestimento();
    ASSERT_TRUE(c.getListaInvestimenti().size() == before);
}
