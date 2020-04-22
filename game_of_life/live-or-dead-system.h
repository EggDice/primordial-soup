#ifndef GAME_OF_LIFE_LIVE_OR_DEAD_SYSTEM_H_
#define GAME_OF_LIFE_LIVE_OR_DEAD_SYSTEM_H_

#include <entt/entt.hpp>

#include "../event/tick-event.h"

namespace soup {
namespace game_of_life {

class LiveOrDeadSystem {
 public:
  void Update(entt::registry& registry, const event::TickEvent& event); // NOLINT
};

}  // namespace game_of_life
}  // namespace soup

#endif  // GAME_OF_LIFE_LIVE_OR_DEAD_SYSTEM_H_
