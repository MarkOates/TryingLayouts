#pragma once


#include <AllegroFlare/AssetStudio/Database.hpp>
#include <AllegroFlare/BitmapBin.hpp>
#include <AllegroFlare/Camera2D.hpp>
#include <AllegroFlare/Elements/SelectionCursorBox.hpp>
#include <AllegroFlare/EventEmitter.hpp>
#include <AllegroFlare/FontBin.hpp>
#include <AllegroFlare/GameEvent.hpp>
#include <AllegroFlare/Layouts/Elements/CursorDestination.hpp>
#include <AllegroFlare/Layouts/Layout.hpp>
#include <AllegroFlare/ModelBin.hpp>
#include <AllegroFlare/Player.hpp>
#include <AllegroFlare/Screens/Gameplay.hpp>
#include <AllegroFlare/VirtualControllers/Base.hpp>
#include <TryingLayouts/Gameplay/Level.hpp>
#include <allegro5/allegro.h>
#include <string>


namespace TryingLayouts
{
   namespace Gameplay
   {
      class Screen : public AllegroFlare::Screens::Gameplay
      {
      public:
         static constexpr char* DEFAULT_DATA_FOLDER_PATH = (char*)"[unset-data_folder_path]";
         static constexpr char* TYPE = (char*)"TryingLayouts/Gameplay/Screen";

      private:
         std::string data_folder_path;
         AllegroFlare::AssetStudio::Database* asset_studio_database;
         AllegroFlare::EventEmitter* event_emitter;
         AllegroFlare::BitmapBin* bitmap_bin;
         AllegroFlare::FontBin* font_bin;
         AllegroFlare::ModelBin* model_bin;
         AllegroFlare::Camera2D layout_camera_2d;
         AllegroFlare::Layouts::Layout layout;
         AllegroFlare::Elements::SelectionCursorBox layout_cursor_selection_box;
         AllegroFlare::Layouts::Elements::CursorDestination* current_cursor_destination;
         std::string current_level_identifier;
         TryingLayouts::Gameplay::Level* current_level;
         bool initialized;

      protected:


      public:
         Screen();
         virtual ~Screen();

         void set_data_folder_path(std::string data_folder_path);
         void set_asset_studio_database(AllegroFlare::AssetStudio::Database* asset_studio_database);
         void set_event_emitter(AllegroFlare::EventEmitter* event_emitter);
         void set_bitmap_bin(AllegroFlare::BitmapBin* bitmap_bin);
         void set_font_bin(AllegroFlare::FontBin* font_bin);
         void set_model_bin(AllegroFlare::ModelBin* model_bin);
         std::string get_data_folder_path() const;
         AllegroFlare::EventEmitter* get_event_emitter() const;
         bool get_initialized() const;
         AllegroFlare::AssetStudio::Database* &get_asset_studio_database_ref();
         void initialize();
         void move_cursor_to(int target_tmj_object_id=0);
         void move_cursor_up();
         void move_cursor_down();
         void move_cursor_left();
         void move_cursor_right();
         void set_selection_cursor_box_to_new_position();
         virtual bool load_level_by_identifier(std::string level_identifier="[unset-level_identifier]") override;
         virtual void on_activate() override;
         virtual void on_deactivate() override;
         void update();
         void render();
         virtual void game_event_func(AllegroFlare::GameEvent* game_event=nullptr) override;
         virtual void primary_update_func(double time_now=0.0f, double delta_time=1.0f) override;
         virtual void primary_render_func() override;
         virtual void virtual_control_button_up_func(AllegroFlare::Player* player=nullptr, AllegroFlare::VirtualControllers::Base* virtual_controller=nullptr, int virtual_controller_button_num=0, bool is_repeat=false) override;
         virtual void virtual_control_button_down_func(AllegroFlare::Player* player=nullptr, AllegroFlare::VirtualControllers::Base* virtual_controller=nullptr, int virtual_controller_button_num=0, bool is_repeat=false) override;
         virtual void virtual_control_axis_change_func(ALLEGRO_EVENT* ev=nullptr) override;
         ALLEGRO_FONT* obtain_font();
      };
   }
}



