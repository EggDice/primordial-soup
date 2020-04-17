#ifndef EVENT_GLUT_CONNECTOR_H_
#define EVENT_GLUT_CONNECTOR_H_

#include <map>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "keyboard-event.h"

namespace soup {
namespace event {

const std::map<uint8_t, KeyCode> glut_keyboard_to_key_code = {
  {27, ESC_KEY},
};

const std::map<int, KeyCode> glut_special_keyboard_to_key_code = {
  {GLUT_KEY_UP, ARROW_UP_KEY},
  {GLUT_KEY_RIGHT, ARROW_RIGHT_KEY},
  {GLUT_KEY_DOWN, ARROW_DOWN_KEY},
  {GLUT_KEY_LEFT, ARROW_LEFT_KEY},
};

KeyCode GlutKeyboardToKeyCode(uint8_t key);

KeyCode GlutSpecialKeyboardToKeyCode(int key);

}  // namespace event
}  // namespace soup

#endif  // EVENT_GLUT_CONNECTOR_H_
