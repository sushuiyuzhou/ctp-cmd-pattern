//
// Created by ssyz on Sat 17 Nov 00:19:39 GMT 2018
//
#ifndef CTP_CMD_MARKETSPI_H
#define CTP_CMD_MARKETSPI_H

#include "../ctp/ThostFtdcMdApi.h"
#include "../ctp/ThostFtdcUserApiDataType.h"
#include "../ctp/ThostFtdcUserApiStruct.h"

#include "../utils/CVT.h"
#include "../utils/ConsoleLogger.h"

#include <boost/current_function.hpp>

namespace market {

class MarketSpi : public CThostFtdcMdSpi {
  // action executor
  CThostFtdcMdApi *_pmd;

  // action invoker
  // StrategyInvoker _strategy;

  // external logger
  spdlog::logger *_logger;

  MarketSpi(CThostFtdcMdApi *mdApi, spdlog::logger *logger)
      : _pmd(mdApi), _logger(logger) {
    _logger->info(BOOST_CURRENT_FUNCTION);
  }

public:
  ///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
  void OnFrontConnected() override;

  ///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
  ///@param nReason 错误原因
  ///        0x1001 网络读失败
  ///        0x1002 网络写失败
  ///        0x2001 接收心跳超时
  ///        0x2002 发送心跳失败
  ///        0x2003 收到错误报文
  void OnFrontDisconnected(int nReason) override;

  ///心跳超时警告。当长时间未收到报文时，该方法被调用。
  ///@param nTimeLapse 距离上次接收报文的时间
  void OnHeartBeatWarning(int nTimeLapse) override;

  ///登录请求响应
  void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,
                      CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                      bool bIsLast) override;

  ///登出请求响应
  void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout,
                       CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                       bool bIsLast) override;

  ///错误应答
  void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                  bool bIsLast) override;

  ///订阅行情应答
  void
  OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument,
                     CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                     bool bIsLast) override;

  ///取消订阅行情应答
  void
  OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument,
                       CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                       bool bIsLast) override;

  ///订阅询价应答
  void
  OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument,
                      CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                      bool bIsLast) override;

  ///取消订阅询价应答
  void
  OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument,
                        CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                        bool bIsLast) override;

  ///深度行情通知
  void OnRtnDepthMarketData(
      CThostFtdcDepthMarketDataField *pDepthMarketData) override;

  ///询价通知
  void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp) override;
};

} // namespace market

#endif
