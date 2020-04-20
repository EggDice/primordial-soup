#include <gtest/gtest.h>

#include <vector>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#include "program.h"
#include "../window/mock-window-utility.h"
#include "../rendering/mock-graphics-engine.h"

namespace {
namespace w = soup::window;
namespace r = soup::rendering;

using ::testing::_;
using ::testing::NiceMock;

TEST(Program, ExitOnEsc) {
  auto graphics_engine = NiceMock<r::MockGraphicsEngine>();
  auto window_utility = NiceMock<w::MockWindowUtility>();
  auto program = soup::Program(graphics_engine, window_utility);

  EXPECT_CALL(window_utility, Exit())
    .Times(1);

  auto ESC = 27;
  program.Init(0, {});
  program.HandleKeypress(ESC, 0, 0);
  program.HandleTick(0);
}

TEST(Program, RerenderViewportOnResize) {
  auto graphics_engine = NiceMock<r::MockGraphicsEngine>();
  auto window_utility = NiceMock<w::MockWindowUtility>();
  auto program = soup::Program(graphics_engine, window_utility);


  EXPECT_CALL(graphics_engine, RenderViewport(800, 600))
    .Times(1);

  program.Init(0, {});
  program.HandleResize(800, 600);
  program.HandleTick(0);
  program.HandleDisplay();
}

TEST(Program, RotateOnArrow) {
  auto graphics_engine = NiceMock<r::MockGraphicsEngine>();
  auto window_utility = NiceMock<w::MockWindowUtility>();
  auto program = soup::Program(graphics_engine, window_utility);

  std::vector<float> rotate_x, rotate_y;

  ON_CALL(graphics_engine, PlaceCamera(_))
    .WillByDefault([&rotate_x, &rotate_y](const auto& t) {
        rotate_x.push_back(t.rotate_x[0]);
        rotate_y.push_back(t.rotate_y[0]);
      });

  program.Init(0, {});
  program.HandleTick(0);
  program.HandleDisplay();

  program.HandleSpecialKeypress(GLUT_KEY_RIGHT, 0, 0);
  program.HandleSpecialKeypress(GLUT_KEY_UP, 0, 0);
  program.HandleTick(0);
  program.HandleDisplay();

  program.HandleSpecialKeypress(GLUT_KEY_RIGHT, 0, 0);
  program.HandleSpecialKeypress(GLUT_KEY_UP, 0, 0);
  program.HandleTick(0);
  program.HandleDisplay();

  EXPECT_TRUE(rotate_x[0] < rotate_x[1]);
  EXPECT_TRUE(rotate_y[0] < rotate_y[1]);
  EXPECT_TRUE(rotate_x[1] < rotate_x[2]);
  EXPECT_TRUE(rotate_y[1] < rotate_y[2]);
}

}  // namespace
