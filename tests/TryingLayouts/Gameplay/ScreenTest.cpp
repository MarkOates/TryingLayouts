
#include <gtest/gtest.h>

#include <TryingLayouts/Gameplay/Screen.hpp>

#include <AllegroFlare/Testing/WithAllegroRenderingFixture.hpp>
#include <AllegroFlare/Testing/WithAllegroFlareFrameworksFullFixture.hpp>
//#include <AllegroFlare/Frameworks/Full.hpp>


// NOTE: Fully commented out
// NOTE: Fully commented out
// NOTE: Fully commented out
// NOTE: Fully commented out
// NOTE: Fully commented out

/*
class TestGameConfiguration : public TryingLayouts::Game:Configurations::Main
{
public:
   // TODO: Upgrade this out of void* to a level base class (once the upstream design is clear)
   virtual AllegroFlare::Levels::Base *load_level_by_identifier(std::string identifier) override
   {
      // NOTE: Not used in this test
      //RPG::Gameplay::Level *result = new RPG::Gameplay::Level();
      //if (identifier == "test_level")
      //{
         //result->set_background_image_identifier("maps/rpg-fit-backgrounds-x2-01.png");
      //}
      //return result;
      return nullptr;
   }
};
*/


class TryingLayouts_Gameplay_ScreenTest : public ::testing::Test {};
class TryingLayouts_Gameplay_ScreenTestWithAllegroRenderingFixture
   : public AllegroFlare::Testing::WithAllegroRenderingFixture
{};
class TryingLayouts_Gameplay_ScreenTestWithAllegroFrameworksFullFixture
   : public AllegroFlare::Testing::WithAllegroFlareFrameworksFullFixture
{};


/*

TEST_F(TryingLayouts_Gameplay_ScreenTest, can_be_created_without_blowing_up)
{
   TryingLayouts::Gameplay::Screen screen;
}


TEST_F(TryingLayouts_Gameplay_ScreenTest, TYPE__has_the_expected_value)
{
   TryingLayouts::Gameplay::Screen screen;
   EXPECT_EQ("TryingLayouts/Gameplay/Screen", screen.get_type());
}


TEST_F(TryingLayouts_Gameplay_ScreenTest, type__has_the_expected_value_matching_TYPE)
{
   TryingLayouts::Gameplay::Screen screen;
   EXPECT_EQ(TryingLayouts::Gameplay::Screen::TYPE, screen.get_type());
}


*/

TEST_F(TryingLayouts_Gameplay_ScreenTestWithAllegroFrameworksFullFixture,
   CAPTURE__TIMED_INTERACTIVE__will_run_as_expected)
{
   TryingLayouts::Gameplay::Screen screen;
   screen.set_event_emitter(get_framework_event_emitter());
   screen.set_bitmap_bin(get_framework_bitmap_bin());
   screen.set_font_bin(get_framework_font_bin());
   screen.set_model_bin(get_framework_model_bin());
   screen.set_data_folder_path(get_framework_data_folder_path());
   screen.initialize();

   framework_register_and_activate_screen("screen", &screen);

   framework_run_loop(3);
}



/*

   void move_cursor_up(AllegroFlare::Layouts::Layout &cursor_map)
   {
      int next_id = current_cursor_destination->move_up_to_target_tmj_object_id;
      move_cursor_to(cursor_map, next_id);
   }

   void move_cursor_down(AllegroFlare::Layouts::Layout &cursor_map)
   {
      int next_id = current_cursor_destination->move_down_to_target_tmj_object_id;
      move_cursor_to(cursor_map, next_id);
   }

   void move_cursor_left(AllegroFlare::Layouts::Layout &cursor_map)
   {
      int next_id = current_cursor_destination->move_left_to_target_tmj_object_id;
      move_cursor_to(cursor_map, next_id);
   }

   void move_cursor_right(AllegroFlare::Layouts::Layout &cursor_map)
   {
      int next_id = current_cursor_destination->move_right_to_target_tmj_object_id;
      move_cursor_to(cursor_map, next_id);
   }

   void activate_current_cursor_selection()
   {
      // TODO: Assert current_cursor_destination
      if (current_cursor_destination->on_activation) current_cursor_destination->on_activation();

      // TODO: Possibly some custom behavior would be here if it fit the design
   }

   void set_selection_cursor_box_to_new_position()
   {
      selection_cursor_box.reposition_to(
         current_cursor_destination->x,
         current_cursor_destination->y
      );
      selection_cursor_box.resize_to(
         current_cursor_destination->width,
         current_cursor_destination->height
      );
   }

*/

