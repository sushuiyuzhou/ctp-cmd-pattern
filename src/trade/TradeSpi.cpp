//
// Created by sushuiyuzhou on 20/10/18.
//

#include "TradeSpi.h"
#include "./StrategyInvoker.h"
#include "./TradeCmd.h"

namespace trade {

///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
void TradeSpi::OnFrontConnected() {
  _logger->info(BOOST_CURRENT_FUNCTION);

  _strategy.invoke(CMD::LogIn);
}

///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
///@param nReason 错误原因
///        0x1001 网络读失败
///        0x1002 网络写失败
///        0x2001 接收心跳超时
///        0x2002 发送心跳失败
///        0x2003 收到错误报文
void TradeSpi::OnFrontDisconnected(int nReason) { _logger->info(BOOST_CURRENT_FUNCTION); }

///心跳超时警告。当长时间未收到报文时，该方法被调用。
///@param nTimeLapse 距离上次接收报文的时间
void TradeSpi::OnHeartBeatWarning(int nTimeLapse) { _logger->info(BOOST_CURRENT_FUNCTION); }

///客户端认证响应
void TradeSpi::OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField,
                                 CThostFtdcRspInfoField *pRspInfo,
                                 int nRequestID,
                                 bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///登录请求响应
void TradeSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,
                              CThostFtdcRspInfoField *pRspInfo,
                              int nRequestID,
                              bool bIsLast) {
  _logger->info(BOOST_CURRENT_FUNCTION);
  if (bIsLast) {
    if (pRspInfo->ErrorID) {
      _logger->error("ctp error msg: {}", pRspInfo->ErrorMsg);
    }

    // register login status
    _isLoggedIn = true;
    strcpy(_BrokerID, pRspUserLogin->BrokerID);
    strcpy(_InvestorID, pRspUserLogin->UserID);
    strcpy(_TradingDay, pRspUserLogin->TradingDay);

    // confirm settlement info
    _strategy.invoke(CMD::ReqQrySettlementInfo);
  }
}

///登出请求响应
void TradeSpi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout,
                               CThostFtdcRspInfoField *pRspInfo,
                               int nRequestID,
                               bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///用户口令更新请求响应
void TradeSpi::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate,
                                       CThostFtdcRspInfoField *pRspInfo,
                                       int nRequestID,
                                       bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///资金账户口令更新请求响应
void TradeSpi::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate,
                                                 CThostFtdcRspInfoField *pRspInfo,
                                                 int nRequestID,
                                                 bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///报单录入请求响应
void TradeSpi::OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder,
                                CThostFtdcRspInfoField *pRspInfo,
                                int nRequestID,
                                bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///预埋单录入请求响应
void TradeSpi::OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder,
                                      CThostFtdcRspInfoField *pRspInfo,
                                      int nRequestID,
                                      bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///预埋撤单录入请求响应
void TradeSpi::OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction,
                                      CThostFtdcRspInfoField *pRspInfo,
                                      int nRequestID,
                                      bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///报单操作请求响应
void TradeSpi::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction,
                                CThostFtdcRspInfoField *pRspInfo,
                                int nRequestID,
                                bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///查询最大报单数量响应
void TradeSpi::OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume,
                                        CThostFtdcRspInfoField *pRspInfo,
                                        int nRequestID,
                                        bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///投资者结算结果确认响应
void TradeSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm,
                                          CThostFtdcRspInfoField *pRspInfo,
                                          int nRequestID,
                                          bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///删除预埋单响应
void TradeSpi::OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder,
                                      CThostFtdcRspInfoField *pRspInfo,
                                      int nRequestID,
                                      bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///删除预埋撤单响应
void TradeSpi::OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction,
                                            CThostFtdcRspInfoField *pRspInfo,
                                            int nRequestID,
                                            bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///执行宣告录入请求响应
void TradeSpi::OnRspExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder,
                                    CThostFtdcRspInfoField *pRspInfo,
                                    int nRequestID,
                                    bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///执行宣告操作请求响应
void TradeSpi::OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction,
                                    CThostFtdcRspInfoField *pRspInfo,
                                    int nRequestID,
                                    bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///询价录入请求响应
void TradeSpi::OnRspForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote,
                                   CThostFtdcRspInfoField *pRspInfo,
                                   int nRequestID,
                                   bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///报价录入请求响应
void TradeSpi::OnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote,
                                CThostFtdcRspInfoField *pRspInfo,
                                int nRequestID,
                                bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///报价操作请求响应
void TradeSpi::OnRspQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction,
                                CThostFtdcRspInfoField *pRspInfo,
                                int nRequestID,
                                bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///申请组合录入请求响应
void TradeSpi::OnRspCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction,
                                     CThostFtdcRspInfoField *pRspInfo,
                                     int nRequestID,
                                     bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询报单响应
void TradeSpi::OnRspQryOrder(CThostFtdcOrderField *pOrder,
                             CThostFtdcRspInfoField *pRspInfo,
                             int nRequestID,
                             bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询成交响应
void TradeSpi::OnRspQryTrade(CThostFtdcTradeField *pTrade,
                             CThostFtdcRspInfoField *pRspInfo,
                             int nRequestID,
                             bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询投资者持仓响应
void TradeSpi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition,
                                        CThostFtdcRspInfoField *pRspInfo,
                                        int nRequestID,
                                        bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询资金账户响应
void TradeSpi::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount,
                                      CThostFtdcRspInfoField *pRspInfo,
                                      int nRequestID,
                                      bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询投资者响应
void TradeSpi::OnRspQryInvestor(CThostFtdcInvestorField *pInvestor,
                                CThostFtdcRspInfoField *pRspInfo,
                                int nRequestID,
                                bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询交易编码响应
void TradeSpi::OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode,
                                   CThostFtdcRspInfoField *pRspInfo,
                                   int nRequestID,
                                   bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询合约保证金率响应
void TradeSpi::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate,
                                            CThostFtdcRspInfoField *pRspInfo,
                                            int nRequestID,
                                            bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询合约手续费率响应
void TradeSpi::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate,
                                                CThostFtdcRspInfoField *pRspInfo,
                                                int nRequestID,
                                                bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询交易所响应
void TradeSpi::OnRspQryExchange(CThostFtdcExchangeField *pExchange,
                                CThostFtdcRspInfoField *pRspInfo,
                                int nRequestID,
                                bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询产品响应
void TradeSpi::OnRspQryProduct(CThostFtdcProductField *pProduct,
                               CThostFtdcRspInfoField *pRspInfo,
                               int nRequestID,
                               bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询合约响应
void TradeSpi::OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument,
                                  CThostFtdcRspInfoField *pRspInfo,
                                  int nRequestID,
                                  bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询行情响应
void TradeSpi::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData,
                                       CThostFtdcRspInfoField *pRspInfo,
                                       int nRequestID,
                                       bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询投资者结算结果响应
void TradeSpi::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo,
                                      CThostFtdcRspInfoField *pRspInfo,
                                      int nRequestID,
                                      bool bIsLast) {
  _logger->info(BOOST_CURRENT_FUNCTION);
  if (bIsLast) {
    if (pRspInfo && (pRspInfo->ErrorID != 0)) {
      _logger->error("ctp error msg: {}", pRspInfo->ErrorMsg);
    }
    // log if returned
    if (pSettlementInfo) {
      if (pSettlementInfo->SettlementID) {
        _logger->info("SettlementID: {}", pSettlementInfo->SettlementID);
      }
    }
  } else {
    _logger->error("data not ended.");
  }
}

///请求查询转帐银行响应
void TradeSpi::OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank,
                                    CThostFtdcRspInfoField *pRspInfo,
                                    int nRequestID,
                                    bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询投资者持仓明细响应
void TradeSpi::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail,
                                              CThostFtdcRspInfoField *pRspInfo,
                                              int nRequestID,
                                              bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询客户通知响应
void TradeSpi::OnRspQryNotice(CThostFtdcNoticeField *pNotice,
                              CThostFtdcRspInfoField *pRspInfo,
                              int nRequestID,
                              bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询结算信息确认响应
void TradeSpi::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm,
                                             CThostFtdcRspInfoField *pRspInfo,
                                             int nRequestID,
                                             bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询投资者持仓明细响应
void TradeSpi::OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail,
                                                     CThostFtdcRspInfoField *pRspInfo,
                                                     int nRequestID,
                                                     bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///查询保证金监管系统经纪公司资金账户密钥响应
void TradeSpi::OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey,
                                              CThostFtdcRspInfoField *pRspInfo,
                                              int nRequestID,
                                              bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询仓单折抵信息响应
void TradeSpi::OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset,
                                      CThostFtdcRspInfoField *pRspInfo,
                                      int nRequestID,
                                      bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询投资者品种/跨品种保证金响应
void TradeSpi::OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin,
                                                  CThostFtdcRspInfoField *pRspInfo,
                                                  int nRequestID,
                                                  bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询交易所保证金率响应
void TradeSpi::OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate,
                                          CThostFtdcRspInfoField *pRspInfo,
                                          int nRequestID,
                                          bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询交易所调整保证金率响应
void TradeSpi::OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust,
                                                CThostFtdcRspInfoField *pRspInfo,
                                                int nRequestID,
                                                bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询汇率响应
void TradeSpi::OnRspQryExchangeRate(CThostFtdcExchangeRateField *pExchangeRate,
                                    CThostFtdcRspInfoField *pRspInfo,
                                    int nRequestID,
                                    bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询二级代理操作员银期权限响应
void TradeSpi::OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap,
                                       CThostFtdcRspInfoField *pRspInfo,
                                       int nRequestID,
                                       bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询产品报价汇率
void TradeSpi::OnRspQryProductExchRate(CThostFtdcProductExchRateField *pProductExchRate,
                                       CThostFtdcRspInfoField *pRspInfo,
                                       int nRequestID,
                                       bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询期权交易成本响应
void TradeSpi::OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost,
                                            CThostFtdcRspInfoField *pRspInfo,
                                            int nRequestID,
                                            bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询期权合约手续费响应
void TradeSpi::OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate,
                                           CThostFtdcRspInfoField *pRspInfo,
                                           int nRequestID,
                                           bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询执行宣告响应
void TradeSpi::OnRspQryExecOrder(CThostFtdcExecOrderField *pExecOrder,
                                 CThostFtdcRspInfoField *pRspInfo,
                                 int nRequestID,
                                 bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询询价响应
void TradeSpi::OnRspQryForQuote(CThostFtdcForQuoteField *pForQuote,
                                CThostFtdcRspInfoField *pRspInfo,
                                int nRequestID,
                                bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询报价响应
void TradeSpi::OnRspQryQuote(CThostFtdcQuoteField *pQuote,
                             CThostFtdcRspInfoField *pRspInfo,
                             int nRequestID,
                             bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询组合合约安全系数响应
void TradeSpi::OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField *pCombInstrumentGuard,
                                           CThostFtdcRspInfoField *pRspInfo,
                                           int nRequestID,
                                           bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询申请组合响应
void TradeSpi::OnRspQryCombAction(CThostFtdcCombActionField *pCombAction,
                                  CThostFtdcRspInfoField *pRspInfo,
                                  int nRequestID,
                                  bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询转帐流水响应
void TradeSpi::OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial,
                                      CThostFtdcRspInfoField *pRspInfo,
                                      int nRequestID,
                                      bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询银期签约关系响应
void TradeSpi::OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister,
                                       CThostFtdcRspInfoField *pRspInfo,
                                       int nRequestID,
                                       bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///错误应答
void TradeSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  _logger->info(BOOST_CURRENT_FUNCTION);
}

///报单通知
void TradeSpi::OnRtnOrder(CThostFtdcOrderField *pOrder) { _logger->info(BOOST_CURRENT_FUNCTION); }

///成交通知
void TradeSpi::OnRtnTrade(CThostFtdcTradeField *pTrade) { _logger->info(BOOST_CURRENT_FUNCTION); }

///报单录入错误回报
void TradeSpi::OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder,
                                   CThostFtdcRspInfoField *pRspInfo) { _logger->info(BOOST_CURRENT_FUNCTION); }

///报单操作错误回报
void TradeSpi::OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction,
                                   CThostFtdcRspInfoField *pRspInfo) { _logger->info(BOOST_CURRENT_FUNCTION); }

///合约交易状态通知
void TradeSpi::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus) {
  //_logger->info(BOOST_CURRENT_FUNCTION);
  // followed by user login.
  //_logger->info("Exchange ID:                     {}", pInstrumentStatus->ExchangeID);
//  _logger->info("Exchange Instrument ID:          {}", pInstrumentStatus->ExchangeInstID);
//  _logger->info("Settlement Group ID:             {}", pInstrumentStatus->SettlementGroupID);
//  _logger->info("Instrument ID:                   {}", pInstrumentStatus->InstrumentID);
//  _logger->info("Instrument Status:               {}", pInstrumentStatus->InstrumentStatus);
//  _logger->info("TThostFtdcTradingSegmentSNType:  {}", pInstrumentStatus->TradingSegmentSN);
//  _logger->info("TThostFtdcTimeType:              {}", pInstrumentStatus->EnterTime);
//  _logger->info("TFtdcInstStatusEnterReasonType:  {}", pInstrumentStatus->EnterReason);
}

///交易通知
void TradeSpi::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo) {
  _logger->info(BOOST_CURRENT_FUNCTION);
}

///提示条件单校验错误
void TradeSpi::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder) {
  _logger->info(BOOST_CURRENT_FUNCTION);
}

///执行宣告通知
void TradeSpi::OnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder) { _logger->info(BOOST_CURRENT_FUNCTION); }

///执行宣告录入错误回报
void TradeSpi::OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder,
                                       CThostFtdcRspInfoField *pRspInfo) { _logger->info(BOOST_CURRENT_FUNCTION); }

///执行宣告操作错误回报
void TradeSpi::OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *pExecOrderAction,
                                       CThostFtdcRspInfoField *pRspInfo) { _logger->info(BOOST_CURRENT_FUNCTION); }

///询价录入错误回报
void TradeSpi::OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote,
                                      CThostFtdcRspInfoField *pRspInfo) { _logger->info(BOOST_CURRENT_FUNCTION); }

///报价通知
void TradeSpi::OnRtnQuote(CThostFtdcQuoteField *pQuote) { _logger->info(BOOST_CURRENT_FUNCTION); }

///报价录入错误回报
void TradeSpi::OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *pInputQuote,
                                   CThostFtdcRspInfoField *pRspInfo) { _logger->info(BOOST_CURRENT_FUNCTION); }

///报价操作错误回报
void TradeSpi::OnErrRtnQuoteAction(CThostFtdcQuoteActionField *pQuoteAction,
                                   CThostFtdcRspInfoField *pRspInfo) { _logger->info(BOOST_CURRENT_FUNCTION); }

///询价通知
void TradeSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp) { _logger->info(BOOST_CURRENT_FUNCTION); }

///保证金监控中心用户令牌
void TradeSpi::OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField *pCFMMCTradingAccountToken) {
  _logger->info(BOOST_CURRENT_FUNCTION);
}

///申请组合通知
void TradeSpi::OnRtnCombAction(CThostFtdcCombActionField *pCombAction) { _logger->info(BOOST_CURRENT_FUNCTION); }

///申请组合录入错误回报
void TradeSpi::OnErrRtnCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction,
                                        CThostFtdcRspInfoField *pRspInfo) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询签约银行响应
void TradeSpi::OnRspQryContractBank(CThostFtdcContractBankField *pContractBank,
                                    CThostFtdcRspInfoField *pRspInfo,
                                    int nRequestID,
                                    bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询预埋单响应
void TradeSpi::OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder,
                                   CThostFtdcRspInfoField *pRspInfo,
                                   int nRequestID,
                                   bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询预埋撤单响应
void TradeSpi::OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction,
                                         CThostFtdcRspInfoField *pRspInfo,
                                         int nRequestID,
                                         bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询交易通知响应
void TradeSpi::OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice,
                                     CThostFtdcRspInfoField *pRspInfo,
                                     int nRequestID,
                                     bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询经纪公司交易参数响应
void TradeSpi::OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams,
                                           CThostFtdcRspInfoField *pRspInfo,
                                           int nRequestID,
                                           bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询经纪公司交易算法响应
void TradeSpi::OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos,
                                          CThostFtdcRspInfoField *pRspInfo,
                                          int nRequestID,
                                          bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///请求查询监控中心用户令牌
void TradeSpi::OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *pQueryCFMMCTradingAccountToken,
                                                  CThostFtdcRspInfoField *pRspInfo,
                                                  int nRequestID,
                                                  bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///银行发起银行资金转期货通知
void TradeSpi::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer) {
  _logger->info(BOOST_CURRENT_FUNCTION);
}

///银行发起期货资金转银行通知
void TradeSpi::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer) {
  _logger->info(BOOST_CURRENT_FUNCTION);
}

///银行发起冲正银行转期货通知
void TradeSpi::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal) {
  _logger->info(BOOST_CURRENT_FUNCTION);
}

///银行发起冲正期货转银行通知
void TradeSpi::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal) {
  _logger->info(BOOST_CURRENT_FUNCTION);
}

///期货发起银行资金转期货通知
void TradeSpi::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer) {
  _logger->info(BOOST_CURRENT_FUNCTION);
}

///期货发起期货资金转银行通知
void TradeSpi::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer) {
  _logger->info(BOOST_CURRENT_FUNCTION);
}

///系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
void TradeSpi::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal) {
  _logger->info(BOOST_CURRENT_FUNCTION);
}

///系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
void TradeSpi::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal) {
  _logger->info(BOOST_CURRENT_FUNCTION);
}

///期货发起查询银行余额通知
void TradeSpi::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount) {
  _logger->info(BOOST_CURRENT_FUNCTION);
}

///期货发起银行资金转期货错误回报
void TradeSpi::OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer,
                                            CThostFtdcRspInfoField *pRspInfo) { _logger->info(BOOST_CURRENT_FUNCTION); }

///期货发起期货资金转银行错误回报
void TradeSpi::OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer,
                                            CThostFtdcRspInfoField *pRspInfo) { _logger->info(BOOST_CURRENT_FUNCTION); }

///系统运行时期货端手工发起冲正银行转期货错误回报
void TradeSpi::OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal,
                                                        CThostFtdcRspInfoField *pRspInfo) {
  _logger->info(BOOST_CURRENT_FUNCTION);
}

///系统运行时期货端手工发起冲正期货转银行错误回报
void TradeSpi::OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal,
                                                        CThostFtdcRspInfoField *pRspInfo) {
  _logger->info(BOOST_CURRENT_FUNCTION);
}

///期货发起查询银行余额错误回报
void TradeSpi::OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount,
                                                CThostFtdcRspInfoField *pRspInfo) { _logger->info(BOOST_CURRENT_FUNCTION); }

///期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
void TradeSpi::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal) {
  _logger->info(BOOST_CURRENT_FUNCTION);
}

///期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
void TradeSpi::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal) {
  _logger->info(BOOST_CURRENT_FUNCTION);
}

///期货发起银行资金转期货应答
void TradeSpi::OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer,
                                             CThostFtdcRspInfoField *pRspInfo,
                                             int nRequestID,
                                             bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///期货发起期货资金转银行应答
void TradeSpi::OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer,
                                             CThostFtdcRspInfoField *pRspInfo,
                                             int nRequestID,
                                             bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///期货发起查询银行余额应答
void TradeSpi::OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount,
                                                  CThostFtdcRspInfoField *pRspInfo,
                                                  int nRequestID,
                                                  bool bIsLast) { _logger->info(BOOST_CURRENT_FUNCTION); }

///银行发起银期开户通知
void TradeSpi::OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount) { _logger->info(BOOST_CURRENT_FUNCTION); }

///银行发起银期销户通知
void TradeSpi::OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount) {
  _logger->info(BOOST_CURRENT_FUNCTION);
}

///银行发起变更银行账号通知
void TradeSpi::OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount) {
  _logger->info(BOOST_CURRENT_FUNCTION);
}

}