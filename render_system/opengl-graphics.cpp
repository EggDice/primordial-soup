#include "opengl-graphics.h"

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <glm/gtc/type_ptr.hpp>


namespace soup {
namespace render_system {

void OpenGlGraphics::Init() {
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_NORMALIZE);
  glEnable(GL_COLOR_MATERIAL);
}

void OpenGlGraphics::SetupScene() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void OpenGlGraphics::TearDownScene() {
  glutSwapBuffers();
}

void OpenGlGraphics::DrawQuads(const std::vector<Quad>& quads) const {
  glBegin(GL_QUADS);
  for (auto& quad : quads) {
    glColor3fv(glm::value_ptr(quad.color));
    glNormal3fv(glm::value_ptr(quad.normal));
    for (uint8_t i = 0; i < 4; ++i) {
      glVertex3fv(glm::value_ptr(quad.vertices[i]));
    }
  }
  glEnd();
}

void OpenGlGraphics::DrawLines(const std::vector<Line>& lines) const {
  glBegin(GL_LINES);
  for (auto& line : lines) {
    glColor3fv(glm::value_ptr(line.color));
    for (uint8_t i = 0; i < 2; ++i) {
      glVertex3fv(glm::value_ptr(line.vertices[i]));
    }
  }
  glEnd();
}

}  // namespace render_system
}  // namespace soup


