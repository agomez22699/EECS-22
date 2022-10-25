#ifndef ADVANCED_H_INCLUDED_
#define ADVANCED_H_INCLUDED_

#include "Constants.h"
#include "Image.h"

/* add noise to an image */
IMAGE *Noise( int percentage, IMAGE *image);

/* posterize the image */
IMAGE *Posterize(IMAGE *image, unsigned int rbits, unsigned int gbits, unsigned int bbits);

/* motion blur */
IMAGE *MotionBlur(int BlurAmount, IMAGE *image);

IMAGE *Enlarge(IMAGE *image, int enlarge_percentage);

IMAGE *Square(IMAGE *image, int x_offset, int y_offset, int square_size);

IMAGE *BrightnessAndContrast(IMAGE *image, int brightness, int contrast);

#endif /* ADVANCED_H_INCLUDED_ */

/* vim: set tabstop=8 softtabstop=8 shiftwidth=8 noexpandtab : */
