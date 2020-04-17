#ifndef COMPONENT_WINDOW_H_
#define COMPONENT_WINDOW_H_

#include <string>

namespace soup {
namespace component {

struct Window {
  uint64_t width;
  uint64_t height;
  std::string name;
  bool operator==(const Window& other) const;
};

}  // namespace component
}  // namespace soup

#endif  // COMPONENT_WINDOW_H_
