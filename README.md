# rotate-image-opencv
This project is a C++ program to rotate an image by a given angle using OpenCV.

To run:-
> Compile rotate.cpp using OpenCV v4.1.1 and recommended MinGW-W64 compiler. 
  Or run rotate.exe directly.
> Input image path (copy image to folder for convenience).
> Input rotation angle. 
> The original image and new image will be displayed.
> Press any key to close windows.

Rotations in right angles are easily performed using the rotate function.

For other angles, a rotation matrix is created using the getRotationMatrix2D function and necessary scale. The warpAffine function is used to apply rotation matrix to the image.
