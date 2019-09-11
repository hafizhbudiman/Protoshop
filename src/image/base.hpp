#ifndef BASE_IMAGE_HPP
#define BASE_IMAGE_HPP

#include <iostream>
#include "../../lib/CImg/CImg.h"
#include "pixel.hpp"

enum ImageType {
    BLACKWHITE,
    GRAYSCALE,
    RGB
};

class Image {
protected:
  pixel** pixels;

  /**
   * @method set_pixel
   * @param {int} row position of pixel from top, starting from 0
   * @param {int} col position of pixel from left, starting from 0
   * @param {pixel} px new pixel
   */
  void set_pixel(int row, int col, pixel px);

private:
  cimg_library::CImg<unsigned char>* cimg;

public:
  ImageType imageType;
  int height;
  int width;

  /**
   * @constructor
   * @param {ImageType} imageType type of the image
   * @param {int} height height of the image
   * @param {int} width width of the image
   */
  Image(ImageType imageType, int height, int width);

  /**
   * @constructor
   * @param {string} filename of the image file
   */
  static Image* load(std::string filename);

  /**
   * @method show
   * show the image using CImg library
   */
  void show();

  ~Image();
};

#endif
