#include "glut-connector.h"

namespace soup {
namespace event {


KeyCode GlutKeyboardToKeyCode(uint8_t key) {
  return glut_keyboard_to_key_code.contains(key) ?
    glut_keyboard_to_key_code.at(key) :
    UNDEFINED_KEY;
}

KeyCode GlutSpecialKeyboardToKeyCode(int key) {
  return glut_special_keyboard_to_key_code.contains(key) ?
    glut_special_keyboard_to_key_code.at(key) :
    UNDEFINED_KEY;
}

}  // namespace event
}  // namespace soup
