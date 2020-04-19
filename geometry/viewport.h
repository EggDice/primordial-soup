#ifndef GEOMETRY_VIEWPORT_H_
#define GEOMETRY_VIEWPORT_H_

#include <cstdint>

namespace soup {
namespace geometry {

struct Viewport {
  uint64_t width;
  uint64_t height;
  bool operator==(const Viewport& other) const;
};

}  // namespace geometry
}  // namespace soup

#endif  // GEOMETRY_VIEWPORT_H_
