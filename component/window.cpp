#include "window.h"

namespace soup {
namespace component {

bool Window::operator==(const Window& other) const {
  return is_exit == other.is_exit &&
    name == other.name;
}


}  // namespace component
}  // namespace soup
