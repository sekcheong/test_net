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


class argument_exception: public exception_base {
public:
  //inherits the base constructor
  using exception_base::exception_base;
};

class argument_null_exception: public exception_base {
public:
  //inherits the base constructor
  using exception_base::exception_base;
};

class argument_out_of_range_exception: public argument_exception {
public:
  //inherits the base constructor
  using argument_exception::argument_exception;
};


}


#endif /* SRC_CORE_EXCEPTIONS_EXECPTION_ARG_H_ */
