#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

void drawContour(cv::InputArray &array, cv::InputArray &image, std::string name);

int main( void ){
    
    cv::Mat image = cv::imread("img.png", cv::IMREAD_COLOR);
    cv::Mat  grayImage, grayCanny;

    if(image.empty()){
        std::cout << "Error \n";
        return 0;
    }

    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(grayImage, grayImage, cv::Size(3, 3), 0);
    
    cv::Canny(grayImage, grayCanny, 50, 50, 3);

    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    
    cv::findContours( grayCanny, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
    cv::Mat result(cv::Mat::zeros( image.size(), CV_8UC3 ));

    for( size_t i = 0; i< contours.size(); i++ ){
        cv::Scalar color = cv::Scalar(0, 255, 0);
        cv::drawContours(result, contours, (int) i, color, 2, cv::LINE_8, hierarchy, 0);
    }

    for(const auto &contour : contours){
        auto moment = cv::moments(contour);
        auto point = cv::Point( static_cast<float>(moment.m10 / (moment.m00 + 1e-5)),
                                static_cast<float>(moment.m01 / (moment.m00 + 1e-5)));

        std::vector<cv::Point> contoursPoints;

        cv::approxPolyDP(cv::Mat(contour), contoursPoints, 5, true );

        if (contoursPoints.size() == 4){
            cv::putText(result, "Rectangle", point, 1, 1, cv::Scalar(0, 255, 0));
        }
        else if (contoursPoints.size() == 3){
            cv::putText(result, "Triangle", point, 1, 1, cv::Scalar(0, 255, 0));
        }
        else{
            cv::putText(result, "Circle", point, 1, 1, cv::Scalar(0, 255, 0));
        }
    }

    cv::imshow("OriginalImage", image);
    cv::imshow("Result", result);
    cv::waitKey(0);
    return 0;
}
