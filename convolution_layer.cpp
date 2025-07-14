#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include"convolution_layer.hpp"
#include <random>
//applying convolution ioperation to the input matrix

Convolution::Convolution()
{
    
}

Convolution::Convolution(const std::vector<std::vector<double>> &image, int stride_len, int kernel_len)
{
     //storing the image size and the image width
     image_height= image.size(); image_width= image[0].size();

     stride = stride_len;
     kernel_size = kernel_len;
     /*
     
     P = (O*S - S + K - N)/2;

     N = input size (28)

     P = padding

     K = kernel size (3)

     S = stride (1)

     */
     padding = ((28*stride) - stride + kernel_size - 28)/2;

     //initialise the kernel matrix 
     std::default_random_engine generator;
     std::normal_distribution<double> distribution(0,std::sqrt(2.0/9.0));

     //resize the kernel matrix to the kernel size
     //kernel=std::vector<std::vector<double>>(kernel_size,std::vector<std::vector<double>>(kernel_size));
     kernel.resize(kernel_size,std::vector<double>(kernel_size));
     //allot random values according to helium distribution to the kernel
     for(int i=0;i<kernel_size;i++)
     {
         for(int k=0;k<kernel_size;k++)
         {
             kernel[i][k]= distribution(generator);
         }
     }
     std::cout<<"printing kernel\n";
     for(int i=0;i<kernel.size();i++)
     {
         for(int k=0;k<kernel[0].size();k++)
         {
             std::cout<<kernel[i][k]<<" ";
         }
         std::cout<<std::endl;
     }
     std::cout<<"\nprinting padded image\n";
     //initialise the biases to
     pad(image);
}


void Convolution::pad(const std::vector<std::vector<double>> &image)
{
     //padding the image to prevent loss of information at the 
     //edges 
     std::vector<std::vector<double>> image_padded;
     image_padded.resize(image_height+2*padding,std::vector<double>(image_width+2*padding));

     int row=image_padded.size(); int col = image_padded[0].size();
     int r=image.size(); int c= image[0].size();
     for(int i=0;i<row;i++)
     {
         for(int k=0;k<col;k++)
         {
             if(i<padding||i>=padding+r||k<padding||k>=c+padding)
             {
                 image_padded[i][k]=0;
             }
             else
             {
                 image_padded[i][k]=image[i-padding][k-padding];
             }
         }
     }
     for(int i=0;i<image_padded.size();i++)
     {
         for(int k=0;k<image_padded[0].size();k++)
         {
             std::cout<<image_padded[i][k]<<" ";
         }
         std::cout<<std::endl;
     }
     convolute(image_padded);
}

void Convolution::convolute(const std::vector<std::vector<double>> &image)
{
     int row_start=0; int row_end=kernel_size-1;
     int col_start=0; int col_end=kernel_size-1;
     int row=image.size(); int col = image[0].size();

     int map_row=0; int map_col=0;
     int kernel_row=0; int kernel_col=0;

     feature_map.resize(((image.size()-kernel_size)/stride)+1,std::vector<double>(((image[0].size()-kernel_size)/stride)+1,0));
     while(row_end<row)
     {
         col_end=kernel_size-1;map_col=0; col_start=0;
         while(col_end<col)
         {
             //multiply the overlaing pixels of the kernel and image
             //store the information in thefeature map
             kernel_row=0;
             for(int i=row_start;i<=row_end;i++)
             {
                  kernel_col=0;
                 for(int k=col_start;k<=col_end;k++)
                 {
                     feature_map[map_row][map_col]+=image[i][k]*kernel[kernel_row][kernel_col];
                     kernel_col++;
                 }
                 kernel_row++;
             }
             col_end+=stride; map_col++; col_start+=stride;
         }
         row_end+=stride;row_start+=stride; map_row++;
     }

     std::cout<<"\nprinting feature map"<<std::endl;
     for(int i=0;i<feature_map.size();i++)
     {
         for(int k=0;k<feature_map[0].size();k++)
         {
             std::cout<<feature_map[i][k]<<" ";
         }
         std::cout<<std::endl;
     }
}


int main()
{
     std::vector<std::vector<double>> x ={{0,0,1,1,0,0},
                                          {0,1,0,0,1,0},
                                          {1,0,0,0,0,1},
                                          {1,0,0,0,0,1},
                                          {0,1,0,0,1,0},
                                          {0,0,1,1,0,0}
     };
     
     Convolution obj(x,1,3);

}
