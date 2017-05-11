#include <iostream>
#include <string>
#include<math.h>
#include<vector>
#include<fstream>
#include<list>
#include<algorithm>
#include <unordered_set>
#include "package/Eigen/core"
using namespace std;

int main() {
   srand((unsigned)time(NULL));

   int money=120;
   char kigo='m';
   int count=0;
   int X=8;
   int r2=rand()%1;
   double a=double(rand())/double(RAND_MAX)/5.0-0.1;
   
   Eigen::MatrixXf A=Eigen::MatrixXf::Zero(2,2);
   A(0,0)=2;
   A(1,1)=5;

   cout<<a<<endl;

   return 0;
}
