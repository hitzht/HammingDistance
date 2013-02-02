/*
 * hamming_distance_test.cpp
 *
 *   Copyright (c) 2013, Shuji Suzuki
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *   1. Redistributions of source code must retain the above Copyright
 *      notice, this list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above Copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 *   3. Neither the name of the authors nor the names of its contributors
 *      may be used to endorse or promote products derived from this
 *      software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 *   PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 *   ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "../src/hamming_distance.hpp"
#include <string>
#include <gtest/gtest.h>

using namespace std;

TEST(HammingDistanceTest, HammingDistance) {
  string str0 = "abracadabra";
  string str1 = "abrabadadra";

  EXPECT_EQ(2, hd::HammingDistance(str0.begin(), str0.end(), str1.begin(), str1.end()));
}


struct MatchBetweenBAndC {
  bool operator()(char c0, char c1) {
    if (c0 == c1) {
      return true;
    } else if ((c0 == 'b' && c1 == 'c') || (c0 == 'c' && c1 == 'b')) {
      return true;
    }
    return false;
  }
};

TEST(HammingDistanceTest, HammingDistanceWithMatch) {
  string str0 = "abracadabra";
  string str1 = "abrabadadra";

  EXPECT_EQ(1, hd::HammingDistance(str0.begin(), str0.end(), str1.begin(), str1.end(), MatchBetweenBAndC()));
}


