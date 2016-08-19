#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <time.h>

int main(int argc, char** argv) {
  int i;
  IplImage *img = 0;
  CvRNG rng = cvRNG(time(NULL));
  CvPoint pt1, pt2;
  CvScalar rcolor;
  int irandom;

  /* 1: allocate image region and initialize it */
  img = cvCreateImage(cvSize(800, 800), IPL_DEPTH_8U, 3);
  cvZero(img);

  /* 2: draw random lines */
  for ( i = 0; i<5; i++) {
    pt1.x = cvRandInt(&rng) % (img->width);
    pt1.y = cvRandInt(&rng) % (img->height);
    pt2.x = cvRandInt(&rng) % (img->width);
    pt2.y = cvRandInt(&rng) % (img->height);
    irandom = cvRandInt(&rng);
    rcolor = CV_RGB(irandom & 255, (irandom >> 8) & 255, (irandom >> 16) & 255);
    cvLine(img, pt1, pt2, rcolor, cvRandInt(&rng) % 4, CV_AA, 0);
  }


  /* 6: display the image and finish when key is down. */
  cvNamedWindow("Drawing", CV_WINDOW_AUTOSIZE);
  cvShowImage("Drawing", img);
  cvWaitKey(0);

  cvDestroyWindow("Drawing");
  cvReleaseImage(&img);

  return 0;
}

