#include "control-system.h"

#include "../component/rotation.h"
#include "../component/control-keyboard-rotate.h"

namespace soup {
namespace controls {


void ControlSystem::Update(const entt::registry& registry,
                           event::TickEvent event) {
  const_cast<entt::registry&>(registry).view<
    component::InputEvents
  >().each([&registry, this] (auto& input_events) {
    UpdateRotate(registry, input_events);
    input_events.keyboard_events.clear();
  });
}

void ControlSystem::UpdateRotate(const entt::registry& registry,
                                 const component::InputEvents& input_events) {
  const_cast<entt::registry&>(registry).view<
    component::ControlKeyBoardRotate,
    component::Rotation
  >().each([&input_events] (auto& control, auto& rotation) {
    for (auto& event : input_events.keyboard_events) {
      if (control.key_rotations.contains(event.key_code)) {
        auto delta_rotation = control.key_rotations[event.key_code];
        rotation += delta_rotation;
      }
    }
  });
}

}  // namespace controls
}  // namespace soup
