#include "program.h"

#include <glm/glm.hpp>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "../component/position.h"
#include "../component/radius.h"
#include "../component/rotation.h"
#include "../component/color.h"
#include "../component/render-cube-faces.h"
#include "../component/render-cube-edges.h"
#include "../component/render-camera.h"

namespace soup {

Program::Program() :
  angleX_(0),
  angleY_(0),
  graphics_(),
  graphics_system_(graphics_),
  render_system_() {}

void Program::Init(int argc, char** argv) {
  // TODO(EggDice) move to window entity and system
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(400, 400);
  glutCreateWindow(name_);

  graphics_.Init();
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
}

void Program::HandleDisplay() {
  graphics_.SetupScene();

  // TODO(EggDice): Move to render system and light entity
  GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
  GLfloat lightColor[] = {0.7f, 0.7f, 0.7f, 1.0f};
  GLfloat lightPos[] = {-2 * 20.0f, 20.0f, 4 * 20.0f, 1.0f};
  glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
  glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

  graphics_system_.Update(registry_, tick_time);

  graphics_.TearDownScene();
}

void Program::HandleKeypress(unsigned char key, int x, int y) {
  switch (key) {
    case 27:  // Escape key TODO(EggDice): to constant
      exit(0);
      break;
  }
}

void Program::HandleSpecialKeypress(int key, int x, int y) {
  // TODO(EggDice): Move to input system and camera entity
  switch (key) {
    case GLUT_KEY_UP:
      angleX_ = static_cast<float>((360 + static_cast<int>(angleX_) + 5) % 360);
      break;
    case GLUT_KEY_DOWN:
      angleX_ = static_cast<float>((360 + static_cast<int>(angleX_) - 5) % 360);
      break;
    case GLUT_KEY_LEFT:
      angleY_ = static_cast<float>((360 + static_cast<int>(angleY_) + 5) % 360);
      break;
    case GLUT_KEY_RIGHT:
      angleY_ = static_cast<float>((360 + static_cast<int>(angleY_) - 5) % 360);
      break;
  }
}

void Program::HandleResize(int w, int h) {
  // TODO(EggDice): Move to window entity and graphics
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0,
                 static_cast<float>(w) / static_cast<float>(h),
                 1.0,
                 200.0);
}

void Program::HandleMouse(int button, int state, int x, int y) {}

void Program::HandleTick(int value) {
  render_system_.Update(registry_, tick_time);
  glutPostRedisplay();
}

void Program::RegisterKeyboardFunction(void (*func)(unsigned char key,
                                                    int x, int y)) {
  glutKeyboardFunc(func);
}

void Program::RegisterKeyboardSpecialFunction(void (*func)(int key,
                                                           int x,
                                                           int y)) {
  glutSpecialFunc(func);
}

void Program::RegisterResizeFunction(void (*func)(int width, int height)) {
  glutReshapeFunc(func);
}

void Program::RegisterMouseFunction(void (*func)(int button,
                                                 int state,
                                                 int x, int y)) {
  glutMouseFunc(func);
}

void Program::RegisterDisplayFunction(void (*func)(void)) {
  glutDisplayFunc(func);
}

void Program::RegisterTickFunc(void (*func)(int value)) {
  glutTimerFunc(Program::tick_time, func, 0);
}

void Program::StartMainLoop() {
  glutMainLoop();
}

const uint64_t Program::tick_time = 25;
const char Program::name_[] = "Primordial Soup";
}  // namespace soup
