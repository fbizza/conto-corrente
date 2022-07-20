#include "gtest/gtest.h"
#include "../Prelievo.h"

TEST(Prelievo, EseguiPrelievoTest) {
    ContoCorrente c(1000);
    Prelievo p1(c, 200);
    ASSERT_TRUE(c.getListaPrelievi().empty());
    p1.esegui();
    ASSERT_EQ(1, c.getListaPrelievi().size());
    ASSERT_EQ(800, c.getSaldo());
    Prelievo p2(c, 10000);
    EXPECT_THROW(p2.esegui(), const char*);    // UN PRELIEVO CHE SFORA IL SALDO NON DEVE ESSERE ESEGUITO
    ASSERT_EQ(1, c.getListaPrelievi().size()); // E NON DEVE ESSERE AGGIUNTO ALLO STORICO
}

TEST(Prelievo, AnnullaPrelievoTest) {
    ContoCorrente c(5000);
    Prelievo p1(c, 950);
    int before = c.getSaldo();
    p1.esegui();
    ASSERT_FALSE(before == c.getSaldo());
    c.annullaUltimoPrelievo();
    ASSERT_TRUE(c.getListaPrelievi().empty());
    ASSERT_TRUE(before == c.getSaldo());
}



