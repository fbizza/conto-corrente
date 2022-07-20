#include "gtest/gtest.h"

#include "../ContoCorrente.h"

TEST(ContoCorrente, Costruttore) {
    ContoCorrente c;
    ASSERT_EQ(c.getSaldo(), 0);
    ASSERT_TRUE(c.getListaPrelievi().empty());
    ASSERT_TRUE(c.getListaVersamenti().empty());
    ASSERT_TRUE(c.getListaBonifici().empty());
    ASSERT_TRUE(c.getListaInvestimenti().empty());
}

TEST(ContoCorrente, DiminuisciSaldoTest) {
    ContoCorrente c(2000);
    c.diminuisciSaldo(500);
    ASSERT_EQ(1500, c.getSaldo());
    EXPECT_THROW(c.diminuisciSaldo(30000), const char*);
}

TEST(ContoCorrente, AumentaSaldoTest) {
    ContoCorrente c(20);
    c.aumentaSaldo(85);
    ASSERT_EQ(105, c.getSaldo());
}

TEST(ContoCorrente, Aggiungi_Rimuovi_InvestimentoTest) {
    ContoCorrente c(10000);
    Investimento i(c, 300, "MSFT");
    ASSERT_TRUE(c.getListaInvestimenti().empty());
    i.esegui();
    ASSERT_EQ(c.getListaInvestimenti().size(), 1);
    ASSERT_EQ(c.getSaldo(), 9700);
    c.annullaUltimoInvestimento();
    ASSERT_TRUE(c.getListaInvestimenti().empty());
    ASSERT_EQ(c.getSaldo(), 10000);
    EXPECT_THROW(c.annullaUltimoInvestimento(), const char*);
}

TEST(ContoCorrente, Aggiungi_Rimuovi_BonificoTest) {
    ContoCorrente c(10);
    Bonifico b(c, 2, "IT34781782974802352");
    ASSERT_TRUE(c.getListaBonifici().empty());
    b.esegui();
    ASSERT_EQ(c.getListaBonifici().size(), 1);
    ASSERT_EQ(c.getSaldo(), 8);
    c.annullaUltimoBonifico();
    ASSERT_TRUE(c.getListaBonifici().empty());
    ASSERT_EQ(c.getSaldo(), 10);
    EXPECT_THROW(c.annullaUltimoBonifico(), const char*);
}

TEST(ContoCorrente, Aggiungi_Rimuovi_VersamentoTest) {
    ContoCorrente c(500);
    Versamento v(c, 200);
    ASSERT_TRUE(c.getListaVersamenti().empty());
    v.esegui();
    ASSERT_EQ(c.getListaVersamenti().size(), 1);
    ASSERT_EQ(c.getSaldo(), 700);
    c.annullaUltimoVersamento();
    ASSERT_TRUE(c.getListaBonifici().empty());
    ASSERT_EQ(c.getSaldo(), 500);
    EXPECT_THROW(c.annullaUltimoVersamento(), const char*);
}

TEST(ContoCorrente, Aggiungi_Rimuovi_PrelievoTest) {
    ContoCorrente c(90);
    Prelievo p(c, 20);
    ASSERT_TRUE(c.getListaPrelievi().empty());
    p.esegui();
    ASSERT_EQ(c.getListaPrelievi().size(), 1);
    ASSERT_EQ(c.getSaldo(), 70);
    c.annullaUltimoPrelievo();
    ASSERT_TRUE(c.getListaPrelievi().empty());
    ASSERT_EQ(c.getSaldo(), 90);
    EXPECT_THROW(c.annullaUltimoPrelievo(), const char*);
}


