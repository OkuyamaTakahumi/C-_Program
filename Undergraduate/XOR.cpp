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

class Neural{
	int sou;//層の数
	vector<int> nyuron;//各層のニューロンの数が入ったコンテナ
	vector<vector<int>> in;//入力の入ったコンテナ
	vector<vector<double>> w1;//重み1
   vector<double> w2;//重み2
	double gaku;//学習率
	vector<double> input;
	vector<double> out1;
	double out2;
	vecotr<double> yp;
public:
   Neural(){}
   Neural(int a,double b)://(層の数,学習率)
      sou(a), 
		gaku(b),
		in(4,vector<int>(2)),
      w1(3,vector<double>(2)),
      w2(3),
		input(3),
		outi1(3)
	   yp(4);//教師信号
	{}
   
	void Setwi();
	void Shutu(int val);
	void Denpan(int val);


};

void Neural::Setwi(){
	for(int i=0;i<3;i++){
		w2[i]=double(rand())/double(RAND_MAX)/5.0-0.1;
		for(int j=0;j<2;j++){
			w1[i][j]=double(rand())/double(RAND_MAX)/5.0-0.1;
		}
	}
	in[0][0]=0;
	in[0][1]=0;
	in[1][0]=0;
	in[1][1]=1;
   in[2][0]=1;
	in[2][1]=0;
   in[3][0]=1;
	in[3][1]=1;
	
	cout<<"w1"<<endl;
	for(int i=0;i<3;i++ ){
		for(int j=0; j<2;j++){
			cout<<w1[i][j]<<" ";
		}
		cout<<endl;
	}
   cout<<endl<<"w2"<<endl;
   for(int j=0;j<3;j++){
		cout<<w2[j]<<" ";
	}
   cout<<endl<<endl;
}

void Neural::Shutu(int val){
	input[0]=1;
	input[1]=in[val][0];
	input[2]=in[val][1];
	//cout<<"input"<<endl<<input[1]<<","<<input[2]<<endl;
	double net;
	out1[0]=1;
	for(int i=1;i<2;i++ ){
		net=0;
      for(int j=0; j<3;j++){
         net+=w1[j][i]*input[j];
		}
		out1[i]=1/(1+ exp(net));
		//cout<<out1[i]<<endl;
	}
   input[0]=out1[0];
	input[1]=out1[1];
	input[2]=out1[2];
	//cout<<"input"<<endl<<out1[1]<<","<<input[2]<<endl;
	
	net=0;
	for(int j=0; j<3;j++){
		net+=w2[j]*input[j];
	}
	out2=1/(1+ exp(net));
	cout<<out2<<endl;
}
void Neural::Denpan(int val){
	g3 = out2*(1-out2)*(yp[val]-out2);
	
	g2[0]=out2*(1-out2)
	g2[1]=
	
	for(int i=0:i<3;i++){
		g2[i]=g3*w2[i]*out1[i]*(1-out1[i]);
	}
	
	for(int i=0;i<3;i++){
		int sum=0;
		for(int j=0;j<2;j++){
			sum+=input[i]*w1[i][j];
		}
	   g1[i]=out2*(1-out2)*sum;
   }
   
	for(int i=0;i<3;i++){
		dw2[i]=gaku*
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<2;j++){
			dw1[i][j]=gaku*;
		}
	   g1[i]=out2*(1-out2)*sum;
   }


}

int main(){
	srand((unsigned)time(NULL));
	Neural n(3,0.5);
	n.Setwi();
	for(int val=0;val<4;val++){
		n.Shutu(val);
	}
   return 0;
}
