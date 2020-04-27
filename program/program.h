#ifndef PROGRAM_PROGRAM_H_
#define PROGRAM_PROGRAM_H_

#include <cstdint>
#include <string>

#include "../rendering/render-system.h"
#include "../rendering/graphics-system.h"
#include "../rendering/graphics-engine.h"
#include "../rendering/opengl-graphics-engine.h"
#include "../controls/input-system.h"
#include "../controls/control-system.h"
#include "../window/window-utility.h"
#include "../window/glut-window-utility.h"
#include "../window/window-system.h"
#include "../game_of_life/live-or-dead-system.h"

namespace soup {
class Program {
 public:
  Program(const rendering::GraphicsEngine& graphics,
          const window::WindowUtility& window);
  void Init(int argc, char** argv);
  void HandleKeypress(unsigned char key, int x, int y);
  void HandleSpecialKeypress(int key, int x, int y);
  void HandleResize(int w, int h);
  void HandleMouse(int button, int state, int x, int y);
  void HandleDisplay();
  void HandleTick(int value);
  void RegisterKeyboardFunction(void (*func)(unsigned char key, int x, int y));
  void RegisterKeyboardSpecialFunction(void (*func)(int key, int x, int y));
  void RegisterResizeFunction(void (*func)(int width, int height));
  void RegisterMouseFunction(void (*func)(int button, int state, int x, int y));
  void RegisterDisplayFunction(void (*func)(void));
  void RegisterTickFunc(void (*func)(int value));
  void StartMainLoop();
  static const uint64_t tick_time;

 private:
  const rendering::GraphicsEngine& graphics_;
  const window::WindowUtility& window_utility_;
  rendering::GraphicsSystem graphics_system_;
  rendering::RenderSystem render_system_;
  controls::InputSystem input_system_;
  controls::ControlSystem control_system_;
  window::WindowSystem window_system_;
  game_of_life::LiveOrDeadSystem live_or_dead_system_;
  entt::registry registry_;
  static const char name_[];
};
}  // namespace soup

#endif  // PROGRAM_PROGRAM_H_
