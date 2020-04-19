#ifndef WINDOW_GLUT_WINDOW_UTILITY_H_
#define WINDOW_GLUT_WINDOW_UTILITY_H_

#include "window-utility.h"

namespace soup {
namespace window {

class GlutWindowUtility : public WindowUtility {
 public:
  void Init(int * argcp,
            char **argv,
            const component::RenderViewport& viewport,
            const component::Window& window) const;
  void Exit() const;
  void RegisterKeyboardFunction(void (*func)(unsigned char key,
                                             int x, int y)) const;
  void RegisterKeyboardSpecialFunction(void (*func)(int key,
                                                    int x, int y)) const;
  void RegisterResizeFunction(void (*func)(int width, int height)) const;
  void RegisterMouseFunction(void (*func)(int button,
                                          int state,
                                          int x, int y)) const;
  void RegisterDisplayFunction(void (*func)(void)) const;
  void RegisterTickFunc(void (*func)(int value)) const;
  void StartMainLoop() const;
  void PostRedisplay() const;
  static const uint64_t tick_time;
};

}  // namespace window
}  // namespace soup

#endif  // WINDOW_GLUT_WINDOW_UTILITY_H_
