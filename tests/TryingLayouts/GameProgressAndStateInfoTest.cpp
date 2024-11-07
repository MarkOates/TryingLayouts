
#include <gtest/gtest.h>

#include <TryingLayouts/GameProgressAndStateInfo.hpp>


TEST(TryingLayouts_GameProgressAndStateInfoTest, can_be_created_without_blowing_up)
{
   TryingLayouts::GameProgressAndStateInfo game_progress_and_state_info;
}


TEST(TryingLayouts_GameProgressAndStateInfoTest, TYPE__has_the_expected_value)
{
   EXPECT_STREQ(
     "TryingLayouts/GameProgressAndStateInfo",
     TryingLayouts::GameProgressAndStateInfo::TYPE
   );
}


TEST(TryingLayouts_GameProgressAndStateInfoTest, type__has_the_expected_value_matching_TYPE)
{
   TryingLayouts::GameProgressAndStateInfo game_progress_and_state_info;
   EXPECT_EQ(TryingLayouts::GameProgressAndStateInfo::TYPE, game_progress_and_state_info.get_type());
}


