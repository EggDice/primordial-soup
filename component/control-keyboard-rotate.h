#ifndef COMPONENT_CONTROL_KEYBOARD_ROTATE_H_
#define COMPONENT_CONTROL_KEYBOARD_ROTATE_H_

#include <map>

#include "../event/keyboard-event.h"
#include "rotation.h"

namespace soup {
namespace component {

struct ControlKeyBoardRotate {
  std::map<event::KeyCode, Rotation> key_rotations;
};

}  // namespace component
}  // namespace soup

#endif  // COMPONENT_CONTROL_KEYBOARD_ROTATE_H_
