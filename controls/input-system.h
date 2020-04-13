#ifndef CONTROLS_INPUT_SYSTEM_H_
#define CONTROLS_INPUT_SYSTEM_H_

#include <entt/entt.hpp>

#include "../component/input-events.h"

namespace soup {
namespace controls {

class InputSystem {
 public:
  template <typename T>
  void Update(const entt::registry& registry, T event);
};

}  // namespace controls
}  // namespace soup

#endif  // CONTROLS_INPUT_SYSTEM_H_
