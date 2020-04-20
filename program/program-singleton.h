#ifndef PROGRAM_PROGRAM_SINGLETON_H_
#define PROGRAM_PROGRAM_SINGLETON_H_

#include "program.h"

namespace soup {
class ProgramSingleton {
 public:
  static int Run(const int argc, char** argv);
  static void HandleKeypress(unsigned char key, int x, int y);
  static void HandleSpecialKeypress(int key, int x, int y);
  static void HandleResize(int w, int h);
  static void HandleMouse(int button, int state, int x, int y);
  static void HandleDisplay();
  static void HandleTick(int value);
 private:
  static const rendering::OpenGlGraphicsEngine graphics_engine_;
  static const window::GlutWindowUtility window_utility_;
  static Program program_;
};
}  // namespace soup


#endif  // PROGRAM_PROGRAM_SINGLETON_H_
