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

}  // namespace window
}  // namespace soup
