#ifndef GEOMETRY_CUBE_EDGES_H_
#define GEOMETRY_CUBE_EDGES_H_

#include "line.h"

namespace soup {
namespace geometry {

struct CubeEdges {
  Line edges[12];
};

}  // namespace geometry
}  // namespace soup

#endif  // GEOMETRY_CUBE_EDGES_H_
