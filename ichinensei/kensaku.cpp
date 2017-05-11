#include <iostream>
#include <string>
#include<math.h>
#include<vector>
#include<fstream>
#include<list>
#include<algorithm>
using namespace std;

int main(){
   string temp;
   vector<string> data;
   
   cout<<"開くファイル"<<endl;
   cin>>temp;
   
   ifstream f(temp.c_str());
   while(getline(f,temp)){   
   //f>>tempを1行ずつ読み込めるようにしたものがgetline(f,temp)  
   //ex:getline(cin,n)
      data.push_back(temp);
      cout<<temp<<endl;
   }
   
   cout<<"検索する文字入力"<<endl;
   cin>>temp;
   for(vector<string>::size_type i; i<data.size();i++ ){
      if(data[i].find(temp) != string::npos){
	 cout<<i+1<<": "<<data[i]<<endl;
      }
   }
   
   cout<<endl;
   
   return 0;
}
