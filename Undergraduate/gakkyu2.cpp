#include <iostream>
#include <string>
#include<math.h>
#include<vector>
#include<fstream>
#include<list>
using namespace std;

/////////////////////////////////////////////////////////////
class Hito{
   string name;
   string phone;
public:
   void Setname(string n){
      name = n;
   }
   string Getname(){
      return name;
   }

   void Setphone(string n){
      phone = n;
   }
   string Getphone(){
      return phone;
   }
};

//////////////////////////////////////////////////////////////////
class Meibo{
   vector<Hito> data;
   public:
   void Appenddata();
   void Showdata(); 
   void Savedata();
   void Readdata();

};

void Meibo::Appenddata(){
   Hito h;
   string n;
   cout<<"名前入力"<<endl;
   cin>>n;
   h.Setname(n);
   cout<<"電話番号入力"<<endl;
   cin>>n;
   h.Setphone(n);
   data.push_back(h);
}
void Meibo::Showdata(){
   for(vector<Hito>::size_type i=0;i<data.size();i++){
      cout<<i<<"番目"<<endl;
      cout<<data[i].Getname()<<endl;
      cout<<data[i].Getphone()<<endl;
      cout<<"-------------------------------"<<endl;
   }
}
void Meibo::Savedata(){
   ofstream f("meibo.txt");
   for(vector<Hito>::size_type i=0;i<data.size();i++){
      f<<data[i].Getname()<<endl;
      f<<data[i].Getphone()<<endl;
   f<<"xxx"<<endl;

   }
}

void Meibo::Readdata(){
   ifstream f2("meibo.txt");
   Hito h;
   string n;
   while(1){
      if(n=="xxx"){
	 break;
      }
      f2>>n;
      h.Setname(n);
      f2>>n;
      h.Setphone(n);
      data.push_back(h);
   }
}

/////////////////////////////////////////////////////////////////
int main(){
   int a;
   Meibo m;

   m.Readdata();
   cout<<"何がしたい？"<<endl;
   cout<<"1.名簿追加,2.名簿一覧,3.終了,4.,5.,6.,))"<<endl;
   cin>>a;
   if(a==1){
      m.Appenddata();
   }
   else if(a==2){
      m.Showdata();
   }
   
   m.Savedata();
   return 0;
}
