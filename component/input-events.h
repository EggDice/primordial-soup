#ifndef COMPONENT_INPUT_EVENTS_H_
#define COMPONENT_INPUT_EVENTS_H_

#include <vector>

#include "../event/keyboard-event.h"

namespace soup {
namespace component {

struct InputEvents {
  std::vector<event::KeyboardEvent> keyboard_events;
};

}  // namespace component
}  // namespace soup

#endif  // COMPONENT_INPUT_EVENTS_H_
