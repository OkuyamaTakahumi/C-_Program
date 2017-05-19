
#include <iostream>
#include <string>
#include<math.h>
using namespace std;


///////////////////////////////////////////////////////////////////
class Neko{

string name;

public:

Neko(){}

Neko(string n){
name=n;
}

void setname(string n){
	name = n;
}

void naku();
};

void Neko::naku(){
	cout<<"My name is "<<name<<endl;
}
///////////////////////////////////////////////////////////////////


int main() {



/*
int x=100;
int *p1;
p1=&x;

cout<<x<<endl;
cout<<p1<<endl;

*p1=200;

cout<<x<<endl;
cout<<p1<<endl<<endl;

///////////////////////////////////////////////////////////////////

Neko N;
Neko *p2;
p2=&N;

N.naku();

N.setname("okuyama");
N.naku();
cout<<p2<<endl;

p2 -> setname("takahumi");// (*p2).setneme("takahumi")と同じ
N.naku();
cout<<p2<<endl<<endl;;
delete p2;


///////////////////////////////////////////////////////////////////

Neko  *p3 = new Neko; //Neko *p3 ; p3= new Neko; と同じ（*いらない）
p3->setname("chinchin");
p3->naku();
cout<<endl;


///////////////////////////////////////////////////////////////////

Neko *p4;
string ans,n;

cout<<"オブジェクト作る？ y or n :";
cin>>ans;

if(ans == "y"){
	cout<<"猫の名前は？:";
	cin>>n;
	p4 = new Neko(n);
	p4->naku();
	p3->naku();
	p2->naku();
	N.naku();
}

else{
	cout<<"わかった作らない"<<endl;
}

delete p3;

delete p4;
*/
//////////////////////////////////////////////////////////////////

int num =5;
Neko *p5 = new Neko[num];
p5[3].setname("haruka");
p5[3].naku();
delete []p5;


return 0;
}
