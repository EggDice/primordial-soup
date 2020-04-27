#include "game-of-life.h"

#include <algorithm>

namespace soup {
namespace game_of_life {

GameOfLife::GameOfLife(glm::ivec3 size,
                       glm::ivec2 stay_alive_interval,
                       glm::ivec2 reproduction_interval) {
  size_ = size;
  stay_alive_interval_ = stay_alive_interval;
  reproduction_interval_ = reproduction_interval;
}

void GameOfLife::TransformNewState(
    std::vector<bool>::const_iterator last_state,
    std::vector<bool>::const_iterator last_state_end,
    std::vector<bool>::iterator new_state) const {
  auto begin = last_state;
  while (last_state != last_state_end) {
    *new_state = IsAlive(begin, last_state);
    last_state++;
    new_state++;
  }
}

bool GameOfLife::IsAlive(std::vector<bool>::const_iterator begin,
                         std::vector<bool>::const_iterator it) const {
  auto neighbours = GetNeighbours(begin, it);
  auto live_neighbour_count =
    std::count(neighbours.begin(), neighbours.end(), true);
  auto limit_interval = *it ? stay_alive_interval_ : reproduction_interval_;
  return live_neighbour_count >= limit_interval[0] &&
         live_neighbour_count < limit_interval[1];
}

std::array<uint64_t, GameOfLife::neighbour_count_>
    GameOfLife::GetNeighbourIndexes(uint64_t index) const {
  auto distances = std::array<uint64_t, GameOfLife::neighbour_count_>{};
  std::transform(neighbour_coords_.begin(),
                 neighbour_coords_.end(),
                 distances.begin(),
                 [&index, this] (auto neighbour_coord) {
    auto current_coord = IndexToCoord(index);
    auto bounded_coord = BoundCoord(current_coord + neighbour_coord);
    return CoordToIndex(bounded_coord);
  });
  return distances;
}

std::array<bool, GameOfLife::neighbour_count_>
  GameOfLife::GetNeighbours(std::vector<bool>::const_iterator begin,
                            std::vector<bool>::const_iterator it) const {
  auto neighbours = std::array<bool, GameOfLife::neighbour_count_>{};
  auto neighbour_indexes = GetNeighbourIndexes(it - begin);
  std::transform(neighbour_indexes.begin(),
                 neighbour_indexes.end(),
                 neighbours.begin(),
                 [it, begin] (auto distance) {
    return *(begin + distance);
  });
  return neighbours;
}

glm::ivec3 GameOfLife::IndexToCoord(uint64_t index) const {
  return glm::ivec3(
    index % size_.x,
    index / size_.x % size_.y,
    index / size_.x / size_.y);
}

glm::ivec3 GameOfLife::BoundCoord(glm::ivec3 coord) const {
  return glm::ivec3(
    (coord.x + size_.x) % size_.x,
    (coord.y + size_.y) % size_.y,
    (coord.z + size_.z) % size_.z);
}

uint64_t GameOfLife::CoordToIndex(glm::ivec3 coord) const {
  return coord.x + coord.y * size_.x + coord.z * size_.x * size_.y;
}

constexpr std::array<glm::ivec3, GameOfLife::neighbour_count_>
    GameOfLife::GetNeighbourCoords() {
  auto neighbours = std::array<glm::ivec3, GameOfLife::neighbour_count_>{};
  uint64_t count = 0;
  for (int64_t z = -1; z <= 1; ++z) {
    for (int64_t y = -1; y <= 1; ++y) {
      for (int64_t x = -1; x <= 1; ++x) {
        if (x != 0 || y != 0 || z != 0) {
          neighbours[count++] = glm::ivec3(x, y, z);
        }
      }
    }
  }
  return neighbours;
}

const std::array<glm::ivec3, GameOfLife::neighbour_count_>
  GameOfLife::neighbour_coords_ = GetNeighbourCoords();
}  // namespace game_of_life
}  // namespace soup
