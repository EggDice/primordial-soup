#ifndef RENDER_SYSTEM_RENDER_BUFFER_H_
#define RENDER_SYSTEM_RENDER_BUFFER_H_

#include <vector>
#include <cstdint>

#include "cube.h"
#include "quad.h"
#include "line.h"

namespace soup {
namespace render_system {

template <class T>
class RenderBuffer {
 public:
  explicit RenderBuffer(uint64_t size);
  const std::vector<T>& GetBuffer();
  void AddCube(Cube c);
  void Render();
  void Clear();
 private:
  uint64_t size_;
  uint64_t cube_to_buffer_ratio_;
  std::vector<Cube> cube_buffer_;
  std::vector<T> out_buffer_;
};

template class RenderBuffer<Quad>;
template class RenderBuffer<Line>;

}  // namespace render_system
}  // namespace soup

#endif  // RENDER_SYSTEM_RENDER_BUFFER_H_
