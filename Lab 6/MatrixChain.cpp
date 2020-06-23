// This program output the minimum number of operations required to perform the matrix chain multiplication.
#include <iostream>
#include <stdio.h>
#include <vector> // you may use the vector class to represent a matrix, for ex: vector<vector<int>> M;
#include <sys/time.h>
#include <climits>

using namespace std;

void PrintOptimalParens( vector<vector<int> > s, int i, int j)
{

	if (i == j)
		cout << "A" << i-1;
	else{
		cout << "(";
		PrintOptimalParens(s, i, s[i][j]);
		PrintOptimalParens(s, s[i][j]+1,j);
		cout << ")";
	}
}

void MatrixChainOrder(vector<int> p)
{

	int n = p.size();
	vector<vector<int> > m (n, vector<int> (n,0));	//keeps values inside
	vector<vector<int> > s (n, vector<int> (n,0));	//keeps track of the optimal order to multiple in

	for(int l = 2; l < n; l++){
		for(int i = 1; i < n-l+1; i++){
			int j = i +l -1;
			m[i][j] = 9999999; //really large number
			for(int k = i; k <= j-1; k++){
				int q = m[i][k] + m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j]){		
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}

	cout << m[1][n-1] << endl;
	PrintOptimalParens(s, 1, n-1);
	cout << endl;

	return;


}

int main(int argc,char **argv)
 {  

   // Get number of matrices in the input:
   int size;
   cin >> size;

   vector<int> matrice;

   int value;

   for(int i = 0; i < size+1; i++){		//fills values into matrix
   	cin >> value;
   	matrice.push_back(value);
   }


   MatrixChainOrder(matrice);

   // etc

 }

