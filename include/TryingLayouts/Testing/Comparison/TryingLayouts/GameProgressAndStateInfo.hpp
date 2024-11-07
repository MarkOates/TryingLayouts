#pragma once


#include <TryingLayouts/GameProgressAndStateInfo.hpp>
#include <ostream>


namespace TryingLayouts
{
   bool operator==(const GameProgressAndStateInfo& object, const GameProgressAndStateInfo& other_object);
   bool operator!=(const GameProgressAndStateInfo& object, const GameProgressAndStateInfo& other_object);
   void PrintTo(const GameProgressAndStateInfo& object, ::std::ostream* os);
}


