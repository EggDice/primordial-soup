#include "input-system.h"

#include <vector>

namespace soup {
namespace controls {

template
void InputSystem::Update<event::KeyboardEvent>(entt::registry& registry, // NOLINT
                                               event::KeyboardEvent event);

template
void InputSystem::Update<event::ResizeEvent>(entt::registry& registry, // NOLINT
                                             event::ResizeEvent event);

template <typename T>
void InputSystem::Update(entt::registry& registry, T event) {
  registry.view<
    component::InputEvents
  >().each([&event] (auto& input_events) {
    input_events.Add(event);
  });
}


}  // namespace controls
}  // namespace soup
