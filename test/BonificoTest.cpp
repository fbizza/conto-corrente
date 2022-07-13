#include "gtest/gtest.h"

#include "../Bonifico.h"

TEST(Bonifico, Costruttore) {
    ContoCorrente c;
    Bonifico b(c);
    ASSERT_EQ(0, b.getImporto());
    ASSERT_FALSE(b.isIstantaneo);
}

TEST(Bonifico, EseguiBonificoTest) {
    ContoCorrente c(1000);
    Bonifico b1(c, 100);
    Bonifico b2(c, 1100);
    b1.eseguiBonifico();
    ASSERT_EQ(900, c.getSaldo());
    ASSERT_ANY_THROW(b2.eseguiBonifico());
}



