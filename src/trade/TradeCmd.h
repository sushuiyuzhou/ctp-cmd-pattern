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

enum class CMD {
  LogIn,
  LogOut,
  RequestSettlement
};

class Command {
protected:
  // action executor
  CThostFtdcTraderApi *_api;
  CThostFtdcTraderSpi *_spi;

public:
  Command(CThostFtdcTraderApi *api,
          CThostFtdcTraderSpi *spi) :
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

  void doExecute() override {
    // make sure the function call is working.
    std::cout << "api version: " << _api->GetApiVersion() << std::endl;
  }

public:
  LogInCmd(CThostFtdcTraderApi *api,
           CThostFtdcTraderSpi *spi) : Command(api, spi) {
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
            CThostFtdcTraderSpi *spi) : Command(api, spi) {
  }
};

class RequestSettlementCmd : public Command {
  const char *name() override {
    return "<query settlement>";
  }

  void doExecute() override {
  }

public:
  RequestSettlementCmd(CThostFtdcTraderApi *api,
                       CThostFtdcTraderSpi *spi) : Command(api, spi) {
  }
};

}

#endif //CTP_CMD_TRADECMD_H
