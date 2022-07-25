#include "gtest/gtest.h"

#include "../Bonifico.h"

TEST(Bonifico, Costruttore) {
    ContoCorrente c(100);
    Bonifico b(c);
    ASSERT_EQ(0, b.getImporto());
}

TEST(Bonifico, EseguiBonificoTest) {
    ContoCorrente c(1000);
    Bonifico b1(c, 100);
    Bonifico b2(c, 1100);
    ASSERT_TRUE(c.getListaBonifici().empty());
    b1.esegui();
    ASSERT_EQ(900, c.getSaldo());
    EXPECT_THROW(b2.esegui(), std::logic_error);
    ASSERT_EQ(c.getListaBonifici().size(), 1);
}

TEST(Bonifico, AnnullaBonificoTest) {
    ContoCorrente c(2000);
    Bonifico b1(c, 20);
    Bonifico b2(c, 330);
    b1.esegui();
    b2.esegui();
    ASSERT_EQ(1650, c.getSaldo());
    ASSERT_TRUE(c.getListaBonifici().size() == 2);
    c.annullaUltimoBonifico();
    ASSERT_EQ(1980, c.getSaldo());
    c.annullaUltimoBonifico();
    ASSERT_TRUE(c.getListaBonifici().empty());
}



