#include "live-or-dead-system.h"

#include <iostream>
#include <vector>
#include <algorithm>

#include <glm/glm.hpp>

#include "game-of-life.h"
#include "../component/position.h"
#include "../component/color.h"
#include "../component/game-of-life-cell.h"

namespace soup {
namespace game_of_life {

void LiveOrDeadSystem::Update(entt::registry& registry,
                              const event::TickEvent& event) {
  auto game_of_life = GameOfLife{{21, 21, 21}, {2, 6}, {4, 6}};
  auto view = registry.view<
    component::Position,
    component::Color,
    component::GameOfLifeCell>();
  auto old_state = std::vector<bool>{};
  old_state.resize(view.size());
  auto new_state = std::vector<bool>{};
  new_state.resize(view.size());

  std::transform(
    view.begin(),
    view.end(),
    old_state.begin(),
    [&registry](auto& entity) {
      return registry.get<component::GameOfLifeCell>(entity).is_alive;
    });

  game_of_life.TransformNewState(
    old_state.begin(),
    old_state.end(),
    new_state.begin());

  uint64_t count = 0;
  view.each([&count, &new_state] (
    auto& position,
    auto& color,
    auto& cell) {
      cell.is_alive = new_state[count++];
      color.color = cell.is_alive ?
        glm::vec3(0.7f, 0.7f, 0.0f) : glm::vec3(0.0f, 0.0f, 0.0f);
  });
}

}  // namespace game_of_life
}  // namespace soup
