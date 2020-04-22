#include "live-or-dead-system.h"

#include "../component/position.h"
#include "../component/game-of-life-cell.h"

namespace soup {
namespace game_of_life {

void LiveOrDeadSystem::Update(entt::registry& registry,
                              const event::TickEvent& event) {
  registry.view<
    component::Position,
    component::GameOfLifeCell
  >().each([] (
    auto& position,
    auto& cell) {
  });
}

}  // namespace game_of_life
}  // namespace soup
