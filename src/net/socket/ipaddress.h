#ifndef _NET_IPADDRESS_H_
#define _NET_IPADDRESS_H_

#include <string>
#include <sstream>
#include <iostream>
#include <string>
#include <regex>

#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream

#include "../net.h"
#include "addressfamily.h"


namespace msv {
namespace net {
namespace sockets {


class ip_address {
public:

  ip_address(unsigned long address) {
    set_address(address);
  }

  ip_address(std::string address) {
    if (!is_valid_ipv4_address(address)) {
      throw argument_exception("IPAddress(): address '" + address + "' is invalid.");
    }
    std::stringstream s(address);
    char ch; //temp variable to store the '.'
    int a, b, c, d;
    s >> a >> ch >> b >> ch >> c >> ch >> d;
    auto addr = make_ipv4_address(a, b, c, d);
    set_address(addr);
  }

  unsigned long  get_address() {
    return _address;
  }

  std::string get_address_string() {
    int a, b, c, d;
    unpack_ipv4_address(_address, a, b, c, d);
    std::stringstream ss;
    ss << a << "." << b << "." << c << "." << d ;
    return ss.str();
  }

  static unsigned long make_ipv4_address(int a, int b, int c, int d) {
    return (long) d | ((unsigned int) c << 8) | ((unsigned int) b << 16) | ((unsigned int) a << 24);
  }

  static unsigned long unpack_ipv4_address(unsigned long addr, int &a, int &b, int &c, int &d) {
    a = addr & 0x00000000ff000000 >> 24;
    b = addr & 0x0000000000ff0000 >> 16;
    c = addr & 0x000000000000ff00 >> 8;
    d = addr & 0x00000000000000ff;
  }

  static bool is_valid_ipv4_address(const std::string& s) {
    static const std::regex e("\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}");
	return regex_match(s, e);
  }

private:

  void set_address(unsigned long address) {
    if (address > ADDR_MAX) {
      throw argument_out_of_range_exception("getIPAddress(): address out of range");
    }
    _address = address;
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
