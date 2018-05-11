#ifndef _NET_IPADDRESS_H_
#define _NET_IPADDRESS_H_

#include <string>
#include <sstream>
#include <iostream>
#include <string>
#include <regex>

#include "../net.h"
#include "addressfamily.h"

namespace msv {
namespace net {
namespace sockets {



class IPAddress {
public:

  IPAddress(unsigned long address) {
    setIPAddress(address);
  }

  IPAddress(std::string address) {
    if (!isValidIPV4Address(address)) {
      throw ArgumentException("IPAddress(): address '" + address + "' is invalid.");
    }
    std::stringstream s(address);
    char ch; //temp variable to store the '.'
    int a, b, c, d;
    s >> a >> ch >> b >> ch >> c >> ch >> d;
    auto addr = makeIPv4Address(a, b, c, d);
    setIPAddress(addr);
  }

  unsigned long  getIPAddress() {
    return _address;
  }

private:

  unsigned long makeIPv4Address(int a, int b, int c, int d) {
    return (long) d | ((unsigned int)c << 8) | ((unsigned int)b << 16) | ((unsigned int)a << 24);
  }

  void setIPAddress(unsigned long address) {
    if (address > ADDR_MAX) {
      throw ArgumentOutOfRangeException("getIPAddress(): address out of range");
    }
    _address = address;
  }

  bool isValidIPV4Address(const std::string& s) {
     static const std::regex e("\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}");
     return regex_match(s, e);
  }

private:
  unsigned long _address = 0;
  static const unsigned long ADDR_MIN = 0;
  static const unsigned long ADDR_MAX = 0x00000000ffffffff;
};


}
}
}

#endif /* SRC_NET_SOCKET_IPADDRESS_H_ */
