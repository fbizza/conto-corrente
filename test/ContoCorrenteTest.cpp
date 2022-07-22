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

TEST(ContoCorrente, Annulla_i_esimo_VersamentoTest) {
    ContoCorrente c(100);
    Versamento v1(c, 20);
    Versamento v2(c, 30);
    Versamento v3(c, 50);
    v1.esegui();
    v2.esegui();
    v3.esegui();
    ASSERT_TRUE(c.getListaVersamenti().size() == 3);
    c.annullaVersamento(1);
    EXPECT_THROW(c.annullaVersamento(3), std::out_of_range);
    ASSERT_EQ(c.getSaldo(), 170);
    ASSERT_TRUE(c.getListaVersamenti().size() == 2);
}

TEST(ContoCorrente, Annulla_i_esimo_BonificoTest) {
    ContoCorrente c(5000);
    Bonifico b1(c, 1000);
    Bonifico b2(c, 500);
    Bonifico b3(c, 200);
    Bonifico b4(c, 300);
    b1.esegui();
    b2.esegui();
    b3.esegui();
    b4.esegui();
    ASSERT_TRUE(c.getListaBonifici().size() == 4);
    c.annullaBonifico(3);
    EXPECT_THROW(c.annullaVersamento(4), std::out_of_range);
    ASSERT_EQ(c.getSaldo(), 3300);
    ASSERT_TRUE(c.getListaBonifici().size() == 3);
}

TEST(ContoCorrente, Annulla_i_esimo_InvestimentoTest) {
    ContoCorrente c(10000);
    Investimento i1(c, 2000);
    Investimento i2(c, -3000);
    i1.esegui();
    i2.esegui();
    ASSERT_TRUE(c.getListaInvestimenti().size() == 2);
    c.annullaInvestimento(0);
    EXPECT_THROW(c.annullaVersamento(3), std::out_of_range);
    ASSERT_EQ(c.getSaldo(), 13000);
    ASSERT_TRUE(c.getListaInvestimenti().size() == 1);
}
