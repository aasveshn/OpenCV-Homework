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

  cv::Mat part1 = image(cv::Rect(0, 0, image.size().width /2 , image.size().height / 2));
  cv::Mat part2 = image(cv::Rect(image.size().width / 2, 0, image.size().width / 2 , image.size().height / 2));
  cv::Mat part3 = image(cv::Rect(image.size().width / 2, image.size().height / 2, image.size().width / 2, image.size().height / 2));
  cv::Mat part4 = image(cv::Rect(0,image.size().height / 2, image.size().width / 2, image.size().height / 2));

  cv::Mat mask = cv::Mat::zeros(image.size(), image.type());
  cv::Mat maskImage = cv::Mat::zeros(image.size(), image.type());    
  cv::circle(mask, cv::Point(1400, 350), 200, cv::Scalar(255, 255, 255), -1);
  image.copyTo(maskImage, mask);

  cv::imshow("Original image", image);
  cv::imshow("Part1", part1);
  cv::imshow("Part2", part2);
  cv::imshow("Part3", part3);
  cv::imshow("Part4", part4);
  cv::imshow("With mask", maskImage);
  
  cv::waitKey(0);
  return 0;
}