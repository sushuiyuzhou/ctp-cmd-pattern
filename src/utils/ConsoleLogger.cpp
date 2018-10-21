//
// Created by sushuiyuzhou on 21/10/18.
//

#include "ConsoleLogger.h"

#include <memory>

namespace utils {

spdlog::logger *getConsoleLogger() {
  static auto logger = spdlog::stdout_color_mt("ctp-cmd");
  return logger.get();
}

}
