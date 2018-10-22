#include <iostream>

#include <boost/program_options.hpp>

#include "config.h"
#include "./trade/TradeSpi.h"

#include "./utils/ConsoleLogger.h"

// testing
#include "./trade/TradeCmd.h"


namespace po = boost::program_options;

int main(int argc, char **argv) {
  // global console logger
  utils::getConsoleLogger()->info("Initialize logger.");

  po::options_description desc("Allowed options", 200);
  desc.add_options()
      ("dev,d", "dev mode.\n")
      ("test,t", "test mode.\n");

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if (vm.count("test")) {
    CThostFtdcTraderApi *pTradeUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi();
    auto TradeSpi = trade::TradeSpi(pTradeUserApi, utils::getConsoleLogger());

    pTradeUserApi->RegisterSpi(&TradeSpi);
    pTradeUserApi->RegisterFront(config::gTradeFrontAddr);

    trade::LogInCmd login(pTradeUserApi, &TradeSpi);
    login.execute();

    trade::LogOutCmd(pTradeUserApi, &TradeSpi).execute();

    return 0;
  }

  if (vm.count("dev")) {
    CThostFtdcTraderApi *pTradeUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi();
    auto TradeSpi = trade::TradeSpi(pTradeUserApi, utils::getConsoleLogger());

    pTradeUserApi->RegisterSpi(&TradeSpi);
    pTradeUserApi->RegisterFront(config::gTradeFrontAddr);

    pTradeUserApi->SubscribePublicTopic(THOST_TERT_RESTART);
    pTradeUserApi->SubscribePrivateTopic(THOST_TERT_RESUME);

    pTradeUserApi->Init();
    pTradeUserApi->Join();

    return 0;
  }

  return 0;
}