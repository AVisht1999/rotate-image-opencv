#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
using namespace std;
using namespace cv;
int main()
{
    String imageName;
    cout<<"Image path: ";
    getline(cin,imageName);
    Mat image=imread(imageName,IMREAD_UNCHANGED);
    Mat newimg;
    int angle;
    cout<<"Rotation degrees (clockwise: +ve): ";
    cin>>angle;
    switch(angle)
    {
    case 0:
    case 360:
        newimg=image;
        break;
    case 90:
    case -270:
        rotate(image,newimg,ROTATE_90_CLOCKWISE);
        break;
    case 180:
    case -180:
        rotate(image,newimg,ROTATE_180);
        break;
    case 270:
    case -90:
        rotate(image,newimg,ROTATE_90_COUNTERCLOCKWISE);
        break;
    default:
        Point rotationCentre=Point(image.cols/2,image.rows/2);
        double a=image.cols, b=image.rows;
        double x=CV_PI*angle/180.0;
        double scale=MIN(b/(a*sin(x)+b*cos(x)),a/(a*cos(x)+b*sin(x)));
        Mat rotationMatrix=getRotationMatrix2D(rotationCentre,-angle,scale);
        warpAffine(image,newimg,rotationMatrix,image.size());
    }
    String original="Original Image";
    String newimage="New Image";
    namedWindow(original);
    namedWindow(newimage);
    imshow(original,image);
    imshow(newimage,newimg);
    waitKey(0);
    destroyWindow(original);
    destroyWindow(newimage);
    return 0;

}