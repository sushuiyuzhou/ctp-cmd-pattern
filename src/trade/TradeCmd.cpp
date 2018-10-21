//
// Created by sushuiyuzhou on 21/10/18.
//
#include "TradeCmd.h"

#include "../ctp/ThostFtdcUserApiStruct.h"
#include "../ctp/ThostFtdcUserApiDataType.h"
#include "../ctp/ThostFtdcTraderApi.h"

#include "../utils/ConsoleLogger.h"

namespace trade {

void LogInCmd::doExecute() {
  // make sure the function call is working.
  std::cout << "api version: " << _api->GetApiVersion() << std::endl;
  CThostFtdcReqUserLoginField loginReq;
  memset(&loginReq, 0, sizeof(loginReq));

  TThostFtdcBrokerIDType brokerID = "9999";
  TThostFtdcInvestorIDType investerID = "";
  TThostFtdcPasswordType password = "";

  utils::getConsoleLogger()->info("invesntor id: ");
  scanf("%s", investerID);
  utils::getConsoleLogger()->info("password: ");
  scanf("%s", password);

  strcpy(loginReq.BrokerID, brokerID);
  strcpy(loginReq.UserID, investerID);
  strcpy(loginReq.Password, password);

  int rt = _api->ReqUserLogin(&loginReq, 0);
  if (rt) {
    utils::getConsoleLogger()->error("Log in failed.");
  }
}

}
