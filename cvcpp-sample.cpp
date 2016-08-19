#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <iostream>


int main(int argc, const char* argv[]) {
  cv::Mat src = cv::imread(argv[1], cv::IMREAD_COLOR);
  if (src.empty()) {
    std::cerr << "Failed to open img file." << std::endl;
    return -1;
  }

  cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
  cv::imshow("image", src);
  cv::waitKey(0);
//  cv::destroyWindow("image");
  cv::destroyAllWindows();

  return 0;
}
