#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

class Convolution
{

     //data members 
     int stride; int image_width; int image_height;
     int padding; int kernel_size;
     //filter applied across the image
     std::vector<std::vector<double>> kernel;

     //biases matrix
     std::vector<std::vector<double>> biases;

     //feature map storing the features extracted
     std::vector<std::vector<double>> feature_map;

     public:
     Convolution();
     Convolution(const std::vector<std::vector<double>> &image, int stride_len, int kernel_len);

     void pad(const std::vector<std::vector<double>> &image);
     

     void convolute(const std::vector<std::vector<double>> &image);

};