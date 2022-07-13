#include "gtest/gtest.h"
#include "../Investimento.h"

TEST(Investimento, Costruttore) {
    ContoCorrente c(1000);
    Investimento i(c);
    ASSERT_EQ(0, i.getImporto());
}

TEST(Investimento, CompraAzioniTest) {
    ContoCorrente c(1000);
    Investimento i1(c, 300);
    Investimento i2(c, 2000);
    i1.compraAzioni();
    ASSERT_EQ(700, c.getSaldo());
    ASSERT_ANY_THROW(i2.compraAzioni());
}

TEST(Investimento, VendiAzioniTest) {
    ContoCorrente c(1000);
    Investimento i(c, 500);
    i.vendiAzioni();
    ASSERT_EQ(1500, c.getSaldo());
}
