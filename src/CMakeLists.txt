cmake_minimum_required(VERSION 3.7)
project(ctp-cmd)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

# Boost
find_package(Boost COMPONENTS program_options filesystem date_time REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(SOURCE_FILES
        main.cpp
        trade/TradeSpi.cpp
        utils/ConsoleLogger.cpp
        trade/StrategyInvoker.cpp
        trade/TradeCmd.cpp
        market/MarketSpi.cpp
        market/MarketCmd.cpp
        order/OrderFactory.cpp)

add_executable(ctp-cmd ${SOURCE_FILES})

# CTP API
include_directories(ctp)

# ctp Trade libraries
target_link_libraries(ctp-cmd thostmduserapi thosttraderapi)

#Link with Boost
target_link_libraries(ctp-cmd ${Boost_LIBRARIES})
