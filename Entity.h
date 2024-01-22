#include <cstdint>

class Entity {

  protected:
    int64_t hp;
    int64_t x;
    int64_t y;

  public:
    Entity(int64_t hp, int64_t x, int64_t y);
};
