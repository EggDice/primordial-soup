#include <vector>

class RenderBuffer {
  public:
    RenderBuffer(int size);
    std::vector<void *> GetQuadBuffer();
};
