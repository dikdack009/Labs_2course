#include "pch.h"
#include "../lab2/Chain_line.h"
#include <tchar.h>
#include "../lab2/Chain_line.cpp"

// тестирование конструкторов
TEST(ChainConstructor, DefaultConstructor)
{
	Chain::Chain a;
	ASSERT_EQ(1, a.get_a());
}

TEST(ChainConstructor, TestException)
{
	ASSERT_ANY_THROW(Chain::Chain(0));
}

// тестирование других методов
TEST(ChainMethods, Setters)
{
	Chain::Chain r;
	r.set_a(1.5);
	ASSERT_EQ(1.5, r.get_a());
	r.set_a(-2.3);
	ASSERT_EQ(-2.3, r.get_a());
	ASSERT_ANY_THROW(r.set_a(0));
}

TEST(ChainMethods, Parameters)
{
	Chain::Chain q;
	const double PI = 3.62686, err = 0.00001;
	ASSERT_NEAR(PI, q.area(0,2), err);
	ASSERT_NEAR(PI, q.perimetr(0,2), err);
	ASSERT_NEAR(sinh(2) - sinh(0), q.area(0, 2), err);
	ASSERT_NEAR(sinh(2) - sinh(0), q.perimetr(0, 2), err);
	ASSERT_NEAR(0, q.area(3, 3), err);
	ASSERT_NEAR(0, q.perimetr(3, 3), err);
	ASSERT_EQ(1, q.radius(0));
	ASSERT_EQ(0, q.center(0).x);
	ASSERT_EQ(2, q.center(0).y);
	ASSERT_EQ(1, q.f(0));

	Chain::Chain p(3);
	ASSERT_NEAR(6.45443, p.area(0, 2), err);
	ASSERT_NEAR(2.15148, p.perimetr(0, 2), err);
	double a = 22.55047, b = -15.997, c = 16.4501;
	ASSERT_NEAR(a, p.radius(5), 0.0001);
	ASSERT_NEAR(b, p.center(5).x, 0.0001);
	ASSERT_NEAR(c, p.center(5).y, 0.0001);
	ASSERT_EQ(3, p .f(0));

}
int _tmain(int argc, _TCHAR* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}