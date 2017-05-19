#include <iostream>
#include <string>
#include<math.h>
#include<vector>
#include<fstream>
#include<list>
#include<algorithm>
using namespace std;

class Nap{
   int C_limit; //ナップサックの容量
   int Item; //品物の数
   int X;//個体の数

   vector<int> C;//品物の容量
   vector<int> V;//品物の価値
   vector<vector<int>> E;
   //個体を行，染色体を列
   vector<int> C_sum;
   vector<int> V_sum;

   vector<vector<int>> elite;

   vector<vector<int>> nextE;	


public:
   Nap(){}
   Nap(int a, int b, int c):
      C_limit(a), //ナップサックの容量
      Item(b), //品物の数
      X(c),//個体の数
      C(Item),//品物の容量
      V(Item),//品物の価値
      E(X,vector<int>(Item)),
      //個体を行，染色体を列
      C_sum(X),//各個体の容量の和
      V_sum(X),//各個体の価値の和
      elite(2,vector<int>(Item)),
      //エリートな個体を行, 染色体を列
      nextE(X,vector<int>(Item))

  {}

   void CVset();
   void Eset();
   void Hyouka();
   void Elite();
   void Roulette();
   void Nitenkousa();
   void Heni();
   void Inelite();
   void Showkai();
};

void Nap::CVset(){
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
}

void Nap::Eset(){
   for(int i=0;i<X;i++){
      for(int j=0;j<Item;j++){
         E[i][j]=rand()%2;
	 cout<<E[i][j];
      }
      cout<<endl;
   }
   cout<<endl;
}
void Nap::Hyouka(){   
   for(int i=0;i<X;i++){
      C_sum[i]=0;
      V_sum[i]=0;
      for(int j=0;j<Item;j++){
	 if(E[i][j]==1){
	    C_sum[i]+=C[j];
	    V_sum[i]+=V[j];
	 }

	 if(C_sum[i]>C_limit){
	    V_sum[i]=0;
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
}

void Nap::Elite(){
   vector<int> top2(2);//エリートの個体の価値の和
   vector<int> N_top2(2);//エリートの個体の個体番号

   if(V_sum[0] > V_sum[1]){
      top2[0] = V_sum[0];
      top2[1] = V_sum[1];
      N_top2[0] = 0;
      N_top2[1] = 1;
   }
   else{
      top2[0] = V_sum[1];
      top2[1] = V_sum[0];
      N_top2[0] = 1;
      N_top2[1] = 0;
   }
   for(vector<int>::size_type i=2;i<X; i++){
      if(V_sum[i]>top2[0]){
	 top2[1]=top2[0];
	 top2[0]=V_sum[i];
	 N_top2[1]=N_top2[0];
	 N_top2[0] = i;
      }
      else if(V_sum[i]>top2[1]){
	 top2[1]=V_sum[i];
	 N_top2[1] = i;
      }
   }
   for(vector<int>::size_type i=0;i<2;i++){
      for(vector<int>::size_type j=0;j<Item;j++){
	 elite[i][j]=E[N_top2[i]][j];
      }
   }
   cout<<"エリート : ["<<top2[0]<<","<<top2[1]<<"]"<<endl;

}
void Nap::Roulette(){
   int total=0;
   for(vector<int>::size_type i=0;i<X;i++){
      total+=V_sum[i];
   }
   
   for(vector<int>::size_type i=0;i<X;i++){
      int mato=rand()%total;
      int sum=0;
           for(vector<int>::size_type j=0;j<X;j++){
	 sum += V_sum[j];
         if(sum>mato){
	    for(int val=0;val<Item;val++){
	       nextE[i][val] = E[j][val];
	    }
            break;
	 }
      }
   }
}
void Nap::Nitenkousa(){
   for(int x=0;(X%2==1 && x<X-1) || (X%2==0 && x<X);x=x+2){
      int crossrate=rand()%100;
      if(crossrate<95){
	 int r1=rand()%Item;
int r2=r1+rand()%(Item-r1);
        
	 vector<vector<int>> child(2,vector<int>(Item));

	 for(vector<int>::size_type i=0;i<Item;i++ ){
	    if(r1<=i && i<=r2){
	       child[0][i]=nextE[x+1][i];
	       child[1][i]=nextE[x][i];
	    }
	    else{
               child[0][i]=nextE[x][i];
	       child[1][i]=nextE[x+1][i];
	    }
         }
	 for(vector<int>::size_type i=0;i<Item;i++){
	    nextE[x][i]=child[0][i];
            nextE[x+1][i]=child[1][i];    
	 }
      }
      else{
         cout<<"入れ替えなし"<<endl;
      }
   }
}
void Nap::Heni(){
   for(vector<int>::size_type i=0;i<X;i++){
      int henirate=rand()%100;
      if(henirate<3){
	 int m=rand()%Item;
	 nextE[i][m]=(nextE[i][m]+1)%2;
      }
   }
}
void Nap::Inelite(){
   for(vector<int>::size_type i=0;i<X;i++){
      for(vector<int>::size_type j=0;j<Item;j++){
	 if(i==0 || i==1){
	    E[i][j]=elite[i][j];
	 }
	 else{
	    E[i][j]=nextE[i][j];
	 }
      }
   }
}
void Nap::Showkai(){
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

      cout<<"解 : ";
      for(int j=0;j<Item;j++){
         cout<<elite[0][j];
      }
      cout<<endl;
      for(int j=0;j<Item;j++){
         if(elite[0][j]==1){
	    cout<<"["<<C[j]<<","<<V[j]<<"]"<<",";
	 }
      }
      cout<<endl;
}




///////////////////////////////////////////////////////////////
 
///////////////////////////////////////////////////////////////

class GA{
   Nap N;
   int GENERATION;
 
      
public:
   GA():
      GENERATION(20),
      N(50,20,9)//(ナップサックの容量,品物量,個体数) 
   {}

   void Keisan();
};
   
void GA::Keisan(){ 
   N.CVset();
   N.Eset();
   for(int a=0;a<GENERATION;a++){
      N.Hyouka();
      N.Elite();
      if(a==GENERATION-1){
	 break;
      }
      N.Roulette();
      N.Nitenkousa();
      N.Heni();
      N.Inelite();
   }
   N.Showkai();
} 
//////////////////////////////////////////////////////////////////


int main(){
   srand((unsigned)time(NULL));
   GA G;
   G.Keisan();
   return 0;
}

