#ifndef WINDOW_WINDOW_SYSTEM_H_
#define WINDOW_WINDOW_SYSTEM_H_

#include <entt/entt.hpp>

#include "window-utility.h"
#include "../event/tick-event.h"

namespace soup {
namespace window {

class WindowSystem {
 public:
  explicit WindowSystem(const WindowUtility& window_utility);
  void Init(entt::registry& registry, int* argcp, char ** argv); // NOLINT
  void Update(entt::registry& registry, const event::TickEvent& event); // NOLINT
 private:
  const WindowUtility& window_utility_;
};

}  // namespace window
}  // namespace soup

#endif  // WINDOW_WINDOW_SYSTEM_H_
