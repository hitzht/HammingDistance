/*
 * hamming_distance_priv.hpp
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
#ifndef HAMMING_DISTANCE_PRIV_HPP_
#define HAMMING_DISTANCE_PRIV_HPP_

namespace hamming_distance {

template<typename StringIterator>
uint64_t HammingDistance(StringIterator string0_first, StringIterator string0_last,
    StringIterator string1_first, StringIterator string1_last) {
  StringIterator string0_it = string0_first;
  StringIterator string1_it = string1_first;
  uint64_t distance = 0;
  for (; (string0_it != string0_last) && (string1_it != string1_last); ++string0_it, ++string1_it) {
    if (*string0_it != *string1_it) {
      ++distance;
    }
  }

  for (; string0_it != string0_last; ++string0_it) {
    ++distance;
  }
  for (; string1_it != string1_last; ++string1_it) {
    ++distance;
  }
  return distance;
}

template<typename StringIterator, typename Match>
uint64_t HammingDistance(StringIterator string0_first, StringIterator string0_last,
    StringIterator string1_first, StringIterator string1_last, Match match) {
  StringIterator string0_it = string0_first;
  StringIterator string1_it = string1_first;
  uint64_t distance = 0;
  for (; (string0_it != string0_last) && (string1_it != string1_last); ++string0_it, ++string1_it) {
    if (!match(*string0_it, *string1_it)) {
      ++distance;
    }
  }

  for (; string0_it != string0_last; ++string0_it) {
    ++distance;
  }
  for (; string1_it != string1_last; ++string1_it) {
    ++distance;
  }
  return distance;
}
}

#endif /* HAMMING_DISTANCE_PRIV_HPP_ */
