#include "pch.h"
#include "../Custom_List/custom_list.h"

TEST(CustomListTest, CreateList)
{
	custom_list::List<int> a;
}

TEST(CustomListTest, PushFront)
{
	custom_list::List<int> a;
	EXPECT_EQ(a.size(), 0);
	a.push_front(1);
	EXPECT_EQ(a.size(), 1);
}

TEST(CustomListTest, Indexator)
{
	custom_list::List<int> a;
	a.push_front(2);
	a.push_front(1);
	EXPECT_EQ(a[0], 1);
	EXPECT_EQ(a[1], 2);
	EXPECT_EQ(a[0], 1);
	EXPECT_THROW(a[2], std::out_of_range);
}

TEST(CustomListTest, Begin)
{
	custom_list::List<int> a;
	a.push_front(1);
	a.push_front(0);
	auto it = a.begin();
	EXPECT_EQ(*it, 0);
	++it;
	EXPECT_EQ(*it, 1);
	++it;
	EXPECT_EQ(it, nullptr);
}

TEST(CustomListTest, End)
{
	custom_list::List<int> a;
	a.push_front(0);
	EXPECT_EQ(a.end(), nullptr);
}
TEST(CustomListTest, For)
{
	custom_list::List<int> a;
	a.push_front(4);
	a.push_front(3);
	a.push_front(2);
	a.push_front(1);
	a.push_front(0);
	int i = 0;
	for (auto it = a.begin(); it != a.end(); ++it)
		EXPECT_EQ(*it, i++);
}