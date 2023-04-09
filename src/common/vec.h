#pragma once

#include <cstdint>

namespace lcpp {

template <typename T>
struct Vec2
{
    T x;
    T y;
};

template <typename T>
struct Vec3
{
    T x;
    T y;
    T z;
};

using Vec2f = Vec2<float>;
using Vec2i = Vec2<int32_t>;
using Point2f = Vec2f;
using Point2i = Vec2i;

using Vec3f = Vec3<float>;
using Vec3i = Vec3<int32_t>;
using Point3f = Vec3f;
using Point3i = Vec3i;
}  // namespace lcpp