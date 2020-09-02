#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


int main(int argc, char* argv[])
{
	int n = 10;
	vector <double> x(n+1);
	vector <double> a(n,-1);
	vector <double> b(n,2);
	vector <double> c(n,-1);
	vector <double> v(n);
	vector <double> d(n);
	vector <double> b_tilde(n);
	vector <double> d_tilde(n);
	double h = 1/(double(n)+1);

	double hh = 100*h*h;
	for (int i=0; i<=n; i++)
	{
			x[i]=i*h;
			d_tilde[i]=hh*exp(-10*x[i]);
			cout << d_tilde[i] << endl;
	}

	//Lager nxn matrise A
	vector<vector<double>> A( n , vector<double> (n,0));
	A[0][0]=b[0]; A[0][1]=c[0];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ( j == i - 1)
			{
					A[i][j]=a[j];
					A[i][j+1]=b[j+1];
					A[i][j+2]=c[j+1];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	return 0;

}
