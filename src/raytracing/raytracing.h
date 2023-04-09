#pragma once

#include <vector>

#include "common/vec.h"

namespace lcpp
{
class Raytracing
{
public:
    Raytracing() = default;

    // bresenham-line algorithm
    std::vector<Point2i> Trace(const Point2i& start, const Point2i& end);
};
}  // namespace lcpp