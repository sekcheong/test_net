/*
 * ipendpoint.h
 *
 *  Created on: May 11, 2018
 *      Author: scheong
 */

#ifndef SRC_NET_SOCKET_IPENDPOINT_H_
#define SRC_NET_SOCKET_IPENDPOINT_H_

#include "ipaddress.h"

#include "../net.h"
#include "addressfamily.h"

namespace msv {
namespace net {
namespace sockets {


class ip_end_point {
public:
  static const unsigned int min_port = 0;
  static const unsigned int max_port = 0xffff;

  ip_end_point(std::string address) {
    init(address, 0);
  }

  ip_end_point(ip_address address, unsigned int port) {
    init(address, port);
  }

  ip_end_point(int a, int b, int c, int d) {
    ip_address addr(a,b,c,d);
    init(addr, 0);
  }

  ip_end_point(int a, int b, int c, int d, unsigned int port) {
    ip_address addr(a, b, c, d);
    init(addr, port);
  }

private:

  void init(ip_address address, unsigned int port) {
    if (port>max_port) {
      throw argument_out_of_range_exception();
    }
    _port = port;
    _address = address;
  }

  unsigned int _port = min_port;
  ip_address _address;
};

}
}
}


#endif /* SRC_NET_SOCKET_IPENDPOINT_H_ */
