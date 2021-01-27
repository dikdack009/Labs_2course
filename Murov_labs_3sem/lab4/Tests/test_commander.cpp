#include "pch.h"
#include "../Task4Lib/task_4.h"

using namespace task_4;

TEST(CommanderTest, CreateEmpty)
{
	Commander S = Commander();
	EXPECT_EQ(S.GetName(), std::string(""));
	EXPECT_EQ(S.GetRank(), Rank::Rank1);
	EXPECT_EQ(S.GetUniformSize(), 0);
}

TEST(CommanderTest, Create)
{
	Commander S = Commander(std::string ("aaa"), Rank::Rank2, 54);
	EXPECT_EQ(S.GetName(), std::string("aaa"));
	EXPECT_EQ(S.GetRank(), Rank::Rank2);
	EXPECT_EQ(S.GetUniformSize(), 54);
}