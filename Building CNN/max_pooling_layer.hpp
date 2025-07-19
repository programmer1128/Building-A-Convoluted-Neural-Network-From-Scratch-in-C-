#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include"convolution_layer.hpp"
//#include"relu_layer.hpp"
#include <random>

class Max_Pooling
{
     std::vector<std::vector<double>> reduced_map;

     public :
      
     std::vector<std::vector<double>> set_map(std::vector<std::vector<double>> map,int window_size);
};
