//
// Created by sushuiyuzhou on 21/10/18.
//

#include "StrategyInvoker.h"
#include "./TradeCmd.h"

namespace trade {

void StrategyInvoker::invoke(CMD cmd) {
  switch (cmd) {
    case CMD::LogIn :
      trade::LogInCmd(_api, _spi).execute();
      break;
  }
}
void StrategyInvoker::askThenInvoke() {
  // Could ask user for options here.
}

}
