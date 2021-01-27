#include "pch.h"
#include "../Task4Lib/task_4.h"

using namespace task_4;

TEST(CrewTest, Place)
{
	Crew squad = Crew();
	squad.SetPlace("aaa");
	EXPECT_EQ(squad.GetPlace(), std::string("aaa"));
}
