#include "../ctp/ThostFtdcTraderApi.h"
#include "../ctp/ThostFtdcUserApiDataType.h"
#include "../ctp/ThostFtdcUserApiStruct.h"

#include "../utils/ConsoleLogger.h"

namespace order {

enum class OrderType {
  TEST
};

  // OrderFactory needs to know about market + strategy.
class OrderFactory {};

} // namespace order
