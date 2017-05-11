#include <iostream>
#include <string>
#include<math.h>
using namespace std;

int main{

  


//////////////////////////////////////////////////////////////////
class kougeki{
	public:
	int energy;
	int x1;
};

//////////////////////////////////////////////////////////////////
class mao{

int x;
int HP;

public:
mao():x(rand()%10),HP(100){};

void attacked(kougeki);
int getHP(){
	return HP;
}

};

void mao::attacked(kougeki k){
	if(k.x1==x){
		HP -= 5*k.energy;
		cout<<"命中"<<endl<<endl;
		
		if (HP>0){
			cout<<"ボスは移動した"<<endl;
			x=rand()%10;
		}
	}
	else if(k.x1==x-1 || k.x1==x+1){
		HP -= k.energy;
		cout<<"カスった"<<endl<<endl;
	}
	else{
		cout<<"外れ"<<endl<<endl<<endl;
	}
	if (HP<=0){
		HP=0;
		cout<<endl<<"倒した"<<endl;
	}
	else{
	cout<<"魔王の残りエネルギー："<<HP<<endl;
	}
}

///////////////////////////////////////////////////////////////////

class yusha{
int hp;

public:
yusha():hp(50){};

int gethp(){
	return hp;
}
kougeki attack();
};

kougeki yusha::attack(){
	kougeki k;
	cout<<"勇者の攻撃"<<endl;
	
	cout<<"どのくらいエネルギー使う？:";
	cout<<"勇者の残りエネルギー："<<hp<<endl;
	cin>>k.energy;
	if(hp<k.energy){
		k.energy=hp;
	}
	hp-=k.energy;
	cout<<"0~9を選んで:";
	cin>> k.x1;
	return k;
}

///////////////////////////////////////////////////////////////////
 
class senjou{
	mao M;
	yusha Y;
	void ending(){
		cout<<"Finish"<<endl;
	}
	public:
	senjou();
	void play();
};

senjou::senjou(){
	cout<<endl<<"START"<<endl<<endl;
	cout<<"魔王の残りエネルギー："<<M.getHP()<<endl;
}

void senjou::play(){
	while(Y.gethp()>0){
		if(M.getHP()<=0){
			break;
		}
		kougeki k = Y.attack();
		M.attacked(k);
	}
	if(M.getHP()>0){
		cout<<endl<<"倒せなかった"<<endl;
		}
	else if(Y.gethp()<=0){
		cout<<"しかし勇者のエネルギーも0なので相打ち"<<endl;
		}
	ending();
}


//////////////////////////////////////////////////////////////////

int main(){
	srand((unsigned)time(NULL));
	senjou S;
	S.play();
return 0;
}
