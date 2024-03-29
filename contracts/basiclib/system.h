#pragma once
#include <basiclib/types.h>

extern "C" {

   /**
    * @defgroup systemapi System API
    * @ingroup contractdev
    * @brief Define API for interating with system level intrinsics
    *
    */

   /**
    * @defgroup systemcapi System C API
    * @ingroup systemapi
    * @brief Define API for interating with system level intrinsics
    *
    * @{
    */

   /**
    *  Aborts processing of this message and unwinds all pending changes if the test condition is true
    *  @brief Aborts processing of this message and unwinds all pending changes
    *  @param test - 0 to abort, 1 to ignore
    *  @param cstr - a null terminated message to explain the reason for failure

    */
   void  assert( uint32_t test, const char* cstr );

   /**
    *  Returns the time in seconds from 1970 of the last accepted block (not the block including this message)
    *  @brief Get time of the last accepted block
    *  @return time in seconds from 1970 of the last accepted block
    */
   Time  now();

   ///@ } systemcapi
}


