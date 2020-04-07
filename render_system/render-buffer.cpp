#include "render-buffer.h"

#include <algorithm>

namespace soup {
namespace render_system {

template <class T>
RenderBuffer<T>::RenderBuffer(uint64_t size) : size_(size) {
  if (std::is_same<T, Quad>::value) {
    cube_to_buffer_ratio_ = 6;
  }
  if (std::is_same<T, Line>::value) {
    cube_to_buffer_ratio_ = 12;
  }
  out_buffer_.reserve(cube_to_buffer_ratio_ * size_);
}

template <class T>
const std::vector<T>& RenderBuffer<T>::GetBuffer() {
  return out_buffer_;
}

template <class T>
void RenderBuffer<T>::AddCube(Cube c) {
  cube_buffer_.push_back(c);
}

template <class T>
void RenderBuffer<T>::Render() {
  for (auto& cube : cube_buffer_) {
    auto quads_to_add = cube.Render<T>();
    out_buffer_.insert(out_buffer_.end(),
                      quads_to_add.begin(),
                      quads_to_add.end());
  }
}

template <class T>
void RenderBuffer<T>::Clear() {
  cube_buffer_.clear();
  out_buffer_.clear();
}
}  // namespace render_system
}  // namespace soup
