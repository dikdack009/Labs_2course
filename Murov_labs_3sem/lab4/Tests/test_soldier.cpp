#include "pch.h"
#include "../Task4Lib/task_4.h"

using namespace task_4;

TEST(SoldierTest, CreateSoldierEmty)
{
	Soldier S = Soldier();
	EXPECT_EQ(S.GetSpecialization(), Specialization::Infantry);
}

TEST(SoldierTest, CreateSoldier)
{
	Soldier S = Soldier(std::string ("aaa"), Rank (1), 54, Specialization::Sniper);
	EXPECT_EQ(S.GetSpecialization(), Specialization::Sniper);
	EXPECT_EQ(S.GetName(), std::string("aaa"));
	EXPECT_EQ(S.GetRank(), Rank (1));
	EXPECT_EQ(S.GetUniformSize(), 54);
}