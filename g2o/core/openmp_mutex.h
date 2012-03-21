// g2o - General Graph Optimization
// Copyright (C) 2011 R. Kuemmerle, G. Grisetti, W. Burgard
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
// IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
// TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
// PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
// TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef G2O_OPENMP_MUTEX
#define G2O_OPENMP_MUTEX

#include "g2o/config.h"

#ifdef G2O_OPENMP
#include <omp.h>
#endif

namespace g2o {

#ifdef G2O_OPENMP

  /**
   * \brief Mutex realized via OpenMP
   */
  class OpenMPMutex
  {
    public:
      OpenMPMutex() { omp_init_lock(&_lock); }
      ~OpenMPMutex() { omp_destroy_lock(&_lock); }
      void lock() { omp_set_lock(&_lock); }
      void unlock() { omp_unset_lock(&_lock); }

    protected:
      omp_lock_t _lock;
  };

#else

  /*
   * dummy which does nothing in case we don't have OpenMP support
   */
  struct OpenMPMutex 
  {
    void lock() {}
    void unlock() {}
  };

#endif

}

#endif