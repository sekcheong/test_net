/*
 * exec.h
 *
 *  Created on: May 10, 2018
 *      Author: scheong
 */

#ifndef SRC_CORE_EXCEPTIONS_EXECPTION_ARG_H_
#define SRC_CORE_EXCEPTIONS_EXECPTION_ARG_H_


#include "exception.h"

namespace msv {


class ArgumentException: public ExceptionBase {
public:
  //inherits the base constructor
  using ExceptionBase::ExceptionBase;
};

class ArgumentNullException: public ExceptionBase {
public:
  //inherits the base constructor
  using ExceptionBase::ExceptionBase;
};

class ArgumentOutOfRangeException: public ArgumentException {
public:
  //inherits the base constructor
  using ArgumentException::ArgumentException;
};


}


#endif /* SRC_CORE_EXCEPTIONS_EXECPTION_ARG_H_ */
