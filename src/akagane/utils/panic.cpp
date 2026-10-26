#include "panic.hpp"

namespace Akagane {

void endless() {
  // 空無限ループによる未定義動作対策
  volatile bool tmp;
  while (true) {
    tmp = !tmp;
  }
}

} // namespace Akagane
