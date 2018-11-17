// Created by sushuiyuzou
// Sat 17 Nov 22:37:49 GMT 2018
#idndef CTP_MARKET_CMD_H
#define CTP_MARKET_CMD_H

#include "./MarketSpi.h"

#include "../ctp/ThostFtdcMdApi.h"
#include "../ctp/ThostFtdcUserApiDataType.h"
#include "../ctp/ThostFtdcUserApiStruct.h"

#include "../spdlog/logger.h"

namespace market {

class CMD;

enum class CMD {
  // API commands
  CreateFtdcMdApi,
  GetApiVersion,
  Release,
  Init,
  Join,
  GetTradingDay,
  RegisterFront,
  RegisterNameServer,
  RegisterFensUserInfo,
  RegisterSpi,
  SubscribeMarketData,
  UnSubscribeMarketData,
  SubscribeForQuoteRsp,
  UnSubscribeForQuoteRsp,
  ReqUserLogin,
  ReqUserLogout
}

class CmdInvoker {
  // action exeturos
  CThostFtdcMdApi *_api;
  MarketSpi *_spi;

public:
  CmdInvoker(CThostFtdcMdApi *api, MarketSpi *spi) : _api(api), _spi(spi) {}
  void invode(CMD cmd);
};

} // namespace market

#endif
