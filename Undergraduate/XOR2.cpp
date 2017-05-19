#include <iostream>
#include <string>
#include<math.h>
#include<vector>
#include<fstream>
#include<list>
#include<algorithm>
#include <unordered_set>
#include "package/Eigen/Core"
#include "package/Eigen/Geometry"

using namespace std;
using namespace Eigen;//以下サンプルコードでは名前空間Eigenを省略


int main(){
	srand((unsigned)time(NULL));
	double weight[2][2];
	double weight2[2][1];
	int input[2];
	double H[2];
	double O[2];

   for(int i=0;i<2;i++ ){
      for(int j=0; j<2;j++){
	 weight[i][j]=double(rand())/double(RAND_MAX);
      }
   }

   cin>>input[0];
   cin>>input[1];


   for(int i=0;i<2;i++ ){
      for(int j=0; j<2;j++){
         cout<<weight[i][j]<<" ";
		}
      cout<<endl;
   }
   cout<<endl;

   for(int i=0;i<2;i++ ){
      for(int j=0; j<2;j++){
         double x =input[0]*weight[0][i]+input[1]*weight[1][i];
         H[i]=1/(1+ exp(x));
      }
   }  

   for(int i=0;i<2;i++ ){
      cout<<H[i]<<" ";
   }
   cout<<endl<<endl;
		

   for(int i=0;i<2;i++ ){
      weight[i][0]=double(rand())/double(RAND_MAX);
	}
	
	for(int i=0;i<1;i++ ){
      double x =H[0]*weight2[0][i]+H[1]*weight[1][i];
			  O[i]=1/(1+ exp(x));
		  }
		  cout<<O[0]<<endl;
return 0;
}
