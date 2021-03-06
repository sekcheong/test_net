#include <iostream>

#include "../tests.h"

using namespace std;
using namespace msv;
using namespace msv::net::sockets;

unsigned long make_ipv4_address(int a, int b, int c, int d) {
  return (long) d | ((unsigned int)c << 8) | ((unsigned int)b << 16) | ((unsigned int)a << 24);
}

void test_string_to_ip_addr(int a, int b, int c, int d) {
  string ipstr = to_string(a) + "." + to_string(b) + "." + to_string(c) + "." + to_string(d);
  ip_address addr(ipstr);
  auto ip = addr.get_address();
  auto v = make_ipv4_address(a, b, c, d);
  if (ip!=v) {
    cerr << "** ERROR: Address not equal to " << ipstr << endl;
    throw;
  }
}

#define ERROR(x) cerr << "** ERROR: " << x << endl
#define OK() cout << "OK" << endl

string retText(string text) {
  return "!";
}

int test_net_socket_ipaddress() {
  cout << "test_net_socket_ipaddress() " << endl;
  cout << "Test case 1...";
  try {
    ip_address addr(0);
    OK();
  }
  catch (...) {
    ERROR("Unknown error!");
  }

  cout << "Test case 2...";
  try {
    ip_address addr(0xffffffff);
    OK();
  }
  catch (...) {
    ERROR("Unknown error!");
  }

  cout << "Test case 3...";
  try {
    long ip = 0xffffffff;
    ip_address addr(ip+1);
    ERROR("OutOfRangeException not raised for MAX!");
    throw;
  }
  catch (argument_out_of_range_exception &ex) {
    OK();
  }

  cout << "Test case 4...";
  try {
    ip_address addr(-1);
    ERROR("OutOfRangeException not raised for MIN!");
    throw;
  }
  catch (argument_out_of_range_exception &ex) {
    OK();
  }

  cout << "Test case 5...";
  test_string_to_ip_addr(192, 168, 1, 1);
  test_string_to_ip_addr(255, 255, 255, 255);
  test_string_to_ip_addr(0, 255, 255, 255);
  test_string_to_ip_addr(255, 0, 255, 255);
  test_string_to_ip_addr(255, 255, 0, 255);
  test_string_to_ip_addr(255, 255, 255, 0);
  test_string_to_ip_addr(0, 0, 0, 0);
  OK();

  cout << "Test case 6...";
  ip_address addr2(make_ipv4_address(192,168,1, 1));
  if (addr2.get_address_string()!="192.168.1.1") {
    ERROR("get_address_string() not equal to 192.168.1.1");
  }
  OK();

  cout << endl;
  cout << "ALL TESTS PASSED" << endl;
  //cout << sizeof(ip_address) << endl;

  return 0;
}


/*
You need to output ANSI colour codes. Note that not all terminals support this; if colour sequences are not supported, garbage will show up.

Example:

 cout << "\033[1;31mbold red text\033[0m\n";

Here, \033 is the ESC character, ASCII 27. It is followed by [, then zero or more numbers separated by ;, and finally the letter m. The numbers describe the colour and format to switch to from that point onwards.

The codes for foreground and background colours are:

         foreground background
black        30         40
red          31         41
green        32         42
yellow       33         43
blue         34         44
magenta      35         45
cyan         36         46
white        37         47

Additionally, you can use these:

reset             0  (everything back to normal)
bold/bright       1  (often a brighter shade of the same colour)
underline         4
inverse           7  (swap foreground and background colours)
bold/bright off  21
underline off    24
inverse off      27

See the table on Wikipedia for other, less widely supported codes.
 */
