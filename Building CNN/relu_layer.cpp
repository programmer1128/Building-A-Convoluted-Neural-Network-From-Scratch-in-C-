#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include"relu_layer.hpp"
#include"functions.hpp"

Relu::Relu(std::vector<std::vector<double>> map)
{
     int row= map.size(); int col = map[0].size();

     for(int i=0;i<row;i++)
     {
         for(int k=0;k<col;k++)
         {
             map[i][k]= relu(map[i][k]);
         }
     }

     feature_map=map;
}


std::vector<std::vector<double>> Relu:: get_map()
{
    return feature_map;
}

std::vector<std::vector<double>> Relu:: set_map(std::vector<std::vector<double>> map)
{
     int row= map.size(); int col = map[0].size();

     for(int i=0;i<row;i++)
     {
         for(int k=0;k<col;k++)
         {
             map[i][k]= relu(map[i][k]);
         }
     }
     return map;
}
