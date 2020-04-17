#include "window.h"

namespace soup {
namespace component {

bool Window::operator==(const Window& other) const {
  return width == other.width &&
    height == other.height &&
    name == other.name;
}


}  // namespace component
}  // namespace soup
