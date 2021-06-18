#include <depthai/depthai.hpp>
#include <iostream>

#define PROJECT_NAME "camera_cv_tests"

int main() {
  int height = 1080;
  int width = 1920;

  dai::Pipeline pipeline;

  // Define source and output
  auto camRGB = pipeline.create<dai::node::ColorCamera>();
  auto xout = pipeline.create<dai::node::XLinkOut>();

  xout->setStreamName("rgb");
  xout->input.setBlocking(false);
  xout->input.setQueueSize(1);

  // Properties
  camRGB->setResolution(
      dai::ColorCameraProperties::SensorResolution::THE_1080_P);
  camRGB->setFps(60);
  camRGB->setVideoSize({width, height});

  // Linking
  camRGB->video.link(xout->input);

  dai::Device device(pipeline);
  auto qRGB = device.getOutputQueue("rgb", 4, false);

  while (true) {
    auto inRGB = qRGB->get<dai::ImgFrame>();

    cv::imshow("rgb", inRGB->getCvFrame());

    int key = cv::waitKey(1);
    if (key == 'q' || key == 'Q')
      return 0;
  }

  return 0;
}
