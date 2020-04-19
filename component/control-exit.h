#ifndef COMPONENT_CONTROL_EXIT_H_
#define COMPONENT_CONTROL_EXIT_H_

#include "../event/keyboard-event.h"

namespace soup {
namespace component {

struct ControlExit {
  event::KeyCode key_code;
};

}  // namespace component
}  // namespace soup

#endif  // COMPONENT_CONTROL_EXIT_H_
