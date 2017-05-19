
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

int A[100];
for(int i=0 ; i<100 ; i++){
	A[i]=0;
} 

///////////////////////////////////////////////////////////////////

int num;
string n;
string ans;

cout<<"何匹召喚する？：" ;
cin >> num;

Neko *p1;
p1 = new Neko[num];
//Neko *p1 = new Neko[100];と同じ
//x[0],x[1]...はポインタでなくオブジェクト
//だからx[0]->naku();とはできなく, x[0].naku();

for (int i=0 ; i<num ; i++){
	cout<<i+1<<"匹目の名前は？";
	cin >> n;
	p1[i].setname(n);
} 

cout<<"鳴かせる？ y or n :";
cin>>ans;

if(ans == "y"){
	
	for(int val ; val<num ; val++ ){
		p1[val].naku();
	}
}

else{
	cout<<"わかった鳴かせない"<<endl;
}



///////////////////////////////////////////////////////////////////

Neko N[100];
//Neko N[num];はエラー
//Neko *N =new Neko[num];なら大丈夫
N[0].setname("tama");
N[0].naku();



delete []p1;//[]大事,配列へのポインタなので
return 0;
}