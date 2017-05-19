#include <iostream>
#include <string>
#include<math.h>
using namespace std;

class rocket{

	int f,v,h;

public:

	rocket(int,int,int);
	rocket();
	~rocket();
	void Accel(int);
	void Report();
	int GetF(){return f;}
};

rocket::rocket(int a,int b,int c):f(a),v(b),h(c){}
rocket::rocket():f(100),v(0),h(0){}
rocket::~rocket(){
		cout<<"燃料切れ"<<endl;
		cout<<"さらば"<<endl;
	}

void rocket::Accel(int b){
		if(b<0){
			b=0;
		}

		else if(b>f){
			b=f;
		}
		f -= b;
		v += b;
		h += v;
	}

void rocket::Report(){
		cout<<"状況報告"<<endl;
		cout<<"残り燃料："<<f<<endl;
		cout<<"速度："<<v<<endl;
		cout<<"高さ："<<h<<endl;
		//cout<<endl;
	}

int main(){
	int b;
	int i = 1;
	rocket x;
	//rocket y(200,10,5);
	x.Report();
	//y.Report();



	while (x.GetF()>0){
	cout<<i<<"回目の噴射量：";
	cin>>b;
	x.Accel(b);
	x.Report();
	i+=1;
	}
	return 0;
}
