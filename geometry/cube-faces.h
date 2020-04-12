#ifndef GEOMETRY_CUBE_FACES_H_
#define GEOMETRY_CUBE_FACES_H_

#include "quad.h"

namespace soup {
namespace geometry {

struct CubeFaces {
  Quad faces[6];
};

}  // namespace geometry
}  // namespace soup

#endif  // GEOMETRY_CUBE_FACES_H_
