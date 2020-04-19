#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "glut-window-utility.h"

namespace soup {
namespace window {

void GlutWindowUtility::Init(int * argcp,
                             char **argv,
                             const component::RenderViewport& viewport,
                             const component::Window& window) const {
  glutInit(argcp, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(viewport.width, viewport.height);
  glutCreateWindow(window.name.c_str());
}

void GlutWindowUtility::Exit() const {
  exit(EXIT_SUCCESS);
}

void GlutWindowUtility::RegisterKeyboardFunction(void (*func)(unsigned char key,
                                                    int x, int y)) const {
  glutKeyboardFunc(func);
}

void GlutWindowUtility::RegisterKeyboardSpecialFunction(void (*func)(int key,
                                                           int x,
                                                           int y)) const {
  glutSpecialFunc(func);
}

void GlutWindowUtility::RegisterResizeFunction(void (*func)(int width,
                                                            int height)) const {
  glutReshapeFunc(func);
}

void GlutWindowUtility::RegisterMouseFunction(void (*func)(int button,
                                                 int state,
                                                 int x, int y)) const {
  glutMouseFunc(func);
}

void GlutWindowUtility::RegisterDisplayFunction(void (*func)(void)) const {
  glutDisplayFunc(func);
}

void GlutWindowUtility::RegisterTickFunc(void (*func)(int value)) const {
  glutTimerFunc(GlutWindowUtility::tick_time, func, 0);
}

void GlutWindowUtility::StartMainLoop() const {
  glutMainLoop();
}

void GlutWindowUtility::PostRedisplay() const {
  glutPostRedisplay();
}

const uint64_t GlutWindowUtility::tick_time = 25;

}  // namespace window
}  // namespace soup
