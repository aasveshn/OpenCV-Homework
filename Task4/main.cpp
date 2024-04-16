#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
  cv::Mat image = cv::imread("img.jpg");

  if (image.empty()) {
      std::cout << "Error \n";
      return 0;
  }
  
  cv::Mat imageRGB, imageHSV, imageYUV, imageLab;

  cv::cvtColor(image, imageRGB, cv::COLOR_BGR2RGB);
  cv::cvtColor(image, imageHSV, cv::COLOR_BGR2HSV);
  cv::cvtColor(image, imageYUV, cv::COLOR_BGR2YUV);
  cv::cvtColor(image, imageLab, cv::COLOR_BGR2Lab);
  
  cv::imshow("Original image", image);
  cv::imshow("RGB", imageRGB);
  cv::imshow("HSV", imageHSV);
  cv::imshow("YUV", imageYUV);
  cv::imshow("Lab", imageLab);
  cv::waitKey(0);
  return 0;
}
