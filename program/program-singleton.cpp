#include "program-singleton.h"

namespace soup {
int ProgramSingleton::Run(const int argc, char** argv) {
  program_.Init(argc, argv);
  program_.RegisterDisplayFunction(ProgramSingleton::HandleDisplay);
  program_.RegisterKeyboardFunction(ProgramSingleton::HandleKeypress);
  program_
    .RegisterKeyboardSpecialFunction(ProgramSingleton::HandleSpecialKeypress);
  program_.RegisterMouseFunction(ProgramSingleton::HandleMouse);
  program_.RegisterResizeFunction(ProgramSingleton::HandleResize);
  program_.RegisterTickFunc(ProgramSingleton::HandleTick);
  program_.StartMainLoop();
  return 0;
}

void ProgramSingleton::HandleDisplay() {
  program_.HandleDisplay();
}

void ProgramSingleton::HandleKeypress(unsigned char key, int x, int y) {
  program_.HandleKeypress(key, x, y);
}

void ProgramSingleton::HandleSpecialKeypress(int key, int x, int y) {
  program_.HandleSpecialKeypress(key, x, y);
}

void ProgramSingleton::HandleMouse(int button, int state, int x, int y) {
  program_.HandleMouse(button, state, x, y);
}

void ProgramSingleton::HandleResize(int w, int h) {
  program_.HandleResize(w, h);
}

void ProgramSingleton::HandleTick(int value) {
  program_.HandleTick(value);
  program_.RegisterTickFunc(ProgramSingleton::HandleTick);
}

const rendering::OpenGlGraphicsEngine ProgramSingleton::graphics_engine_{};

const window::GlutWindowUtility ProgramSingleton::window_utility_{};

Program ProgramSingleton::program_(
  ProgramSingleton::graphics_engine_,
  ProgramSingleton::window_utility_
);
}  // namespace soup
