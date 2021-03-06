//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// UNSUPPORTED: libcpp-has-no-threads
//
// This test uses new symbols that were not defined in the libc++ shipped on
// darwin11 and darwin12:
// XFAIL: availability=macosx10.7
// XFAIL: availability=macosx10.8

// <memory>

// shared_ptr

// template <class T>
// shared_ptr<T>
// atomic_load(const shared_ptr<T>* p)

// UNSUPPORTED: c++98, c++03

#include <memory>
#include <cassert>

#include "test_macros.h"

int main()
{
    {
        std::shared_ptr<int> p(new int(3));
        std::shared_ptr<int> q = std::atomic_load(&p);
        assert(*q == *p);
    }
}
