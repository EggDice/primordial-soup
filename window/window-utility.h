#ifndef WINDOW_WINDOW_UTILITY_H_
#define WINDOW_WINDOW_UTILITY_H_

#include "../component/window.h"
#include "../component/render-viewport.h"

namespace soup {
namespace window {

class WindowUtility {
 public:
  virtual ~WindowUtility() {}
  virtual void Init(int * argcp,
                    char **argv,
                    const component::RenderViewport& viewport,
                    const component::Window& window) const = 0;
  virtual void Exit() const = 0;
  virtual void RegisterKeyboardFunction(void (*func)(unsigned char key,
                                                     int x, int y)) const = 0;
  virtual void RegisterKeyboardSpecialFunction(void (*func)(int key,
                                                            int x,
                                                            int y)) const = 0;
  virtual void RegisterResizeFunction(void (*func)(int width,
                                                   int height)) const = 0;
  virtual void RegisterMouseFunction(void (*func)(int button,
                                                  int state,
                                                  int x, int y)) const = 0;
  virtual void RegisterDisplayFunction(void (*func)(void)) const = 0;
  virtual void RegisterTickFunc(void (*func)(int value)) const = 0;
  virtual void StartMainLoop() const = 0;
  virtual void PostRedisplay() const = 0;
};

}  // namespace window
}  // namespace soup

#endif  // WINDOW_WINDOW_UTILITY_H_
