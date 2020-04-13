#ifndef EVENT_KEYBOARD_EVENT_H_
#define EVENT_KEYBOARD_EVENT_H_

#include "event.h"

namespace soup {
namespace event {

enum KeyCode {
  ESC_KEY = 27
};

struct KeyboardEvent : public Event {
  KeyCode key_code;
};

}  // namespace event
}  // namespace soup

#endif  // EVENT_KEYBOARD_EVENT_H_
