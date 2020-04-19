#ifndef EVENT_RESIZE_EVENT_H_
#define EVENT_RESIZE_EVENT_H_

#include "event.h"

namespace soup {
namespace event {

struct ResizeEvent : public Event {
  int width;
  int height;
};

}  // namespace event
}  // namespace soup

#endif  // EVENT_RESIZE_EVENT_H_
