//
// Created by sushuiyuzhou on 21/10/18.
//
#ifndef CTP_CMD_STRATEGYINVOKER_H
#define CTP_CMD_STRATEGYINVOKER_H

#include "./TradeCmd.h"

#include "../ctp/ThostFtdcUserApiStruct.h"
#include "../ctp/ThostFtdcUserApiDataType.h"

#include "../ctp/ThostFtdcTraderApi.h"
#include "../spdlog/logger.h"

namespace trade {

class StrategyInvoker {
  // action executor
  CThostFtdcTraderApi *_api;
  CThostFtdcTraderSpi *_spi;

public:
  StrategyInvoker(CThostFtdcTraderApi *api,
                  CThostFtdcTraderSpi *spi) :
      _api(api),
      _spi(spi) {}

  void invoke(CMD cmd);

  void askThenInvoke();
};

}

#endif //CTP_CMD_STRATEGYINVOKER_H
