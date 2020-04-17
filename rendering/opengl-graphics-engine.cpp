#include "opengl-graphics-engine.h"

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <glm/gtc/type_ptr.hpp>


namespace soup {
namespace rendering {

void OpenGlGraphicsEngine::Init() const {
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_NORMALIZE);
  glEnable(GL_COLOR_MATERIAL);
}

void OpenGlGraphicsEngine::SetupScene() const {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void OpenGlGraphicsEngine::TearDownScene() const {
  glutSwapBuffers();
}

void OpenGlGraphicsEngine::
    DrawQuads(const std::vector<geometry::Quad>& quads) const {
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

void OpenGlGraphicsEngine::
    DrawLines(const std::vector<geometry::Line>& lines) const {
  glBegin(GL_LINES);
  for (auto& line : lines) {
    glColor3fv(glm::value_ptr(line.color));
    glNormal3fv(glm::value_ptr(line.normal));
    for (uint8_t i = 0; i < 2; ++i) {
      glVertex3fv(glm::value_ptr(line.vertices[i]));
    }
  }
  glEnd();
}


void OpenGlGraphicsEngine::
    PlaceCamera(const geometry::Transform& t) const {
  glTranslatef(t.translate[0], t.translate[1], t.translate[2]);
  glRotatef(t.rotate_x[0], t.rotate_x[1], t.rotate_x[2], t.rotate_x[3]);
  glRotatef(t.rotate_y[0], t.rotate_y[1], t.rotate_y[2], t.rotate_y[3]);
}

void OpenGlGraphicsEngine::RenderAmbientLight(const glm::vec4& color) const {
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, glm::value_ptr(color));
}

void OpenGlGraphicsEngine::RenderDiffuseLight(const glm::vec4& color,
                                              const glm::vec4& position) const {
  glLightfv(GL_LIGHT0, GL_DIFFUSE, glm::value_ptr(color));
  glLightfv(GL_LIGHT0, GL_POSITION, glm::value_ptr(position));
}

}  // namespace rendering
}  // namespace soup


