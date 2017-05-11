
#include <iostream>
#include <string>
#include<math.h>
#include<vector>
#include<fstream>
#include<list>
#include<algorithm>
using namespace std;

int main(){
   srand((unsigned)time(NULL));
   int C_limit=200; //ナップサックの容量
   int Item=20; //品物の数
   int X=9;//染色体の数

   vector<int> C(Item);//品物の容量
   vector<int> V(Item);//品物の価値
   
   vector<vector<int>> E(X,vector<int>(Item));
   //個体を行，染色体を列

   vector<int> C_sum(X);
   vector<int> V_sum(X);



   
   for(vector<int>::size_type i=0;i<Item;i++){
      C[i]=rand()%9+1;
      V[i]=rand()%9+1;
   }

   cout<<"C : [";
   for(vector<int>::size_type i=0;i<Item;i++){
      cout<<C[i]<<",";
   }
   cout<<"]"<<endl;
   
   cout<<"V : [";
   for(vector<int>::size_type i=0;i<Item;i++){
      cout<<V[i]<<",";
   }
   cout<<"]"<<endl;
   
   
   for(int i=0;i<X;i++){
      for(int j=0;j<Item;j++){
         E[i][j]=rand()%2;
	 cout<<E[i][j];
      }
      cout<<endl;
   }
   cout<<endl;

 
   for(int i=0;i<X;i++){
      C_sum[i]=0;
      V_sum[i]=0;
      for(int j=0;j<Item;j++){
         if(E[i][j]==1){
	    C_sum[i]+=C[j];
	    V_sum[i]+=V[j];
         }

         if(C_sum[i]>C_limit){
	    V_sum[0]=0;
         }
      }  
   }
   
   cout<<"総容量 : [";
   for(vector<int>::size_type i=0;i<X;i++){
      cout<<C_sum[i]<<",";
   }
   cout<<"]"<<endl;
   
   cout<<"総価値 : [";
   for(vector<int>::size_type i=0;i<X;i++){
      cout<<V_sum[i]<<",";
   }
   cout<<"]"<<endl;

   return 0;
}
