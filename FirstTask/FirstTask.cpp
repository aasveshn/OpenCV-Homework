#include "FirstTask.h"

#include <opencv2/opencv.hpp>

void FirstTask(std::string path) {
    // Загрузка изображения
    cv::Mat image = cv::imread(path);

    // Проверка на успешную загрузку изображения
    if (image.empty()) {
        std::cerr << "Error, cant open image" << std::endl;
        return;
    }

    // Загрузка предварительно обученного классификатора для обнаружения автомобилей
    cv::CascadeClassifier car_cascade;
    if (!car_cascade.load("FirstTask/classifiers/cars.xml")) {
        std::cerr << "Error, cant load classifier" << std::endl;
        return;
    }

    // Применение классификатора для обнаружения автомобилей на изображении
    std::vector<cv::Rect> cars;
    car_cascade.detectMultiScale(image, cars);

    // Рисование прямоугольников вокруг обнаруженных автомобилей
    for (const auto& car : cars) {
        cv::rectangle(image, car, cv::Scalar(0, 255, 0), 2);
    }

    // Вывод результата
    cv::imshow("Detection", image);
    cv::waitKey(0);
}
