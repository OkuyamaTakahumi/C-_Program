#include <iostream>
#include <string>
#include<math.h>
#include<vector>
#include<fstream>
#include<list>
#include<algorithm>
using namespace std;

/////////////////////////////////////////////////////////////
class Hito{
   string name;
   string phone;
public:
   void Setname(string n){
      name = n;
   }
   string Getname() const{
      return name;
   }

   void Setphone(string n){
      phone = n;
   }
   string Getphone() const{
      return phone;
   }
};
///////////////////////////////////////////////////////////////
bool operator <(const Hito& a, const Hito& b){
   return a.Getname() < b.Getname();
} //ソートするものを定義

//////////////////////////////////////////////////////////////////
class Meibo{
   vector<Hito> data;
   public:
   void Appenddata();
   void Showdata(); 
   void Savedata();
   void Readdata();
   void Delete();
   void Namechange();
   void Insert();
   void Sort();

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
      cout<<i+1<<"番目"<<endl;
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
   }
   f<<"xxx"<<endl;
   
}

void Meibo::Readdata(){
   ifstream f2("meibo.txt");
   Hito h;
   string n;
   while(1){
      f2>>n;
      if(n=="xxx"){
	 break;
      }
      h.Setname(n);
      f2>>n;
      h.Setphone(n);
      data.push_back(h);
   }
}

void Meibo::Delete(){
   string name;
   string a;
   int b=0;
   cout<<"削除する人の名前を入力"<<endl;
   cin>>name;
   for(vector<Hito>::size_type i=0;i<data.size();i++){
      if(name==data[i].Getname()){
	 b=1;
	 cout<<"削除しても良いですか？(y or n))"<<endl;
	 cin>>a;
	 if(a=="y"){
	    data.erase(data.begin()+i);
	 }
      }
   }
   if(b==0){
      cout<<"そんな人いないよ！！"<<endl;
   }
   cout<<endl;
}

void Meibo::Namechange(){
   Hito h;
   string name;
   string a;
   int b=0;
   cout<<"変更する人の名前を入力"<<endl;
   cin>>name;
   for(vector<Hito>::size_type i=0;i<data.size();i++){
      if(name==data[i].Getname()){
	 b=1;
	 cout<<"何に変更しますか？"<<endl;
	 cin>>a;
         h.Setname(a);
	 h.Setphone(data[i].Getphone());
         data[i]=h;
      }
   }
   if(b==0){
      cout<<"そんな人いないよ！！"<<endl;
   }
   cout<<endl;
}

void Meibo::Insert(){
   int a;
   Hito h;
   string n;
   cout<<""<<endl;
   cin>>a;
   if(a>data.size()){
      return;
   }
   cout<<"名前入力"<<endl;
   cin>>n;
   h.Setname(n);
   cout<<"電話番号入力"<<endl;
   cin>>n;
   h.Setphone(n);
   data.insert(data.begin()+a,h);
}

void Meibo::Sort(){
   sort(data.begin(),data.end());
   cout<<"名前を整列させました"<<endl<<endl;
}


/////////////////////////////////////////////////////////////////
class Sagyou{
   Meibo m;
public:
   void Play();
};

void Sagyou::Play(){
   int a;
   m.Readdata();
   while(1){
      cout<<"何がしたい？"<<endl;
      cout<<"1.名簿追加,2.名簿一覧,3.削除,4.名前変更,5.名簿挿入,6.名前じゅんに並べ替え,7.終了))"<<endl;
      cin>>a;
      if(a==1){
         m.Appenddata();
      }
      else if(a==2){
         m.Showdata();
      }
      else if(a==3){
         m.Delete();
      }
      else if(a==4){
         m.Namechange();
      }
      else if(a==5){
         m.Insert();
      }
      else if(a==6){
         m.Sort();
      }
      else if(a==7){
         break;
      }

      else{
	 cout<<"ちゃんと入力してください"<<endl;
      }
   }
   m.Savedata();
}

/////////////////////////////////////////////////////////////////

int main(){
   srand((unsigned)time(NULL));

   Sagyou s;
   s.Play();
		
   return 0;
}
