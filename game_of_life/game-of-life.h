#ifndef GAME_OF_LIFE_GAME_OF_LIFE_H_
#define GAME_OF_LIFE_GAME_OF_LIFE_H_

#include <vector>
#include <array>
#include <cmath>

#include <glm/glm.hpp>

namespace soup {
namespace game_of_life {

class GameOfLife {
 public:
  explicit GameOfLife(glm::ivec3 size,
                      glm::ivec2 stay_alive_interval,
                      glm::ivec2 reproduction_interval);
  void TransformNewState(std::vector<bool>::const_iterator last_state,
                         std::vector<bool>::const_iterator last_state_end,
                         std::vector<bool>::iterator new_state) const;

 private:
  bool IsAlive(std::vector<bool>::const_iterator begin,
               std::vector<bool>::const_iterator it) const;
  static constexpr uint64_t neighbour_count_ = pow(3, 3) - 1;
  std::array<bool, GameOfLife::neighbour_count_>
    GetNeighbours(std::vector<bool>::const_iterator begin,
                  std::vector<bool>::const_iterator it) const;
  std::array<uint64_t, GameOfLife::neighbour_count_>
    GetNeighbourIndexes(uint64_t index) const;
  glm::ivec3 IndexToCoord(uint64_t index) const;
  glm::ivec3 BoundCoord(glm::ivec3 coord) const;
  uint64_t CoordToIndex(glm::ivec3 coord) const;
  glm::ivec3 size_;
  glm::ivec2 stay_alive_interval_;
  glm::ivec2 reproduction_interval_;
  static const std::array<glm::ivec3, GameOfLife::neighbour_count_>
    neighbour_coords_;
  static constexpr std::array<glm::ivec3, GameOfLife::neighbour_count_>
    GetNeighbourCoords();
};

}  // namespace game_of_life
}  // namespace soup

#endif  // GAME_OF_LIFE_GAME_OF_LIFE_H_
