#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>


class Relu
{
      std::vector<std::vector<double>> feature_map;

      public :

      Relu (std::vector<std::vector<double>> map);

      std::vector<std::vector<double>> get_map();

      std::vector<std::vector<double>> set_map(std::vector<std::vector<double>> map);
};