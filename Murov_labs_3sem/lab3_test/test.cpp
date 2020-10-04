#include "pch.h"
#include "../lab3_3/big.h"
#include "../lab3_3/big.cpp"

using namespace Prog3_1;

TEST(Constructors, defaultconstructor) {
    Big_Dec* A = new Big_Dec;

    ASSERT_EQ(0, (int)*A);
    delete A;
}
TEST(Constructors, string_constructor) {
    char c[] = "0000";
    Big_Dec* A = new Big_Dec(c);
    ASSERT_EQ(0, (int)*A);
    delete A;
    char b[] = "-0002";
    ASSERT_ANY_THROW(new Big_Dec(b));
    char q[] = "-2y";
    ASSERT_ANY_THROW(new Big_Dec(q));
    ASSERT_ANY_THROW(new Big_Dec(nullptr));
}
TEST(Constructors, int_constructor) {
    Big_Dec* A = new Big_Dec(-0);
    ASSERT_EQ(0, (int)*A);
    delete A;
    A = new Big_Dec(111);
    ASSERT_EQ(111, (int)*A);
    delete A;
    A = new Big_Dec(-111);
    ASSERT_EQ(-111, (int)*A);
    delete A;
    A = new Big_Dec(-1);
    ASSERT_EQ(-1, (int)*A);
}
TEST(operators, operator_inverce) {
    Big_Dec* A = new Big_Dec(0);
    *A = ~*A;
    ASSERT_EQ(0, (int)*A);
    delete A;
    A = new Big_Dec(11);
    ASSERT_EQ(11, (int)(~*A));
    delete A;
    A = new Big_Dec(-1);
    ASSERT_EQ(-9, (int)~*A);
    delete A;
}
TEST(operators, operator_unminus) {
    Big_Dec* A = new Big_Dec(0);
    *A = -*A;
    ASSERT_EQ(0, (int)*A);
    delete A;
    A = new Big_Dec(11);
    ASSERT_EQ(-11, (int)(-*A));
    delete A;
    A = new Big_Dec(-1);
    ASSERT_EQ(1, (int)-*A);
    delete A;
}
TEST(operators, operator_sum) {
    Big_Dec* A = new Big_Dec(0);
    ASSERT_EQ(-1, (int)(*A - 1));
    ASSERT_EQ(-1, (int)(*A + (-1)));
    *A += -2;
    ASSERT_EQ(-2, (int)(*A));
    ASSERT_EQ(198, (int)(*A + 200));
    ASSERT_EQ(0, (int)(*A + 2));
    ASSERT_EQ(-4, (int)(*A - 2));
    ASSERT_EQ(-2, (int)(*A + 0));
}
TEST(operators, operator_devmult) {
    Big_Dec* A = new Big_Dec(322);
    ASSERT_EQ(32, (int)((*A).div()));
    *A = (*A).div();
    ASSERT_EQ(320, (int)((*A).mult()));
    *A += -24;
    ASSERT_EQ(0, (int)((*A).div()));
    *A = 0;
    ASSERT_EQ(0, (int)((*A).mult()));
    *A = -1;
    ASSERT_EQ(0, (int)((*A).div()));
    ASSERT_EQ(-10, (int)((*A).mult()));
}
int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}