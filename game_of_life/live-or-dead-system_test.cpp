#include <gtest/gtest.h>

#include "live-or-dead-system.h"
#include <entt/entt.hpp>
#include "../component/position.h"
#include "../component/game-of-life-cell.h"

namespace {
namespace g = soup::game_of_life;
namespace c = soup::component;
namespace e = soup::event;

TEST(LiveOrDeadSystem, One) {
  auto live_or_dead_system = g::LiveOrDeadSystem{};
  auto registry = entt::registry{};
  auto entity_000 = registry.create();
  registry.assign<c::Position>(entity_000, glm::vec3(0.0f, 0.0f, 0.0f));
  registry.assign<c::GameOfLifeCell>(entity_000, c::GameOfLifeCell{true});

  live_or_dead_system.Update(registry, e::TickEvent{e::Timer::Now()});

  auto cell_000 = registry.get<c::GameOfLifeCell>(entity_000).is_alive;

  EXPECT_EQ(cell_000, true);
}
}  // namespace

