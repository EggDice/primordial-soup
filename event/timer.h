#ifndef EVENT_TIMER_H_
#define EVENT_TIMER_H_

#include <cstdint>
#include <ctime>
#include <ratio>
#include <chrono>

namespace soup {
namespace event {

using Timestamp = std::chrono::time_point<std::chrono::steady_clock>;
using Milliseconds = std::chrono::milliseconds;

class Timer {
 public:
  static Timestamp Now();
  static uint64_t GetDuration(Timestamp before, Timestamp now);
};

}  // namespace event
}  // namespace soup

#endif  // EVENT_TIMER_H_
