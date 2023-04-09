#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <limits>

#include "common/basic.h"
#include "raytracing/raytracing.h"

using namespace lcpp;

void DrawPixel(const std::vector<Point2i>& pts)
{
    int32_t minx = std::numeric_limits<int32_t>::max();
    int32_t miny = std::numeric_limits<int32_t>::max();
    int32_t maxx = std::numeric_limits<int32_t>::min();
    int32_t maxy = std::numeric_limits<int32_t>::min();

    for (const auto& pt : pts)
    {
        if (pt.x < minx)
            minx = pt.x;
        if (pt.y < miny)
            miny = pt.y;
        if (pt.x > maxx)
            maxx = pt.x;
        if (pt.y > maxy)
            maxy = pt.y;
    }

    cv::Mat img(maxy - miny + 1, maxx - minx + 1, CV_8UC1);
    img.setTo(0);
    for (const auto& pt : pts)
    {
        img.at<uint8_t>(pt.y - miny, pt.x - minx) = 255;
    }

    cv::imshow("px", img);
    cv::waitKey(-1);
    cv::destroyAllWindows();
}

int main(int argc, char** argv)
{
    if (argc != 5)
    {
        std::cerr << "Usage: ./raytracing_test 1 1 1 20" << std::endl;
        return 0;
    }
    Raytracing raytracer;
    std::vector<Vec2i> points;

    L_TIC(t_bresenham);
    points = raytracer.Trace(Point2i{atoi(argv[1]), atoi(argv[2])},
                             Point2i{atoi(argv[3]), atoi(argv[4])});
    L_TOC_US_LOG(t_bresenham);

    L_TIC(t_bresenham2);
    points = raytracer.Trace2(Point2i{atoi(argv[1]), atoi(argv[2])},
                              Point2i{atoi(argv[3]), atoi(argv[4])});
    L_TOC_US_LOG(t_bresenham2);

    // for (const auto& pt : points)
    // {
    //     std::cout << pt.x << "," << pt.y << std::endl;
    // }

    // DrawPixel(points);
    return 0;
}