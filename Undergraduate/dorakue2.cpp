#include <iostream>
#include <string>
#include<math.h>
using namespace std;

/////////////////////////////////////////////////////////////
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

void Naku();
};

void Neko::Naku(){
	cout<<"My name is "<<name<<endl;
}

//////////////////////////////////////////////////////////////////
class Kougeki{
   public:
   int energy;
   int x1;
};

///////////////////////////////////////////////////////////////////

class Yusha{
   int HP;

public:
   Yusha():HP(50){};

   int GetHP(){
      return HP;
   }
   Kougeki Attack();
};

Kougeki Yusha::Attack(){
   Kougeki k;
   cout<<"勇者の攻撃"<<endl;
	
   cout<<"どのくらいエネルギー使う？:";
   cout<<"勇者の残りエネルギー："<<HP<<endl;
   cin>>k.energy;
   if(HP<k.energy){
      k.energy=HP;
   }
   HP-=k.energy;
   cout<<"0~9を選んで:";
   cin>> k.x1;
   return k;
}
//////////////////////////////////////////////////////////////////
class Mao{

   int x;
   int HP;

public:
   Mao():x(rand()%10),HP(100){};

   void Attacked(Kougeki);
   int GetHP(){
      return HP;
   }

};

void Mao::Attacked(Kougeki k){
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

////////////////////////////////////////////////////////////////
class FNeko : public Neko{
   int x;
   int HP;

public:
   FNeko():x(rand()%10),HP(10),Neko("ネコ戦士"){}

   void Attacked(Kougeki);
   int GetHP(){
      return HP;
   }
};

void FNeko::Attacked(Kougeki k){
   Naku(); //Neko::Naku();でももちろん良いがNaku()はNekoにしかないオリジナルなので省略可能
   
   cout<<"お前の攻撃は"<<k.x1<<"か！"<<endl;

   if(k.x1==x){
      cout<<"命中ニャー"<<endl<<endl;
      HP=0;
   }
   else{
      cout<<"外れニャー"<<endl<<endl<<endl;
   }
   
   if (HP==0){
      HP=0;
      cout<<endl<<"倒した"<<endl;
   }
    
   else{
      cout<<"ネコの残りエネルギー："<<HP<<endl;
   }
}

////////////////////////////////////////////////////////////////
template <class T,class U>class Senjou{
   T M;
   Yusha Y;
   void Ending(){
   cout<<"Finish"<<endl;
   }
public:
   Senjou();
   void Play();
};

template <class T,class U> Senjou<T,U>::Senjou(){
   cout<<endl<<"START"<<endl<<endl;
   cout<<"敵の残りエネルギー："<<M.GetHP()<<endl;
}

template<class T, class U> void Senjou<T,U>::Play(){
   while(Y.GetHP()>0){
      if(M.GetHP()<=0){
         break;
      }
      Kougeki k = Y.Attack();
      M.Attacked(k);
   }
   if(M.GetHP()>0){
      cout<<endl<<"倒せなかった"<<endl;
   }
   else if(Y.GetHP()<=0){
      cout<<"しかし勇者のエネルギーも0なので相打ち"<<endl;
   }
   Ending();
}


//////////////////////////////////////////////////////////////////


int main(){
   srand((unsigned)time(NULL));

   Senjou<Mao,Yusha> S;
   S.Play();

		
   return 0;
}
