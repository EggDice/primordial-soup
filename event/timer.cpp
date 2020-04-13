#include "timer.h"

namespace soup {
namespace event {

Timestamp Timer::Now() {
  return std::chrono::steady_clock::now();
}

uint64_t Timer::GetDuration(Timestamp before, Timestamp now) {
  auto diff = now - before;
  return std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
}

}  // namespace event
}  // namespace soup
