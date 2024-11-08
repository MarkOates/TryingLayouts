

#include <TryingLayouts/Gameplay/Level.hpp>




namespace TryingLayouts
{
namespace Gameplay
{


Level::Level()
   : AllegroFlare::Levels::Base(TryingLayouts::Gameplay::Level::TYPE)
   , title("[unset-title]")
{
}


Level::~Level()
{
}


void Level::set_title(std::string title)
{
   this->title = title;
}


std::string Level::get_title() const
{
   return title;
}




} // namespace Gameplay
} // namespace TryingLayouts


