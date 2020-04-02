#include "render-buffer.h"

namespace soup {
namespace render_system {

RenderBuffer::RenderBuffer(int size) {}

std::vector<void *> RenderBuffer::GetCubeBuffer() {
  std::vector<void *> cube_buffer_;
  cube_buffer_.reserve(1);
  return cube_buffer_;
}

std::vector<void *> RenderBuffer::GetQuadBuffer() {
  std::vector<void *> quad_buffer_;
  quad_buffer_.reserve(quad_per_buffer);
  return quad_buffer_;
}

}  // namespace render_system
}  // namespace soup
