#ifndef CONTROLS_CONTROL_SYSTEM_H_
#define CONTROLS_CONTROL_SYSTEM_H_

#include <entt/entt.hpp>

#include "../event/tick-event.h"
#include "../component/input-events.h"

namespace soup {
namespace controls {

class ControlSystem {
 public:
  void Update(entt::registry& registry, const event::TickEvent& event); // NOLINT
 private:
  void UpdateRotate(entt::registry& registry, // NOLINT
                    const component::InputEvents& input_events);
  void UpdateResize(entt::registry& registry, // NOLINT
                    const component::InputEvents& input_events);
  void UpdateExit(entt::registry& registry, // NOLINT
                  const component::InputEvents& input_events);
};

}  // namespace controls
}  // namespace soup

#endif  // CONTROLS_CONTROL_SYSTEM_H_
