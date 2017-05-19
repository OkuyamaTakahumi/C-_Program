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

/*
ベクトル
   Eigen::Vector[次元数][i, f, d]
   Eigen::Vector2f → float型の二次元ベクトル
   Eigen::Vector3d → double型の三次元ベクトル
   Eigen::Vector4i → int型の四次元ベクトル
行列
   Eigen::Matrix[行と列の数][i, f, d]
   Eigen::Matrix3f → float型の3x3行列
   Eigen::Matrix4d → double型の4x4行列 
 */


int main() {
   srand((unsigned)time(NULL));
   int x=2;

   Vector2f v2(1.0f, 0.5f);
   Vector3f v3(0.0f, 1.0f, -1.0f);
   cout<<v2<<endl;
   
   Matrix3d m1;
   m1 << 1.0, 0.0, 0.0,
       0.0, 1.0, 0.0,
       0.0, 0.0, 1.0;
   cout<<m1<<endl<<endl;

   Matrix3d m2;
   m2=Matrix3d::Constant(1.25);
   m2(1,1)=1.0;
   cout<<m2<<endl<<endl;

   Matrix3d m3;
   m3=Matrix3d::Ones();
   cout<<m3<<endl<<endl;

   MatrixXd m4;
   m4=MatrixXd::Ones(x,4);//x行4列
   cout<<m4<<endl<<endl;

   MatrixXd m5;
   m5=MatrixXd::Constant(2,4,3.5);//2行4列で値が全て3.5
   cout<<m5<<endl<<endl;




	   
   
   




   return 0;
}

