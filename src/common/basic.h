#pragma once

#include <chrono>

#define L_TIC(var) auto var = std::chrono::high_resolution_clock::now();

#define L_TOC_MS(var)                                                                              \
    int64_t var##_cost = std::chrono::duration_cast<std::chrono::milliseconds>(                    \
                             std::chrono::high_resolution_clock::now() - var)                      \
                             .count();
#define L_TOC_US(var)                                                                              \
    int64_t var##_cost = std::chrono::duration_cast<std::chrono::microseconds>(                    \
                             std::chrono::high_resolution_clock::now() - var)                      \
                             .count();
#define L_TOC_NS(var)                                                                              \
    int64_t var##_cost = std::chrono::duration_cast<std::chrono::nanoseconds>(                     \
                             std::chrono::high_resolution_clock::now() - var)                      \
                             .count();
#define L_TOC_MS_LOG(var)                                                                          \
    L_TOC_MS(var);                                                                                 \
    printf("%s cost(ms): %ld\n", #var, var##_cost);

#define L_TOC_US_LOG(var)                                                                          \
    L_TOC_US(var);                                                                                 \
    printf("%s cost(us): %ld\n", #var, var##_cost);

#define L_TOC_NS_LOG(var)                                                                          \
    L_TOC_NS(var);                                                                                 \
    printf("%s cost(ns): %ld\n", #var, var##_cost);
