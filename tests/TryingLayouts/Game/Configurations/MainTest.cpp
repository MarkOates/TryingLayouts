
#include <gtest/gtest.h>

#include <TryingLayouts/Game/Configurations/Main.hpp>


TEST(TryingLayouts_Game_Configurations_MainTest, can_be_created_without_blowing_up)
{
   TryingLayouts::Game::Configurations::Main main_configuration;
}


TEST(TryingLayouts_Game_Configurations_MainTest, load_level_by_identifier__will_not_blow_up)
{
   TryingLayouts::Game::Configurations::Main main_configuration;
   AllegroFlare::Levels::Base* level = main_configuration.load_level_by_identifier("forest_village_1");
   EXPECT_NE(nullptr, level);
}


