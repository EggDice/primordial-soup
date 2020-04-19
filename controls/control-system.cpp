#include "control-system.h"

#include "../component/rotation.h"
#include "../component/control-keyboard-rotate.h"
#include "../component/render-viewport.h"
#include "../component/control-resize.h"

namespace soup {
namespace controls {


void ControlSystem::Update(const entt::registry& registry,
                           const event::TickEvent& event) {
  const_cast<entt::registry&>(registry).view<
    component::InputEvents
  >().each([&registry, this] (auto& input_events) {
    UpdateRotate(registry, input_events);
    UpdateResize(registry, input_events);
    input_events.keyboard_events.clear();
    input_events.resize_events.clear();
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

void ControlSystem::UpdateResize(const entt::registry& registry,
                                 const component::InputEvents& input_events) {
  const_cast<entt::registry&>(registry).view<
    component::ControlResize,
    component::RenderViewport
  >().each([&input_events] (auto& control, auto& viewport) {
    for (auto& event : input_events.resize_events) {
      viewport.width = event.width;
      viewport.height = event.height;
    }
  });
}

}  // namespace controls
}  // namespace soup
