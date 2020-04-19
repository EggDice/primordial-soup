#ifndef WINDOW_MOCK_WINDOW_UTILITY_H_
#define WINDOW_MOCK_WINDOW_UTILITY_H_

#include <gmock/gmock.h>

#include "window-utility.h"

namespace soup {
namespace window {

class MockWindowUtility : public WindowUtility {
 public:
  MOCK_METHOD(void, Init, (int * argcp,
                           char **argv,
                           const component::RenderViewport& viewport,
                           const component::Window& window), (const));
  MOCK_METHOD(void, Exit, (), (const));
  MOCK_METHOD(void, RegisterKeyboardFunction, ((void (*func)(unsigned char key,
                                             int x, int y))), (const));
  MOCK_METHOD(void, RegisterKeyboardSpecialFunction, ((void (*func)(int key,
                                                    int x, int y))), (const));
  MOCK_METHOD(void, RegisterResizeFunction, ((void (*func)(int width,
                                                           int height))),
                                            (const));
  MOCK_METHOD(void, RegisterMouseFunction, ((void (*func)(int button,
                                          int state,
                                          int x, int y))), (const));
  MOCK_METHOD(void, RegisterDisplayFunction, ((void (*func)(void))), (const));
  MOCK_METHOD(void, RegisterTickFunc, ((void (*func)(int value))), (const));
  MOCK_METHOD(void, StartMainLoop, (), (const));
  MOCK_METHOD(void, PostRedisplay, (), (const));
};

}  // namespace window
}  // namespace soup

#endif  // WINDOW_MOCK_WINDOW_UTILITY_H_
