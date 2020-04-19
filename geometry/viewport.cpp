#include "viewport.h"

namespace soup {
namespace geometry {

bool Viewport::operator==(const Viewport& other) const {
  return width == other.width &&
    height == other.height;
}


}  // namespace geometry
}  // namespace soup
