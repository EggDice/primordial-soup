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

const float BOX_SIZE = 1.0f;
const float WORLD_RADIUS = 20.0f;
int ROTATION_STEP = 5;
float _angleX = 0;
float _angleY = 0;

struct Cube {
  glm::vec3 position;
  glm::vec3 color;
};

class Element {
  public:
    glm::ivec3 position;
    glm::ivec3 velocity;

    Cube renderToCube() {
      return {position, {1.0f, 1.0f, 1.0f}};
    }

    void move() {
      if (std::abs(position[0] + velocity[0]) > WORLD_RADIUS) {
        velocity[0] *= -1;
      }
      if (std::abs(position[1] + velocity[1]) > WORLD_RADIUS) {
        velocity[1] *= -1;
      }
      if (std::abs(position[2] + velocity[2]) > WORLD_RADIUS) {
        velocity[2] *= -1;
      }
      position += velocity;
    }
};

void renderCube(Cube cube);
void renderWorld();

Element movingElement = {{1, 1, 1}, {2, 3, 1}};
Cube movingCube = {{0, 0, 0}, {1.0f, 0.0f, 0.0f}};

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
	GLfloat lightPos[] = {-2 * BOX_SIZE, BOX_SIZE, 4 * BOX_SIZE, 1.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

  glRotatef(-_angleX, 1.0f, 0.0f, 0.0f);
	glRotatef(-_angleY, 0.0f, 1.0f, 0.0f);

  std::vector<Cube> cubes = {
    {{0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 0.0f}},
    {{2.0f, 2.0f, -2.0f}, {0.0f, 1.0f, 0.0f}},
    {{0.0f, 2.0f, 0.0f}, {0.0f, 1.0f, 1.0f}},
    {{0.0f, 0.0f, -2.0f}, {0.0f, 0.0f, 1.0f}},
    {{2.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 1.0f}},
  };

  for (auto &c : cubes) {
    renderCube(c);
  }
  renderCube(movingCube);
  renderWorld();

	glutSwapBuffers();
}

void renderCube(Cube cube) {
	glBegin(GL_QUADS);
  float x = cube.position[0];
  float y = cube.position[1];
  float z = cube.position[2];

	//Top face
	glColor3fv(glm::value_ptr(cube.color));
	glNormal3f(0.0, 1.0f, 0.0f);
	glVertex3f(x - BOX_SIZE / 2, y + BOX_SIZE / 2, z - BOX_SIZE / 2);
	glVertex3f(x - BOX_SIZE / 2, y + BOX_SIZE / 2, z + BOX_SIZE / 2);
	glVertex3f(x + BOX_SIZE / 2, y + BOX_SIZE / 2, z + BOX_SIZE / 2);
	glVertex3f(x + BOX_SIZE / 2, y + BOX_SIZE / 2, z - BOX_SIZE / 2);

	//Bottom face
	glNormal3f(0.0, -1.0f, 0.0f);
	glVertex3f(x - BOX_SIZE / 2, y - BOX_SIZE / 2, z - BOX_SIZE / 2);
	glVertex3f(x + BOX_SIZE / 2, y - BOX_SIZE / 2, z - BOX_SIZE / 2);
	glVertex3f(x + BOX_SIZE / 2, y - BOX_SIZE / 2, z + BOX_SIZE / 2);
	glVertex3f(x - BOX_SIZE / 2, y - BOX_SIZE / 2, z + BOX_SIZE / 2);

	//Left face
	glNormal3f(-1.0, 0.0f, 0.0f);
	glVertex3f(x - BOX_SIZE / 2, y - BOX_SIZE / 2, z - BOX_SIZE / 2);
	glVertex3f(x - BOX_SIZE / 2, y - BOX_SIZE / 2, z + BOX_SIZE / 2);
	glVertex3f(x - BOX_SIZE / 2, y + BOX_SIZE / 2, z + BOX_SIZE / 2);
	glVertex3f(x - BOX_SIZE / 2, y + BOX_SIZE / 2, z - BOX_SIZE / 2);

	//Right face
	glNormal3f(1.0, 0.0f, 0.0f);
	glVertex3f(x + BOX_SIZE / 2, y - BOX_SIZE / 2, z - BOX_SIZE / 2);
	glVertex3f(x + BOX_SIZE / 2, y + BOX_SIZE / 2, z - BOX_SIZE / 2);
	glVertex3f(x + BOX_SIZE / 2, y + BOX_SIZE / 2, z + BOX_SIZE / 2);
	glVertex3f(x + BOX_SIZE / 2, y - BOX_SIZE / 2, z + BOX_SIZE / 2);

	//Front face
	glNormal3f(0.0, 0.0f, 1.0f);
	glVertex3f(x - BOX_SIZE / 2, y - BOX_SIZE / 2, z + BOX_SIZE / 2);
	glVertex3f(x + BOX_SIZE / 2, y - BOX_SIZE / 2, z + BOX_SIZE / 2);
	glVertex3f(x + BOX_SIZE / 2, y + BOX_SIZE / 2, z + BOX_SIZE / 2);
	glVertex3f(x - BOX_SIZE / 2, y + BOX_SIZE / 2, z + BOX_SIZE / 2);

	//Back face
	glNormal3f(0.0, 0.0f, -1.0f);
	glVertex3f(x - BOX_SIZE / 2, y - BOX_SIZE / 2, z - BOX_SIZE / 2);
	glVertex3f(x - BOX_SIZE / 2, y + BOX_SIZE / 2, z - BOX_SIZE / 2);
	glVertex3f(x + BOX_SIZE / 2, y + BOX_SIZE / 2, z - BOX_SIZE / 2);
	glVertex3f(x + BOX_SIZE / 2, y - BOX_SIZE / 2, z - BOX_SIZE / 2);

	glEnd();
}

void renderWorld() {
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
  glVertex3f(WORLD_RADIUS, WORLD_RADIUS, WORLD_RADIUS);
  glVertex3f(-WORLD_RADIUS, WORLD_RADIUS, WORLD_RADIUS);
	glEnd();
	glBegin(GL_LINES);
  glVertex3f(-WORLD_RADIUS, WORLD_RADIUS, WORLD_RADIUS);
  glVertex3f(-WORLD_RADIUS, -WORLD_RADIUS, WORLD_RADIUS);
	glEnd();
	glBegin(GL_LINES);
  glVertex3f(-WORLD_RADIUS, -WORLD_RADIUS, WORLD_RADIUS);
  glVertex3f(WORLD_RADIUS, -WORLD_RADIUS, WORLD_RADIUS);
	glEnd();
	glBegin(GL_LINES);
  glVertex3f(WORLD_RADIUS, -WORLD_RADIUS, WORLD_RADIUS);
  glVertex3f(WORLD_RADIUS, WORLD_RADIUS, WORLD_RADIUS);
	glEnd();

	glBegin(GL_LINES);
  glVertex3f(WORLD_RADIUS, WORLD_RADIUS, -WORLD_RADIUS);
  glVertex3f(-WORLD_RADIUS, WORLD_RADIUS, -WORLD_RADIUS);
	glEnd();
	glBegin(GL_LINES);
  glVertex3f(-WORLD_RADIUS, WORLD_RADIUS, -WORLD_RADIUS);
  glVertex3f(-WORLD_RADIUS, -WORLD_RADIUS, -WORLD_RADIUS);
	glEnd();
	glBegin(GL_LINES);
  glVertex3f(-WORLD_RADIUS, -WORLD_RADIUS, -WORLD_RADIUS);
  glVertex3f(WORLD_RADIUS, -WORLD_RADIUS, -WORLD_RADIUS);
	glEnd();
	glBegin(GL_LINES);
  glVertex3f(WORLD_RADIUS, -WORLD_RADIUS, -WORLD_RADIUS);
  glVertex3f(WORLD_RADIUS, WORLD_RADIUS, -WORLD_RADIUS);
	glEnd();

	glBegin(GL_LINES);
  glVertex3f(WORLD_RADIUS, WORLD_RADIUS, WORLD_RADIUS);
  glVertex3f(WORLD_RADIUS, WORLD_RADIUS, -WORLD_RADIUS);
	glEnd();
	glBegin(GL_LINES);
  glVertex3f(-WORLD_RADIUS, WORLD_RADIUS, WORLD_RADIUS);
  glVertex3f(-WORLD_RADIUS, WORLD_RADIUS, -WORLD_RADIUS);
	glEnd();
	glBegin(GL_LINES);
  glVertex3f(WORLD_RADIUS, -WORLD_RADIUS, WORLD_RADIUS);
  glVertex3f(WORLD_RADIUS, -WORLD_RADIUS, -WORLD_RADIUS);
	glEnd();
	glBegin(GL_LINES);
  glVertex3f(-WORLD_RADIUS, -WORLD_RADIUS, WORLD_RADIUS);
  glVertex3f(-WORLD_RADIUS, -WORLD_RADIUS, -WORLD_RADIUS);
	glEnd();
}

void update(int value) {
	glutPostRedisplay();
  movingElement.move();
  movingCube = movingElement.renderToCube();
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









