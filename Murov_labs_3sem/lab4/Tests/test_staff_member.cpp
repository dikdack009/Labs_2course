#include "pch.h"
#include "../Task4Lib/task_4.h"

using namespace task_4;

TEST(StaffMemberTest, CreateEmty)
{
	StaffMember S = StaffMember();
	EXPECT_EQ(S.GetName(), std::string(""));
	EXPECT_EQ(S.GetRank(), Rank (0));
	EXPECT_EQ(S.GetUniformSize(), 0);
}

TEST(StaffMemberTest, Create)
{
	StaffMember S = StaffMember(std::string("aaa"), Rank (1), 54);
	EXPECT_EQ(S.GetName(), std::string("aaa"));
	EXPECT_EQ(S.GetRank(), Rank(1));
	EXPECT_EQ(S.GetUniformSize(), 54);
}

TEST(StaffMemberTest, StaffPosition)
{
	StaffMember S = StaffMember(std::string("aaa"), Rank(1), 54);
	S.SetStaffPosition("bbb");
	EXPECT_EQ(S.GetStaffPosition(), std::string("bbb"));
}

