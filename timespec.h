/* Functions for working with timespec structures
 * Written by Daniel Collins (2017-2021)
 * timespec_mod by Alex Forencich (2019)
 * Various contributions by Ingo Albrecht (2021)
 *
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * For more information, please refer to <http://unlicense.org/>
 */

#ifndef DAN_TIMESPEC_H
#define DAN_TIMESPEC_H

#include <stdbool.h>
#include <stdint.h>
#include <sys/time.h>
#include <time.h>

#define TIMESPEC_INIT_FROM_H(hours)                                                     \
    {                                                                                   \
        .tv_sec = (hours) * 3600, .tv_nsec = 0,                                         \
    }

#define TIMESPEC_INIT_FROM_MS(milliseconds)                                             \
    {                                                                                   \
        .tv_sec = (milliseconds) / 1000, .tv_nsec = ((milliseconds) % 1000) * 1000000,  \
    }

#define TIMESPEC_INIT_FROM_US(microseconds)                                             \
    {                                                                                   \
        .tv_sec = (microseconds) / 1000000,                                             \
        .tv_nsec = ((microseconds) % 1000000) * 1000,                                   \
    }

#define TIMESPEC_INIT_FROM_NS(nanoseconds)                                              \
    {                                                                                   \
        .tv_sec = (nanoseconds) / 1000000000, .tv_nsec = (nanoseconds) % 1000000000,    \
    }

#ifdef __cplusplus
extern "C" {
#endif

struct timespec timespec_add(struct timespec ts1, struct timespec ts2);
struct timespec timespec_sub(struct timespec ts1, struct timespec ts2);
struct timespec timespec_mod(struct timespec ts1, struct timespec ts2);

struct timespec timespec_min(struct timespec ts1, struct timespec ts2);
struct timespec timespec_max(struct timespec ts1, struct timespec ts2);
struct timespec timespec_clamp(struct timespec ts1, struct timespec min,
                               struct timespec max);

int timespec_cmp(struct timespec ts1, struct timespec ts2);
bool timespec_eq(struct timespec ts1, struct timespec ts2);
bool timespec_gt(struct timespec ts1, struct timespec ts2);
bool timespec_ge(struct timespec ts1, struct timespec ts2);
bool timespec_lt(struct timespec ts1, struct timespec ts2);
bool timespec_le(struct timespec ts1, struct timespec ts2);

struct timespec timespec_from_double(double s);
double timespec_to_double(struct timespec ts);
struct timespec timespec_from_timeval(struct timeval tv);
struct timeval timespec_to_timeval(struct timespec ts);
struct timespec timespec_from_ms(int_least64_t milliseconds);
int_least64_t timespec_to_ms(struct timespec ts);
struct timespec timespec_from_us(int_least64_t microseconds);
int_least64_t timespec_to_us(struct timespec ts);
struct timespec timespec_from_ns(int_least64_t nanoseconds);
int_least64_t timespec_to_ns(struct timespec ts);

struct timespec timespec_normalise(struct timespec ts);

#ifdef __cplusplus
}
#endif

#endif /* !DAN_TIMESPEC_H */
