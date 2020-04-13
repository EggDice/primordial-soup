#ifndef EVENT_TIMER_H_
#define EVENT_TIMER_H_

#include <cstdint>
#include <ctime>
#include <ratio>
#include <chrono>

namespace soup {
namespace event {

typedef std::chrono::time_point<std::chrono::steady_clock> Timestamp;

class Timer {
 public:
  static Timestamp Now();
  static uint64_t GetDuration(Timestamp before, Timestamp now);
};

}  // namespace event
}  // namespace soup

#endif  // EVENT_TIMER_H_
