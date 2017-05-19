//Viｍで練習してます！！
#include <iostream>
#include <string>
#include<math.h>
using namespace std;



/////////////////////////////////////////////////////////////////


class Man{

   string name;

public:

   void Setname(string n){
      name = n;
   }

   string Getname(){
      return name;
   }

   virtual void Inputdata();
   virtual void Showdata();
   virtual ~Man(){}
   virtual double Nenshu() = 0;   
};  //クラスの終わりには ; をつける

void Man::Inputdata(){   //virtualいらない
   cout<<"Input name"<<endl;
   cin>>name;
}

void Man::Showdata(){
   cout<<"Name is "<<name<<endl;
}


//////////////////////////////////////////////////////////////////

class SMan : public Man{  //継承した

   int salary;

public:

   void Setsalary(int s){
      salary = s;
   }

   int Getsalary(){
      return salary; 
   }

   void Inputdata();
   void Showdata();

   double Nenshu(){
      return salary*12;
   }
};

void SMan::Inputdata(){
   Man::Inputdata();           //継承した
   cout<<"Input salary"<<endl;
   cin>>salary;
}

void SMan::Showdata(){
   Man::Showdata();
   cout<<"Nenshu is "<<Nenshu()<<endl;
}

//////////////////////////////////////////////////////////////////

class SManplus : public SMan{
   int plus;                   //ボーナス
public:
   void Setplus(int b){
      plus=b;
   }
   int Getplus(){
      return plus;
   }

   void Inputdata();
   void Showdata();
   double Nenshu(){
      return SMan::Nenshu() + plus;
   }
};

void SManplus::Inputdata(){
   SMan::Inputdata();
   cout << "Input Bonas "<<endl;
   cin>>plus;
}
void SManplus::Showdata(){
   Man::Showdata();  //SManだと年収が2回出てしまう
   cout<<"Nenshu is "<<Nenshu()<<endl;
}

//////////////////////////////////////////////////////////////////
class RMan : public Man{
   double tyokin;
public:
   void Settyokin(int b){
      tyokin = b;
   }
   int Gettyokin(){
      return tyokin;
   }
   void Inputdata();
   void Showdata();
   double Nenshu(){
      return tyokin*0.01;
   }
};
void RMan::Inputdata(){
   Man::Inputdata();
   cout<<"貯金は？"<<endl;
   cin>>tyokin;
}
void RMan::Showdata(){
    Man::Showdata();
    cout<<"Nenshu is "<<Nenshu()<<endl;
}

//////////////////////////////////////////////////////////////////
int main(){
   int num;
   cout<<"num?"<<endl;
   cin>>num;
   int sum=0;
   char ans;
   Man *h[100]  ;
   
   for(int i=0;i<num;i++){
      cout<<i+1<<"人目はSMan?,RMan? s or r"<<endl;
      cin>>ans;
      if(ans=='r'){
         h[i]= new RMan;
      }
      
      else{
	 cout <<i+1<< "人目ボーナスある？ y or n"<<endl;
         cin >> ans;

         if(ans=='y'){
	    h[i] = new SManplus;
         }
         else {
	    h[i] = new SMan;
         } 
      }
      
      h[i] -> Inputdata();   //ややこしいがこの時h[i]はポインタ
   }

   for(int i=0;i<num;i++){
      cout<<"-----------------"<<endl;
      cout<<i+1<<"th,Man\'s data"<<endl;
      h[i]->Showdata();
      sum+=h[i]->Nenshu(); 
   }
   
   cout<<"-----------------"<<endl;
   
   cout<<"NenshuSum = "<<sum<<endl;

   for(int i; i<num; i++){
      delete h[i];
   }
}
