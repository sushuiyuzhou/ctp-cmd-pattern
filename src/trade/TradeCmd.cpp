//
// Created by sushuiyuzhou on 21/10/18.
//
#include "TradeCmd.h"
#include "TradeSpi.h"

#include "../ctp/ThostFtdcUserApiStruct.h"
#include "../ctp/ThostFtdcUserApiDataType.h"
#include "../ctp/ThostFtdcTraderApi.h"

#include "../utils/ConsoleLogger.h"

namespace trade {

void LogInCmd::doExecute() {
  auto loginReq = std::make_unique<CThostFtdcReqUserLoginField>();

  TThostFtdcBrokerIDType brokerID = "9999";
  TThostFtdcInvestorIDType investerID = "";
  TThostFtdcPasswordType password = "";

  utils::getConsoleLogger()->info("invesntor id: ");
  scanf("%s", investerID);
  utils::getConsoleLogger()->info("password: ");
  scanf("%s", password);

  strcpy(loginReq->BrokerID, brokerID);
  strcpy(loginReq->UserID, investerID);
  strcpy(loginReq->Password, password);

  int rt = _api->ReqUserLogin(loginReq.get(), ++_reqID_);
  if (rt) {
    utils::getConsoleLogger()->error("Log in failed.");
  }
}

void ReqQrySettlementInfoCmd::doExecute() {
  utils::getConsoleLogger()->info(BOOST_CURRENT_FUNCTION);

  auto qrySettlementInfoField = std::make_unique<CThostFtdcQrySettlementInfoField>();

  strcpy(qrySettlementInfoField->BrokerID, _spi->_BrokerID);
  strcpy(qrySettlementInfoField->InvestorID, _spi->_InvestorID);
  std::cout << "query trading date " << _spi->_TradingDay << std::endl;
  strcpy(qrySettlementInfoField->TradingDay, _spi->_TradingDay);

  _api->ReqQrySettlementInfo(qrySettlementInfoField.get(), ++_reqID_);
}

void ReqSettlementInfoConfirmCmd::doExecute() {
  utils::getConsoleLogger()->info(BOOST_CURRENT_FUNCTION);
  auto qrySettlementInfoConfirmField
      = std::make_unique<CThostFtdcSettlementInfoConfirmField>();

  std::cout << "query using broker id: " << _spi->_BrokerID << std::endl
            << "investor ID: " << _spi->_InvestorID << std::endl;
  strcpy(qrySettlementInfoConfirmField->BrokerID, _spi->_BrokerID);
  strcpy(qrySettlementInfoConfirmField->InvestorID, _spi->_InvestorID);

  _api->ReqSettlementInfoConfirm(qrySettlementInfoConfirmField.get(), ++_reqID_);
}

void ReqOrderInsertCmd::doExecute() {
  utils::getConsoleLogger()->info(BOOST_CURRENT_FUNCTION);

  auto qryOrderInsert = std::make_unique<CThostFtdcInputOrderField>();
}

}
