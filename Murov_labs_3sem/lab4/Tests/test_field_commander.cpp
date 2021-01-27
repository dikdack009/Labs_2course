#include "pch.h"
#include "../Task4Lib/task_4.h"

using namespace task_4;

TEST(FieldCommanderTest, CreateEmpty)
{
	FieldCommander S = FieldCommander();
	EXPECT_EQ(S.GetName(), std::string(""));
	EXPECT_EQ(S.GetRank(), Rank(0));
	EXPECT_EQ(S.GetSpecialization(), Specialization::Infantry);
}

TEST(FieldCommanderTest, Create)
{
	FieldCommander S = FieldCommander(std::string("aaa"), Rank::Rank2, 54, Specialization::Sniper);
	EXPECT_EQ(S.GetName(), std::string("aaa"));
	EXPECT_EQ(S.GetRank(), Rank::Rank2);
	EXPECT_EQ(S.GetUniformSize(), 54);
	EXPECT_EQ(S.GetSpecialization(), Specialization::Sniper);
}

TEST(FieldCommanderTest, SetCrew)
{
	FieldCommander S = FieldCommander();
	Crew* c = new Crew();
	S.SetCrew(c);
	EXPECT_EQ(c->GetPlace(), S.GetCrew().GetPlace());
	delete c;
}

