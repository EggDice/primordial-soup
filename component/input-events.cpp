#include "input-events.h"

namespace soup {
namespace component {

void InputEvents::Add(event::KeyboardEvent event) {
  keyboard_events.push_back(event);
}

void InputEvents::Add(event::ResizeEvent event) {
  resize_events.push_back(event);
}

}  // namespace component
}  // namespace soup
