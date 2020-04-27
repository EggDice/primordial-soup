#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <vector>

#include <glm/glm.hpp>
#include "game-of-life.h"

namespace {
namespace g = soup::game_of_life;

using ::testing::ElementsAreArray;

TEST(GameOfLife, OneRemainDead) {
  auto last_state = std::vector<bool>{0};
  auto new_state = std::vector<bool>(last_state.size());
  auto game_of_life = g::GameOfLife{glm::ivec3{1, 1, 1}, {2, 4}, {3, 4}};
  game_of_life.TransformNewState(
    last_state.begin(),
    last_state.end(),
    new_state.begin());
  EXPECT_THAT(new_state, ElementsAreArray({
    0
  }));
}

TEST(GameOfLife, OneDies) {
  auto last_state = std::vector<bool>{1};
  auto new_state = std::vector<bool>(last_state.size());
  auto game_of_life = g::GameOfLife{glm::ivec3{1, 1, 1}, {2, 4}, {3, 4}};
  game_of_life.TransformNewState(
    last_state.begin(),
    last_state.end(),
    new_state.begin());
  EXPECT_THAT(new_state, ElementsAreArray({
    0
  }));
}

TEST(GameOfLife, OneInTheMiddleDies) {
  auto last_state = std::vector<bool>{
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,

    0, 0, 0,
    0, 1, 0,
    0, 0, 0,

    0, 0, 0,
    0, 0, 0,
    0, 0, 0
  };
  auto new_state = std::vector<bool>(last_state.size());
  auto game_of_life = g::GameOfLife{glm::ivec3{3, 3, 3}, {2, 4}, {3, 4}};
  game_of_life.TransformNewState(
    last_state.begin(),
    last_state.end(),
    new_state.begin());
  EXPECT_THAT(new_state, ElementsAreArray({
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,

    0, 0, 0,
    0, 0, 0,
    0, 0, 0,

    0, 0, 0,
    0, 0, 0,
    0, 0, 0
  }));
}

TEST(GameOfLife, BlockStaysInTheMiddle) {
  auto last_state = std::vector<bool>{
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,

    0, 0, 0, 0,
    0, 1, 1, 0,
    0, 1, 1, 0,
    0, 0, 0, 0,

    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,

    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0
  };
  auto new_state = std::vector<bool>(last_state.size());
  auto game_of_life = g::GameOfLife{glm::ivec3{4, 4, 4}, {2, 4}, {3, 4}};
  game_of_life.TransformNewState(
    last_state.begin(),
    last_state.end(),
    new_state.begin());
  EXPECT_THAT(new_state, ElementsAreArray({
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,

    0, 0, 0, 0,
    0, 1, 1, 0,
    0, 1, 1, 0,
    0, 0, 0, 0,

    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,

    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0
  }));
}
}  // namespace

