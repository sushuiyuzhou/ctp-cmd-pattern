#include "MarketSpi.h"

namespace market {
///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
void MarketSpi::OnFrontConnected() { _logger->info(BOOST_CURRENT_FUNCTION); };

///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
///@param nReason 错误原因
///        0x1001 网络读失败
///        0x1002 网络写失败
///        0x2001 接收心跳超时
///        0x2002 发送心跳失败
///        0x2003 收到错误报文
void MarketSpi::OnFrontDisconnected(int nReason) {
  _logger->info(BOOST_CURRENT_FUNCTION);
};

///心跳超时警告。当长时间未收到报文时，该方法被调用。
///@param nTimeLapse 距离上次接收报文的时间
void MarketSpi::OnHeartBeatWarning(int nTimeLapse) {
  _logger->info(BOOST_CURRENT_FUNCTION);
};

///登录请求响应
void MarketSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,
                               CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                               bool bIsLast) {
  _logger->info(BOOST_CURRENT_FUNCTION);
};

///登出请求响应
void MarketSpi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout,
                                CThostFtdcRspInfoField *pRspInfo,
                                int nRequestID, bool bIsLast) {
  _logger->info(BOOST_CURRENT_FUNCTION);
};

///错误应答
void MarketSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID,
                           bool bIsLast) {
  _logger->info(BOOST_CURRENT_FUNCTION);
};

///订阅行情应答
void MarketSpi::OnRspSubMarketData(
    CThostFtdcSpecificInstrumentField *pSpecificInstrument,
    CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  _logger->info(BOOST_CURRENT_FUNCTION);
};

///取消订阅行情应答
void MarketSpi::OnRspUnSubMarketData(
    CThostFtdcSpecificInstrumentField *pSpecificInstrument,
    CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  _logger->info(BOOST_CURRENT_FUNCTION);
};

///订阅询价应答
void MarketSpi::OnRspSubForQuoteRsp(
    CThostFtdcSpecificInstrumentField *pSpecificInstrument,
    CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  _logger->info(BOOST_CURRENT_FUNCTION);
};

///取消订阅询价应答
void MarketSpi::OnRspUnSubForQuoteRsp(
    CThostFtdcSpecificInstrumentField *pSpecificInstrument,
    CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  _logger->info(BOOST_CURRENT_FUNCTION);
};

///深度行情通知
void MarketSpi::OnRtnDepthMarketData(
    CThostFtdcDepthMarketDataField *pDepthMarketData) {
  _logger->info(BOOST_CURRENT_FUNCTION);
};

///询价通知
void MarketSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp) {
  _logger->info(BOOST_CURRENT_FUNCTION);
};

} // namespace market
