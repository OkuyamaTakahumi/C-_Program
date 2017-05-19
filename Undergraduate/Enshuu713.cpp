//============================================================================
// Name        : Enshuu713.cpp
// Author      : Tad
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	const int m = 2;
	const int n = 2;

	int a[m][n];
	int b[m][n];
	int c[m][n];


	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> a[i][j];
		}
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >>b[i][j];
		}
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout << a[i][j];
		}
		cout << endl;
	}


	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout << b[i][j] << " ";
		}
		cout << endl;
	}


	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				c[i][j] = a[i][k] * b[k][j];
			}
		}
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
