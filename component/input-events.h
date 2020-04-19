#ifndef COMPONENT_INPUT_EVENTS_H_
#define COMPONENT_INPUT_EVENTS_H_

#include <vector>

#include "../event/keyboard-event.h"
#include "../event/resize-event.h"

namespace soup {
namespace component {

struct InputEvents {
  std::vector<event::KeyboardEvent> keyboard_events;
  std::vector<event::ResizeEvent> resize_events;
  void Add(event::KeyboardEvent event);
  void Add(event::ResizeEvent event);
};

}  // namespace component
}  // namespace soup

#endif  // COMPONENT_INPUT_EVENTS_H_
