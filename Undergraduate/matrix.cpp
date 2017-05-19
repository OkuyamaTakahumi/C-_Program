#include <iostream>
#include<math.h>
using namespace std;

int main() {
   double R[2][2]={{1,2},{3,4}};
   double q[2][2];
   double s[2][2];

   double a = R[0][0]*R[1][1]-R[0][1]*R[1][0];
   q[0][0]=R[1][1]/a;
   q[1][1]=R[0][0]/a;
   q[0][1]=-R[0][1]/a;
   q[1][0]=-R[1][0]/a;


   for(int i = 0;i<2;i++){
      for(int j = 0;j<2;j++){
         s[i][j]=R[i][0]*q[0][j]+R[i][1]*q[1][j];

      }
   }
   for(int i = 0;i<2;i++){
      for(int j = 0;j<2;j++){
         cout<<"s["<<i<<"]["<<j<<"]:";
         cout<<s[i][j]<<endl;
      }
   }

    return 0;
}
