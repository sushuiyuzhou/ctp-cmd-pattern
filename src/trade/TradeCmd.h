//
// Created by sushuiyuzhou on 21/10/18.
//
#ifndef CTP_CMD_TRADECMD_H
#define CTP_CMD_TRADECMD_H

#include "../ctp/ThostFtdcUserApiStruct.h"
#include "../ctp/ThostFtdcUserApiDataType.h"
#include "../ctp/ThostFtdcTraderApi.h"

#include "../utils/CVT.h"
#include "../utils/ConsoleLogger.h"

#include <boost/current_function.hpp>

#include <string>
#include <iostream>

namespace trade {

class TradeSpi;

static int _reqID_ = 0;

enum class CMD {
  LogIn,
  LogOut,
  ReqQrySettlementInfo
};

class Command {
protected:
  // action executor
  CThostFtdcTraderApi *_api;
  TradeSpi *_spi;

public:
  Command(CThostFtdcTraderApi *api,
          TradeSpi *spi) :
      _api(api),
      _spi(spi) {};

  void execute() {
    utils::getConsoleLogger()->info("Execute command: {}", name());
    doExecute();
  }

private:
  virtual const char *name() = 0;
  virtual void doExecute() = 0;
};

class LogInCmd : public Command {
  const char *name() override {
    return "<log in>";
  }

  void doExecute() override;

public:
  LogInCmd(CThostFtdcTraderApi *api,
           TradeSpi *spi) : Command(api, spi) {
  }
};

class LogOutCmd : public Command {
  const char *name() override {
    return "<log out>";
  }

  void doExecute() override {
  }

public:
  LogOutCmd(CThostFtdcTraderApi *api,
            TradeSpi *spi) : Command(api, spi) {
  }
};

class ReqQrySettlementInfoCmd : public Command {
  const char *name() override {
    return "<ReqQrySettlementInfo>";
  }

  void doExecute() override;

public:
  ReqQrySettlementInfoCmd(CThostFtdcTraderApi *api,
                       TradeSpi *spi) : Command(api, spi) {
  }
};

}

#endif //CTP_CMD_TRADECMD_H
