#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include"convolution_layer.hpp"#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include"convolution_layer.hpp"
//#include"relu_layer.hpp"
#include <random>
#include"max_pooling_layer.hpp"


//we define a window and then take the maximum element in that window
//we slide the window in order of the stride

std::vector<std::vector<double>> Max_Pooling::set_map(std::vector<std::vector<double>> map,int window_size)
{
      //defining a window of size =2*2
      int row_start=0; int row_end=window_size-1;
      int col_start=0; int col_end= window_size-1;
      int row = map.size(); int col = map[0].size();
      double max= std::numeric_limits<double>::lowest();
      std::vector<std::vector<double>> max_map();
      while(row_end<row)
      {
           col_end=window_size-1;
           while(col_end<col)
           {
                //now we find the maximum number in this window 
                for(int i=row_start;i<=row_end;i++)
                {
                     for(int k=col_start;k<=col_end;k++)
                     {
                          max= std::max(max,map[i][k]);
                     }
                }
                col_end++;
           }
           row_end++; 
      }
      return map;
}


//#include"relu_layer.hpp"
#include <random>
#include"max_pooling_layer.hpp"


//we define a window and then take the maximum element in that window
//we slide the window in order of the stride

std::vector<std::vector<double>> Max_Pooling::set_map(std::vector<std::vector<double>> map)
{
     //defining a window of size =2*2
     
     return map;
}
