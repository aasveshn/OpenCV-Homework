#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
  cv::Mat image = cv::imread("img.jpg");

  if (image.empty()) {
      std::cout << "Error \n";
      return 0;
  }

  cv::resize(image, image, cv::Size(1920, 1080));

  cv::line(image, cv::Point(0, 0), cv::Point(1920, 1080), cv::Scalar(0, 255, 0), 3);
  cv::circle(image, cv::Point(1450, 350), 100, cv::Scalar(0, 0, 255), 3);


  cv::putText(image, "width :" + std::to_string(image.cols), cv::Point(250, 330),
              cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 255, 255), 2);
  cv::putText(image, "height " +std::to_string(image.rows), cv::Point(250, 430),
              cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 255, 255), 2);

  cv::putText(image, "sun", cv::Point(1450, 230), 
              cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 255), 2);

  cv::imshow("Image", image);
  cv::waitKey(0);
  return 0;
}
