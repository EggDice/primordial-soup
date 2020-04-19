#include "program.h"

#include <glm/glm.hpp>

#include "../component/position.h"
#include "../component/radius.h"
#include "../component/rotation.h"
#include "../component/color.h"
#include "../component/render-cube-faces.h"
#include "../component/render-cube-edges.h"
#include "../component/render-camera.h"
#include "../component/control-keyboard-rotate.h"
#include "../component/control-resize.h"
#include "../component/control-exit.h"
#include "../component/render-ambient-light.h"
#include "../component/render-diffuse-light.h"
#include "../component/window.h"
#include "../component/render-viewport.h"
#include "../window/glut-connector.h"

namespace soup {

Program::Program() :
  graphics_(),
  graphics_system_(graphics_),
  render_system_(),
  input_system_(),
  control_system_(),
  window_utility_(),
  window_system_(window_utility_) {}

void Program::Init(int argc, char** argv) {
  auto window_entity = registry_.create();
  auto window = component::Window{"Primordial Soup", false};
  registry_.assign<component::Window>(window_entity, window);
  auto viewport = component::RenderViewport{400, 400};
  registry_.assign<component::RenderViewport>(window_entity, viewport);
  auto control_resize = component::ControlResize{};
  registry_.assign<component::ControlResize>(window_entity, control_resize);
  auto control_exit = component::ControlExit{event::ESC_KEY};
  registry_.assign<component::ControlExit>(window_entity, control_exit);

  auto world_entity = registry_.create();
  registry_.assign<component::Position>(world_entity,
                                        glm::vec3(0.0f, 0.0f, 0.0f));
  registry_.assign<component::Radius>(world_entity, 20.0f);
  registry_.assign<component::Color>(world_entity, glm::vec3(0.0f, 1.0f, 0.0f));
  registry_.assign<component::RenderCubeEdges>(world_entity,
                                               component::RenderCubeEdges{});

  auto element_entity = registry_.create();
  registry_.assign<component::Position>(element_entity,
                                        glm::vec3(0.0f, 0.0f, 0.0f));
  registry_.assign<component::Radius>(element_entity, 0.5f);
  registry_.assign<component::Color>(element_entity,
                                     glm::vec3(1.0f, 0.0f, 1.0f));
  registry_.assign<component::RenderCubeFaces>(element_entity,
                                               component::RenderCubeFaces{});

  auto camera_entity = registry_.create();
  registry_.assign<component::Position>(camera_entity,
                                        glm::vec3(0.0f, 0.0f, 80.0f));
  registry_.assign<component::Rotation>(camera_entity,
                                        component::Rotation{10.0f, 20.0f});
  registry_.assign<component::RenderCamera>(camera_entity,
                                            component::RenderCamera{});

  auto ambient_light_entity = registry_.create();
  auto ambient_light = component::RenderAmbientLight{
    glm::vec4(0.3f, 0.3f, 0.3f, 1.0f)
  };
  registry_.assign<component::RenderAmbientLight>(ambient_light_entity,
                                                  ambient_light);

  auto diffuse_light_entity = registry_.create();
  auto diffuse_light = component::RenderDiffuseLight{
    glm::vec4(0.8f, 0.8f, 0.8f, 1.0f),
    glm::vec4(-60.0f, 0.0f, 60.0f, 1.0f)
  };
  registry_.assign<component::RenderDiffuseLight>(diffuse_light_entity,
                                                  diffuse_light);

  auto keyboard_rotate = component::ControlKeyBoardRotate{{
    {event::ARROW_RIGHT_KEY, {0.0f, 5.0f}},
    {event::ARROW_LEFT_KEY, {0.0f, -5.0f}},
    {event::ARROW_UP_KEY, {5.0f, 0.0f}},
    {event::ARROW_DOWN_KEY, {-5.0f, 0.0f}}
  }};
  registry_.assign<component::ControlKeyBoardRotate>(camera_entity,
                                                     keyboard_rotate);



  auto input_entity = registry_.create();
  registry_.assign<component::InputEvents>(input_entity,
                                           component::InputEvents{});

  window_system_.Init(registry_, &argc, argv);
  graphics_system_.Init();
}

void Program::HandleDisplay() {
  graphics_system_.Update(registry_, event::TickEvent{event::Timer::Now()});
}

void Program::HandleKeypress(unsigned char key, int x, int y) {
  auto event = event::KeyboardEvent{
    event::Timer::Now(),
    event::GlutKeyboardToKeyCode(key)
  };
  input_system_.Update(registry_, event);
}

void Program::HandleSpecialKeypress(int key, int x, int y) {
  auto event = event::KeyboardEvent{
    event::Timer::Now(),
    event::GlutSpecialKeyboardToKeyCode(key)
  };
  input_system_.Update(registry_, event);
}

void Program::HandleResize(int w, int h) {
  auto event = event::ResizeEvent{event::Timer::Now(), w, h};
  input_system_.Update(registry_, event);
}

void Program::HandleMouse(int button, int state, int x, int y) {}

void Program::HandleTick(int value) {
  auto tick = event::TickEvent{event::Timer::Now()};
  control_system_.Update(registry_, tick);
  render_system_.Update(registry_, tick);
  window_system_.Update(registry_, tick);
  window_utility_.PostRedisplay();
}

void Program::RegisterKeyboardFunction(void (*func)(unsigned char key,
                                                    int x, int y)) {
  window_utility_.RegisterKeyboardFunction(func);
}

void Program::RegisterKeyboardSpecialFunction(void (*func)(int key,
                                                           int x,
                                                           int y)) {
  window_utility_.RegisterKeyboardSpecialFunction(func);
}

void Program::RegisterResizeFunction(void (*func)(int width, int height)) {
  window_utility_.RegisterResizeFunction(func);
}

void Program::RegisterMouseFunction(void (*func)(int button,
                                                 int state,
                                                 int x, int y)) {
  window_utility_.RegisterMouseFunction(func);
}

void Program::RegisterDisplayFunction(void (*func)(void)) {
  window_utility_.RegisterDisplayFunction(func);
}

void Program::RegisterTickFunc(void (*func)(int value)) {
  window_utility_.RegisterTickFunc(func);
}

void Program::StartMainLoop() {
  window_utility_.StartMainLoop();
}

const uint64_t Program::tick_time = 25;
const char Program::name_[] = "Primordial Soup";
}  // namespace soup
