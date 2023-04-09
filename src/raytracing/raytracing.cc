#include "raytracing/raytracing.h"

#include <cmath>

namespace lcpp
{
std::vector<Point2i> Raytracing::Trace(const Point2i& start, const Point2i& end)
{
    std::vector<Point2i> pts;

    int32_t step_n = 0;
    int32_t x_n = end.x - start.x;
    int32_t y_n = end.y - start.y;

    if (x_n == 0 && y_n == 0)
    {
        pts.emplace_back(start);
        return pts;
    }

    int32_t step_dir = 0;  // 0 x, 1 y
    float k, k_inv;
    Point2i new_start = start, new_end = end;
    if (abs(x_n) > abs(y_n))
    {
        step_n = abs(x_n);
        if (x_n < 0)
        {
            new_start = end;
            new_end = start;
        }
        k = float(new_end.y - new_start.y) / float(new_end.x - new_start.x);
    }
    else
    {
        step_dir = 1;
        step_n = abs(y_n);
        if (y_n < 0)
        {
            new_start = end;
            new_end = start;
        }
        k_inv = float(new_end.x - new_start.x) / float(new_end.y - new_start.y);
    }

    Point2i next;
    for (int32_t step = 0; step <= step_n; ++step)
    {
        if (step_dir == 0)
        {
            next.x = new_start.x + step;
            next.y = std::round(k * step + new_start.y);
        }
        else
        {
            next.y = new_start.y + step;
            next.x = std::round(k_inv * step + new_start.x);
        }
        pts.emplace_back(next);
    }

    return pts;
}
}  // namespace lcpp