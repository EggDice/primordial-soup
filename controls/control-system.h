#ifndef CONTROLS_CONTROL_SYSTEM_H_
#define CONTROLS_CONTROL_SYSTEM_H_

#include <entt/entt.hpp>

#include "../event/tick-event.h"
#include "../component/input-events.h"

namespace soup {
namespace controls {

class ControlSystem {
 public:
  void Update(const entt::registry& registry, event::TickEvent event);
 private:
  void UpdateRotate(const entt::registry& registry,
                    const component::InputEvents& input_events);
  void UpdateResize(const entt::registry& registry,
                    const component::InputEvents& input_events);
};

}  // namespace controls
}  // namespace soup

#endif  // CONTROLS_CONTROL_SYSTEM_H_
