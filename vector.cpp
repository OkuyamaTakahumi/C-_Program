#include <iostream>
#include <string>
#include<math.h>
#include<vector>
#include<fstream>
#include<list>
#include<algorithm>
#include <unordered_set>
using namespace std;

/////////////////////////////////////////////////////////////
int main(){
   //（C++11からのやり方）
   vector<int> data={4,6,5};
   //cout<<data.size()<<endl;//要素数の取得

   //前のやり方（元データから生成）
   int org_data[] = {4, 6, 5};//元データ
   vector<int> data2(org_data, org_data + 3);


   vector<int> data3(124);//int型で初期要素数123のベクトルの宣言
   vector<int> data4(data3);//コピーコンストラクタ

   vector<int> data5(10, 5);//要素数10全ての要素の値5で初期化

   vector<vector<int> > data6={{1,2,3},{4,5,6}};
   //vector<vector<型>> オブジェクト名; で２次元配列を生成
   //cout<<data6.size()<<endl; //=2

   data6[1].push_back(7);
   //cout<<data6[1][3]<<endl;//=7

   vector<int>::iterator itr;// vector<int> の要素へのイテレータ
   itr=data.begin();//最初の要素を示すイテレータ
   ++itr;// 次の要素に移動
   //cout<<*itr<<endl;//itrの指す値を表示（6）
   *itr = 9;    // 二番めの要素の値を 9 に変更
   //cout<<*itr<<endl;

   for(vector<int>::iterator itr = data.begin(); itr != data.end(); ++itr) {
      //cout<<*itr<<endl; //イテレータの指す要素を参照
   }

//itrを宣言したベクトルの型がクラスの場合itr->Setname(h);のようにできる
   return 0;
}
