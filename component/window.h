#ifndef COMPONENT_WINDOW_H_
#define COMPONENT_WINDOW_H_

#include <string>

namespace soup {
namespace component {

struct Window {
  std::string name;
  bool is_exit;
  bool operator==(const Window& other) const;
};

}  // namespace component
}  // namespace soup

#endif  // COMPONENT_WINDOW_H_
