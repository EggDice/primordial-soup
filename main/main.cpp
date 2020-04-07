#include <iostream>
#include <vector>
#include <cstdint>
#include <cstdlib>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "../render_system/cube.h"

const float BOX_RADIUS = 0.5f;
const float WORLD_RADIUS = 20.0f;
int ROTATION_STEP = 5;
float _angleX = 0;
float _angleY = 0;

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
		case 27: //Escape key
			exit(0);
      break;
	}
}

void handleArrows(int key, int x, int y) {
  switch (key) {
    case GLUT_KEY_UP:
      _angleX = float ((360 + (int) _angleX + ROTATION_STEP) % 360);
      break;
    case GLUT_KEY_DOWN:
      _angleX = float ((360 + (int) _angleX - ROTATION_STEP) % 360);
      break;
    case GLUT_KEY_LEFT:
      _angleY = float ((360 + (int) _angleY + ROTATION_STEP) % 360);
      break;
    case GLUT_KEY_RIGHT:
      _angleY = float ((360 + (int) _angleY - ROTATION_STEP) % 360);
      break;
  }
}

void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -80.0f);

	GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

	GLfloat lightColor[] = {0.7f, 0.7f, 0.7f, 1.0f};
	GLfloat lightPos[] = {-2 * WORLD_RADIUS, WORLD_RADIUS, 4 * WORLD_RADIUS, 1.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

  glRotatef(-_angleX, 1.0f, 0.0f, 0.0f);
	glRotatef(-_angleY, 0.0f, 1.0f, 0.0f);

  soup::render_system::Cube world({0.0f, 0.0f, 0.0f}, WORLD_RADIUS, {0.0f, 1.0f, 1.0f});
  soup::render_system::Cube cube({0.0f, 0.0f, 0.0f}, BOX_RADIUS, {1.0f, 1.0f, 0.0f});

  auto quads = cube.Render<soup::render_system::Quad>();

	glBegin(GL_QUADS);
  for (auto & quad : quads) {
    glColor3fv(glm::value_ptr(quad.color));
    glNormal3fv(glm::value_ptr(quad.normal));
	  glVertex3fv(glm::value_ptr(quad.vertices[0]));
	  glVertex3fv(glm::value_ptr(quad.vertices[1]));
	  glVertex3fv(glm::value_ptr(quad.vertices[2]));
	  glVertex3fv(glm::value_ptr(quad.vertices[3]));
  }
  glEnd();

	glBegin(GL_LINES);
	for (auto & line : world.Render<soup::render_system::Line>()) {
	  glColor3fv(glm::value_ptr(line.color));
	  glVertex3fv(glm::value_ptr(line.vertices[0]));
	  glVertex3fv(glm::value_ptr(line.vertices[1]));
  }
  glEnd();

	glutSwapBuffers();
}

void update(int value) {
	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);

	glutCreateWindow("Primordial Soup");
	initRendering();

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutSpecialFunc(handleArrows);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);

	glutMainLoop();
	return 0;
}









