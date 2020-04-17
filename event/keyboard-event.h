#ifndef EVENT_KEYBOARD_EVENT_H_
#define EVENT_KEYBOARD_EVENT_H_

#include "event.h"

namespace soup {
namespace event {

enum KeyCode {
  ESC_KEY,
  UNDEFINED_KEY,
  ARROW_UP_KEY,
  ARROW_RIGHT_KEY,
  ARROW_DOWN_KEY,
  ARROW_LEFT_KEY
};

struct KeyboardEvent : public Event {
  KeyCode key_code;
};

}  // namespace event
}  // namespace soup

#endif  // EVENT_KEYBOARD_EVENT_H_
