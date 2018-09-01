#include "camera.hpp"

#include <iostream>

#include <opencv2/opencv.hpp>

std::string take_pic()
{
    cv::VideoCapture cap(0);

    // Get the frame
    cv::Mat save_img; cap >> save_img;

    if (save_img.empty())
    {
        std::cerr << "Something is wrong with the webcam, could not get frame." << std::endl;
    }

    const auto out = "out.jpg";

    // Save the frame into a file
    imwrite(out, save_img);

    return out;
}
