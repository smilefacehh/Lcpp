#pragma once

#include <vector>

#include "common/vec.h"

namespace lcpp
{
class Raytracing
{
public:
    Raytracing() = default;

    // 2d bresenham-line algorithm
    std::vector<Point2i> Trace(const Point2i& start, const Point2i& end);

    // 2d 第二种实现
    std::vector<Point2i> Trace2(Point2i start, Point2i end);

    // 3D
    std::vector<Point3i> Trace3D(Point3i start, Point3i end);
};
}  // namespace lcpp