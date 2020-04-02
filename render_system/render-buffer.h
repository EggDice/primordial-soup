#ifndef RENDER_SYSTEM_RENDER_BUFFER_H_
#define RENDER_SYSTEM_RENDER_BUFFER_H_

#include <vector>
#include <cstdint>

namespace soup {
namespace render_system {

class RenderBuffer {
 public:
  explicit RenderBuffer(int size);
  std::vector<void *> GetCubeBuffer();
  std::vector<void *> GetQuadBuffer();
 private:
  static const uint8_t quad_per_buffer = 6;
};

}  // namespace render_system
}  // namespace soup

#endif  // RENDER_SYSTEM_RENDER_BUFFER_H_
