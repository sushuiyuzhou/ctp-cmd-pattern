#ifndef CMD_CVT_H
#define CMD_CVT_H

#include <map>
#include <string>

namespace strategy {
namespace utils {

template<typename T>
struct CVT {
  static std::map<T, std::string> &getMap() {
    static std::map<T, std::string> m_map;
    return m_map;
  }
  static bool addEnumStr(T label, std::string str) {
    return getMap().emplace(std::make_pair(label, str)).second;
  }
  static std::string toStr(T label) {
    auto it = getMap().find(label);
    if (it != getMap().end()) {
      return it->second;
    }
    return std::string("");
  }
};

template<typename T>
std::string toStr(T key) {
  return CVT<T>::toStr(key);
}
}
}

#endif

