#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <iostream>
#include <string>

namespace msv {

class ExceptionBase: public std::exception {
public:

  ExceptionBase() {
    _errorCode = 0;
  }

  explicit ExceptionBase(std::string errorMsg) {
    _errorMsg = errorMsg;
    _errorCode = 0;
  }

  explicit ExceptionBase(std::string errorMsg, int errorCode) {
    _errorMsg = errorMsg;
    _errorCode = errorCode;
  }

  virtual const char* what() const throw () {
    return _errorMsg.c_str();
  }

  virtual const std::string &message() {
    return _errorMsg;
  }

  virtual const int errorCode() const throw () {
    return _errorCode;
  }

  virtual ~ExceptionBase() throw () {}

private:
  std::string _errorMsg;
  int _errorCode;

};


}

#endif
