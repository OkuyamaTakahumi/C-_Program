#include <iostream>
#include <string>
#include<math.h>
#include<vector>
#include<list>
#include<fstream>
#include<algorithm>
#include <unordered_set>
using namespace std;

int main(){
//--------------VECTOR------------------------------------------
  //（C++11からのやり方）
  vector<int> data{4, 6, 5};     // データ列を指定して動的配列を生成
  cout<<data.size();//要素数の取得 : 3
  //前のやり方（元データから生成）
  int org_data[] = {4, 6, 5};//元データ
  int org_data2[30];//元データ
  //vectorAの最初のイテレータ -> A.begin()
  //配列Aの最初のイテレータ -> A -> 配列名が最初のイテレータになる
  vector<int> data2(org_data, org_data + 3);

  vector<int> data3(124);//int型で初期要素数123のベクトルの宣言
  vector<int> data4(data3);//コピーコンストラクタ
  vector<int> data5(10, 5);//要素数10全ての要素の値5で初期化

  //vector<vector<型>> オブジェクト名; で２次元配列を生成
  vector<vector<int> > data6={{1,2,3},{4,5,6}};
  cout<<data6.size(); //2
  data6[1].push_back(7);
  cout<<data6[1][3]<<endl;//7

  vector<int> vct{3, 10, 2, 5, 4};
  //vector<int>::iterator v_itr;// vector<int> の要素へのイテレータ
  //v_itr=vct.begin();//最初の要素を示すイテレータ
  auto v_itr = vct.begin();
  ++v_itr;// 次の要素に移動
  cout<<*v_itr;  //v_itrの指す値を表示 : 1
  *v_itr = 1;    // 二番めの要素の値を 9 に変更
  cout<<*v_itr<<endl;

  cout<<"vct"<<endl;
  for(vector<int>::iterator v_itr = vct.begin(); v_itr != vct.end(); ++v_itr) {
    cout<<*v_itr<<" "; //イテレータの指す要素を参照
  }
  cout<<endl;

  cout<<"vct-SORT"<<endl;
  sort(vct.begin(),vct.end());
  for(vector<int>::iterator v_itr = vct.begin(); v_itr != vct.end(); ++v_itr) {
    cout<<*v_itr<<" "; //イテレータの指す要素を参照
  }
  cout<<endl;

  cout<<"REVERSE(vct.begin()+1,vct.end()-1)"<<endl;
  reverse(vct.begin()+1,vct.end()-1);
  for(vector<int>::iterator v_itr = vct.begin(); v_itr != vct.end(); ++v_itr) {
    cout<<*v_itr<<" "; //イテレータの指す要素を参照
  }
  cout<<endl;
  //itrを宣言したベクトルの型がクラスの場合itr->Setname(h);のようにできる

  //--------------LIST--------------------------------------------
    list<char> L;

    L.push_front('b');
    L.push_back('c');
    L.push_front('a');//[a,b,c]

    cout<<L.front(); //a
    cout<<L.back(); //c

    L.pop_front(); //a
    L.push_back('d'); //[b,c,d]

    cout<<L.front(); //b
    cout<<L.back(); //d
    cout<<L.size()<<endl; //3

    list<int> lst{3, 1, 9, 4};

    //list<int>::iterator itr = lst.begin();
    //↓↓書き直せる
    auto l_itr = lst.begin();
    l_itr++;
    lst.insert(l_itr,2);//[b,c,e,d]
    l_itr++;               // 3番目の要素に移動
    lst.erase(l_itr);

    cout<<"lst"<<endl;
    for(list<int>::iterator it=lst.begin();it!=lst.end();it++){
      //cout<<L[it]<<" " -> 間違い
      cout << *it <<" ";
    }
    cout<<endl;

    cout<<"lst-SORT"<<endl;
    lst.sort();//グローバルなsort関数が使わずlistのメンバ関数のsortを使う
    for(list<int>::iterator it=lst.begin();it!=lst.end();it++){
      //cout<<L[it]<<" " -> 間違い
      cout << *it <<" ";
    }
    cout<<endl;


  //--------------lower_bound--------------------------------------------
  int lowerArray[14] = {1,2,3,3,4,5,5,5,6,7,8,9,9,10};

  int *pos;
  int *pos2;


  //3つ目の引数(value)の値以上になる先頭の要素のイテレータを返す
  pos = lower_bound(lowerArray,lowerArray+14,6);
  pos2 = lowerArray;
  cout<<*pos<<" "; //イテレータの値を返す -> 6
  cout<<*pos2<<" "; //イテレータの値を返す -> 1

  //cout<<pos<<endl;
  //↓↓
  int idx = distance(lowerArray,pos);//ポインタ間の距離を返す
  //配列の名前は最初の要素のアドレスを表す
  cout<<idx<<endl;

  return 0;
}
