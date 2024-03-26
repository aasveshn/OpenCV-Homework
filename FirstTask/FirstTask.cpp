#include "FirstTask.h"

#include <opencv2/opencv.hpp>

void FirstTask(std::string path) {
    // �������� �����������
    cv::Mat image = cv::imread(path);

    // �������� �� �������� �������� �����������
    if (image.empty()) {
        std::cerr << "Error, cant open image" << std::endl;
        return;
    }

    // �������� �������������� ���������� �������������� ��� ����������� �����������
    cv::CascadeClassifier car_cascade;
    if (!car_cascade.load("FirstTask/classifiers/cars.xml")) {
        std::cerr << "Error, cant load classifier" << std::endl;
        return;
    }

    // ���������� �������������� ��� ����������� ����������� �� �����������
    std::vector<cv::Rect> cars;
    car_cascade.detectMultiScale(image, cars);

    // ��������� ��������������� ������ ������������ �����������
    for (const auto& car : cars) {
        cv::rectangle(image, car, cv::Scalar(0, 255, 0), 2);
    }

    // ����� ����������
    cv::imshow("Detection", image);
    cv::waitKey(0);
}
