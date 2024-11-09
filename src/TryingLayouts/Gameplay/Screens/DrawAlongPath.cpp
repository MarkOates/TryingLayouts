

#include <TryingLayouts/Gameplay/Screens/DrawAlongPath.hpp>

#include <AllegroFlare/Routers/Standard.hpp>
#include <AllegroFlare/VirtualControllers/GenericController.hpp>
#include <TryingLayouts/Gameplay/Level.hpp>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <sstream>
#include <stdexcept>


namespace TryingLayouts
{
namespace Gameplay
{
namespace Screens
{


DrawAlongPath::DrawAlongPath()
   : AllegroFlare::Screens::Gameplay()
   , data_folder_path(DEFAULT_DATA_FOLDER_PATH)
   , asset_studio_database(nullptr)
   , event_emitter(nullptr)
   , bitmap_bin(nullptr)
   , font_bin(nullptr)
   , model_bin(nullptr)
   , layout_camera_2d({})
   , layout({})
   , layout_cursor_selection_box({})
   , current_cursor_destination(nullptr)
   , current_level_identifier("[unset-current_level]")
   , current_level(nullptr)
   , puzzle__numbers_pressed("")
   , initialized(false)
{
}


DrawAlongPath::~DrawAlongPath()
{
}


void DrawAlongPath::set_data_folder_path(std::string data_folder_path)
{
   if (get_initialized()) throw std::runtime_error("[DrawAlongPath::set_data_folder_path]: error: guard \"get_initialized()\" not met.");
   this->data_folder_path = data_folder_path;
}


void DrawAlongPath::set_asset_studio_database(AllegroFlare::AssetStudio::Database* asset_studio_database)
{
   if (get_initialized()) throw std::runtime_error("[DrawAlongPath::set_asset_studio_database]: error: guard \"get_initialized()\" not met.");
   this->asset_studio_database = asset_studio_database;
}


void DrawAlongPath::set_event_emitter(AllegroFlare::EventEmitter* event_emitter)
{
   if (get_initialized()) throw std::runtime_error("[DrawAlongPath::set_event_emitter]: error: guard \"get_initialized()\" not met.");
   this->event_emitter = event_emitter;
}


void DrawAlongPath::set_bitmap_bin(AllegroFlare::BitmapBin* bitmap_bin)
{
   if (get_initialized()) throw std::runtime_error("[DrawAlongPath::set_bitmap_bin]: error: guard \"get_initialized()\" not met.");
   this->bitmap_bin = bitmap_bin;
}


void DrawAlongPath::set_font_bin(AllegroFlare::FontBin* font_bin)
{
   if (get_initialized()) throw std::runtime_error("[DrawAlongPath::set_font_bin]: error: guard \"get_initialized()\" not met.");
   this->font_bin = font_bin;
}


void DrawAlongPath::set_model_bin(AllegroFlare::ModelBin* model_bin)
{
   if (get_initialized()) throw std::runtime_error("[DrawAlongPath::set_model_bin]: error: guard \"get_initialized()\" not met.");
   this->model_bin = model_bin;
}


std::string DrawAlongPath::get_data_folder_path() const
{
   return data_folder_path;
}


AllegroFlare::EventEmitter* DrawAlongPath::get_event_emitter() const
{
   return event_emitter;
}


bool DrawAlongPath::get_initialized() const
{
   return initialized;
}


AllegroFlare::AssetStudio::Database* &DrawAlongPath::get_asset_studio_database_ref()
{
   return asset_studio_database;
}


void DrawAlongPath::initialize()
{
   if (!((!initialized)))
   {
      std::stringstream error_message;
      error_message << "[TryingLayouts::Gameplay::Screens::DrawAlongPath::initialize]: error: guard \"(!initialized)\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[TryingLayouts::Gameplay::Screens::DrawAlongPath::initialize]: error: guard \"(!initialized)\" not met");
   }
   if (!(al_is_system_installed()))
   {
      std::stringstream error_message;
      error_message << "[TryingLayouts::Gameplay::Screens::DrawAlongPath::initialize]: error: guard \"al_is_system_installed()\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[TryingLayouts::Gameplay::Screens::DrawAlongPath::initialize]: error: guard \"al_is_system_installed()\" not met");
   }
   if (!(al_is_primitives_addon_initialized()))
   {
      std::stringstream error_message;
      error_message << "[TryingLayouts::Gameplay::Screens::DrawAlongPath::initialize]: error: guard \"al_is_primitives_addon_initialized()\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[TryingLayouts::Gameplay::Screens::DrawAlongPath::initialize]: error: guard \"al_is_primitives_addon_initialized()\" not met");
   }
   if (!(al_is_font_addon_initialized()))
   {
      std::stringstream error_message;
      error_message << "[TryingLayouts::Gameplay::Screens::DrawAlongPath::initialize]: error: guard \"al_is_font_addon_initialized()\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[TryingLayouts::Gameplay::Screens::DrawAlongPath::initialize]: error: guard \"al_is_font_addon_initialized()\" not met");
   }
   if (!(event_emitter))
   {
      std::stringstream error_message;
      error_message << "[TryingLayouts::Gameplay::Screens::DrawAlongPath::initialize]: error: guard \"event_emitter\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[TryingLayouts::Gameplay::Screens::DrawAlongPath::initialize]: error: guard \"event_emitter\" not met");
   }
   if (!(bitmap_bin))
   {
      std::stringstream error_message;
      error_message << "[TryingLayouts::Gameplay::Screens::DrawAlongPath::initialize]: error: guard \"bitmap_bin\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[TryingLayouts::Gameplay::Screens::DrawAlongPath::initialize]: error: guard \"bitmap_bin\" not met");
   }
   if (!(font_bin))
   {
      std::stringstream error_message;
      error_message << "[TryingLayouts::Gameplay::Screens::DrawAlongPath::initialize]: error: guard \"font_bin\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[TryingLayouts::Gameplay::Screens::DrawAlongPath::initialize]: error: guard \"font_bin\" not met");
   }
   if (!(model_bin))
   {
      std::stringstream error_message;
      error_message << "[TryingLayouts::Gameplay::Screens::DrawAlongPath::initialize]: error: guard \"model_bin\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[TryingLayouts::Gameplay::Screens::DrawAlongPath::initialize]: error: guard \"model_bin\" not met");
   }
   set_update_strategy(AllegroFlare::Screens::Base::UpdateStrategy::SEPARATE_UPDATE_AND_RENDER_FUNCS);

   layout.set_bitmap_bin(bitmap_bin);
   layout.set_font_bin(font_bin);
   layout.set_tmj_filename(data_folder_path + "layouts/" + "along_a_path_10_digits-01.tmj");
   layout.set_scale(1);
   layout.initialize();

   // Setup the cursor to the initial position
   current_cursor_destination = layout.get_initial_cursor_destination();
   set_selection_cursor_box_to_new_position();

   // Wire up behavior
   wire_up_cursor_destination_activation_behavior();

   initialized = true;
   return;
}

void DrawAlongPath::puzzle__press_number_key(std::string number_str)
{
   puzzle__numbers_pressed += number_str;
   return;
}

void DrawAlongPath::puzzle__submit_puzzle_solution()
{
   bool puzzle_solved = false;
   if (puzzle__numbers_pressed == "041196") puzzle_solved = true;

   if (puzzle_solved)
   {
      std::cout << "Puzzle solved!" << std::endl;
      //event_emitter->emit_exit_game_event();
      //event_emitter->emit_game_won_event();
      event_emitter->emit_router_event(AllegroFlare::Routers::Standard::EVENT_WIN_GAME);
   }
   return;
}

void DrawAlongPath::puzzle__clear()
{
   puzzle__numbers_pressed.clear();
   return;
}

void DrawAlongPath::wire_up_cursor_destination_activation_behavior()
{
   layout.set_cursor_destinations_behavior({
      // number buttons

      { "0", {
         [this](){
            puzzle__press_number_key("0");
         }, {} /* On focus */, {} /* On blur */,
      }},
      { "1", {
         [this](){
            puzzle__press_number_key("1");
         }, {} /* On focus */, {} /* On blur */,
      }},
      { "2", {
         [this](){
            puzzle__press_number_key("2");
         }, {} /* On focus */, {} /* On blur */,
      }},
      { "3", {
         [this](){
            puzzle__press_number_key("3");
         }, {} /* On focus */, {} /* On blur */,
      }},
      { "4", {
         [this](){
            puzzle__press_number_key("4");
         }, {} /* On focus */, {} /* On blur */,
      }},
      { "5", {
         [this](){
            puzzle__press_number_key("5");
         }, {} /* On focus */, {} /* On blur */,
      }},
      { "6", {
         [this](){
            puzzle__press_number_key("6");
         }, {} /* On focus */, {} /* On blur */,
      }},
      { "7", {
         [this](){
            puzzle__press_number_key("7");
         }, {} /* On focus */, {} /* On blur */,
      }},
      { "8", {
         [this](){
            puzzle__press_number_key("8");
         }, {} /* On focus */, {} /* On blur */,
      }},
      { "9", {
         [this](){
            puzzle__press_number_key("9");
         }, {} /* On focus */, {} /* On blur */,
      }},

      // ui buttons

      { "clear", {
         [this](){
            puzzle__clear();
         }, {} /* On focus */, {} /* On blur */,
      }},
      { "submit", {
         [this](){
            // On activate
            puzzle__submit_puzzle_solution();
            //event_emitter->emit_exit_game_event();
         }, {} /* On focus */, {} /* On blur */,
      }},
      { "exit", {
         [this](){
            // On activate
            event_emitter->emit_exit_game_event();
         }, {} /* On focus */, {} /* On blur */,
      }},
   });
   return;
}

void DrawAlongPath::move_cursor_to(int target_tmj_object_id)
{
   AllegroFlare::Layouts::Elements::CursorDestination *next_destination =
      //cursor_map.
      layout.find_cursor_destination_by_tmj_object_id(target_tmj_object_id);
   if (target_tmj_object_id == 0)
   {
      // Nothing
      // TODO: Consider >boop< sound or unmoving cursor animation
   }
   else
   {
      if (current_cursor_destination && current_cursor_destination->on_blur)
      {
         current_cursor_destination->on_blur();
      }

      current_cursor_destination = next_destination;

      if (current_cursor_destination && current_cursor_destination->on_focus)
      {
         current_cursor_destination->on_focus();
      }

      set_selection_cursor_box_to_new_position();
   }
   return;
}

void DrawAlongPath::move_cursor_up()
{
   int next_id = current_cursor_destination->move_up_to_target_tmj_object_id;
   move_cursor_to(next_id);
   return;
}

void DrawAlongPath::move_cursor_down()
{
   int next_id = current_cursor_destination->move_down_to_target_tmj_object_id;
   move_cursor_to(next_id);
   return;
}

void DrawAlongPath::move_cursor_left()
{
   int next_id = current_cursor_destination->move_left_to_target_tmj_object_id;
   move_cursor_to(next_id);
   return;
}

void DrawAlongPath::move_cursor_right()
{
   int next_id = current_cursor_destination->move_right_to_target_tmj_object_id;
   move_cursor_to(next_id);
   return;
}

void DrawAlongPath::set_selection_cursor_box_to_new_position()
{
   layout_cursor_selection_box.reposition_to(
      current_cursor_destination->x,
      current_cursor_destination->y
   );
   layout_cursor_selection_box.resize_to(
      current_cursor_destination->width,
      current_cursor_destination->height
   );
   return;
}

bool DrawAlongPath::load_level_by_identifier(std::string level_identifier)
{
   return false;
}

void DrawAlongPath::on_activate()
{
   if (!(initialized))
   {
      std::stringstream error_message;
      error_message << "[TryingLayouts::Gameplay::Screens::DrawAlongPath::on_activate]: error: guard \"initialized\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[TryingLayouts::Gameplay::Screens::DrawAlongPath::on_activate]: error: guard \"initialized\" not met");
   }
   //emit_event_to_update_input_hints_bar();
   //emit_show_and_size_input_hints_bar_event();
   return;
}

void DrawAlongPath::on_deactivate()
{
   if (!(initialized))
   {
      std::stringstream error_message;
      error_message << "[TryingLayouts::Gameplay::Screens::DrawAlongPath::on_deactivate]: error: guard \"initialized\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[TryingLayouts::Gameplay::Screens::DrawAlongPath::on_deactivate]: error: guard \"initialized\" not met");
   }
   //emit_hide_and_restore_size_input_hints_bar_event();
   return;
}

void DrawAlongPath::update()
{
   layout_cursor_selection_box.update();

   layout_camera_2d.position.x = -layout_cursor_selection_box.get_position().x;
   layout_camera_2d.position.y = -layout_cursor_selection_box.get_position().y;

   layout_camera_2d.position.x = (int)(layout_camera_2d.position.x / 1920) * 1920;
   layout_camera_2d.position.y = (int)(layout_camera_2d.position.y / 1080) * 1080;

   return;
}

void DrawAlongPath::render()
{
   ALLEGRO_FONT *font = obtain_font();

   layout_camera_2d.start_transform();
   layout.render();
   layout_cursor_selection_box.render();
   layout_camera_2d.restore_transform();
   return;
}

void DrawAlongPath::game_event_func(AllegroFlare::GameEvent* game_event)
{
   if (!(game_event))
   {
      std::stringstream error_message;
      error_message << "[TryingLayouts::Gameplay::Screens::DrawAlongPath::game_event_func]: error: guard \"game_event\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[TryingLayouts::Gameplay::Screens::DrawAlongPath::game_event_func]: error: guard \"game_event\" not met");
   }
   return;
}

void DrawAlongPath::primary_update_func(double time_now, double delta_time)
{
   if (!(initialized))
   {
      std::stringstream error_message;
      error_message << "[TryingLayouts::Gameplay::Screens::DrawAlongPath::primary_update_func]: error: guard \"initialized\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[TryingLayouts::Gameplay::Screens::DrawAlongPath::primary_update_func]: error: guard \"initialized\" not met");
   }
   // Update stuff here (take into account delta_time)
   update();
   return;
}

void DrawAlongPath::primary_render_func()
{
   if (!(initialized))
   {
      std::stringstream error_message;
      error_message << "[TryingLayouts::Gameplay::Screens::DrawAlongPath::primary_render_func]: error: guard \"initialized\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[TryingLayouts::Gameplay::Screens::DrawAlongPath::primary_render_func]: error: guard \"initialized\" not met");
   }
   // Render stuff here
   render();
   return;
}

void DrawAlongPath::virtual_control_button_up_func(AllegroFlare::Player* player, AllegroFlare::VirtualControllers::Base* virtual_controller, int virtual_controller_button_num, bool is_repeat)
{
   if (!(initialized))
   {
      std::stringstream error_message;
      error_message << "[TryingLayouts::Gameplay::Screens::DrawAlongPath::virtual_control_button_up_func]: error: guard \"initialized\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[TryingLayouts::Gameplay::Screens::DrawAlongPath::virtual_control_button_up_func]: error: guard \"initialized\" not met");
   }
   // TODO: this function
   return;
}

void DrawAlongPath::virtual_control_button_down_func(AllegroFlare::Player* player, AllegroFlare::VirtualControllers::Base* virtual_controller, int virtual_controller_button_num, bool is_repeat)
{
   if (!(initialized))
   {
      std::stringstream error_message;
      error_message << "[TryingLayouts::Gameplay::Screens::DrawAlongPath::virtual_control_button_down_func]: error: guard \"initialized\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[TryingLayouts::Gameplay::Screens::DrawAlongPath::virtual_control_button_down_func]: error: guard \"initialized\" not met");
   }
   // TODO: this function
   using namespace AllegroFlare;
   //if (!is_processing_user_input()) return;

   if (virtual_controller_button_num == VirtualControllers::GenericController::BUTTON_UP)
   {
      move_cursor_up();
   }
   if (virtual_controller_button_num == VirtualControllers::GenericController::BUTTON_DOWN)
   {
      move_cursor_down();
   }
   if (virtual_controller_button_num == VirtualControllers::GenericController::BUTTON_RIGHT)
   {
      move_cursor_right();
   }
   if (virtual_controller_button_num == VirtualControllers::GenericController::BUTTON_LEFT)
   {
      move_cursor_left();
   }
   if (virtual_controller_button_num == VirtualControllers::GenericController::BUTTON_A
      || virtual_controller_button_num == VirtualControllers::GenericController::BUTTON_MENU
      )
   {
      if (current_cursor_destination->on_activation) current_cursor_destination->on_activation();
      //select_menu_option();
   }
   if (virtual_controller_button_num == VirtualControllers::GenericController::BUTTON_X)
   {
      //exit_screen();
   }
   //call_on_finished_callback_func(); // Consider technique to exit
   return;
}

void DrawAlongPath::virtual_control_axis_change_func(ALLEGRO_EVENT* ev)
{
   if (!(initialized))
   {
      std::stringstream error_message;
      error_message << "[TryingLayouts::Gameplay::Screens::DrawAlongPath::virtual_control_axis_change_func]: error: guard \"initialized\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[TryingLayouts::Gameplay::Screens::DrawAlongPath::virtual_control_axis_change_func]: error: guard \"initialized\" not met");
   }
   // TODO: this function
   return;
}

ALLEGRO_FONT* DrawAlongPath::obtain_font()
{
   if (!(font_bin))
   {
      std::stringstream error_message;
      error_message << "[TryingLayouts::Gameplay::Screens::DrawAlongPath::obtain_font]: error: guard \"font_bin\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[TryingLayouts::Gameplay::Screens::DrawAlongPath::obtain_font]: error: guard \"font_bin\" not met");
   }
   return font_bin->auto_get("Inter-Regular.ttf -32");
}


} // namespace Screens
} // namespace Gameplay
} // namespace TryingLayouts


