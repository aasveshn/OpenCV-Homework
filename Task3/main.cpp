#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


int main()
{
  cv::Mat image = cv::imread("img.JPG");

  if (image.empty()) {
      std::cout << "Error \n";
      return 0;
  }
  
  cv::Mat blurred_image;
  cv:cvtColor(image, blurred_image, cv::COLOR_BGR2GRAY);
  cv::GaussianBlur(blurred_image, blurred_image, cv::Size(5, 5), 1);

  cv::Mat houghImage;
  cv::Canny(image, houghImage, 100, 200, 3);

  std::vector<cv::Vec2f> lines;
    cv::HoughLines(houghImage, lines, 1, CV_PI / 180, 100);

    for (size_t i = 0; i < lines.size(); ++i) {
        float rho = lines[i][0], theta = lines[i][1];
        cv::Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a * rho, y0 = b * rho;
        pt1.x = cvRound(x0 + 1000 * (-b));
        pt1.y = cvRound(y0 + 1000 * (a));
        pt2.x = cvRound(x0 - 1000 * (-b));
        pt2.y = cvRound(y0 - 1000 * (a));
        cv::line(image, pt1, pt2, cv::Scalar(0, 0, 255), 1, cv::LINE_AA);
    }

 
    std::vector<cv::Vec3f> circles;
    cv::HoughCircles(blurred_image, circles, cv::HOUGH_GRADIENT, 2,
                     blurred_image.rows / 5,  
                     200, 200  
                     );

    for (size_t i = 0; i < circles.size(); ++i) {
        cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        cv::circle(image, center, radius, cv::Scalar(0, 0, 255), 2);
    }

  cv::imshow("Image", image); 
  cv::waitKey(0);
  return 0;
}
