#include "input-system.h"

#include <vector>

namespace soup {
namespace controls {

template
void InputSystem::Update<event::KeyboardEvent>(const entt::registry& registry,
                                               event::KeyboardEvent event);

template <typename T>
void InputSystem::Update(const entt::registry& registry, T event) {
  const_cast<entt::registry&>(registry).view<
    component::InputEvents
  >().each([&event] (auto& input_events) {
    input_events.keyboard_events.push_back(event);
  });
}


}  // namespace controls
}  // namespace soup
