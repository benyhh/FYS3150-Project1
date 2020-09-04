#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

int wfile(int n, 	vector <double> x, 	vector <double> v)
{
	int pow = (int)log10(n);
	string filename = "num_result_pow" + to_string(pow) + ".txt";
	ofstream results;
	results.open (filename);
	results << "x           v" << endl;
	for (int i = 0; i < x.size(); i++)
	{
		results << x[i] << " " << v[i] << endl;
	}
	results.close();
	return 0;
}

int solve(int n)
{
	vector <double> x(n+1);
	vector <double> a(n,-1);
	vector <double> b(n,2);
	vector <double> c(n,-1);
	vector <double> d(n);
	vector <double> v(n+1);
	vector <double> b_tilde(n);
	vector <double> c_tilde(n);
	vector <double> d_tilde(n);

	double h = 1/(double(n)+1);
	double hh = 100*h*h;

	for (int i=0; i<n+1; i++)
	{
			x[i]=i*h;
			d[i]=hh*exp(-10*x[i]);
	}

	//Initial values
	b_tilde[0] = b[0];
	d_tilde[0] = d[0];
	v[0]=0;
	v[n]=0;
	//Solving algorithm
	for (int i = 1; i < n; i++)
	{
		b_tilde[i] = b[i] - a[i-1] * c[i-1] / b_tilde[i-1];
		d_tilde[i] = d[i] - a[i-1] * d_tilde[i-1] / b_tilde[i-1];
		c_tilde[i] = c[i]*a[i]/b[i];
	}

	v[n-1] = d_tilde[n-1]/b_tilde[n-1];

	for (int i = n-2; i > 0; i--)
	{
		v[i] = (d_tilde[i]-c_tilde[i]*v[i+1])/b_tilde[i];
		cout << v[i] << endl;
	}
	//Write to file
	wfile(n,x,v);

	return 0;
}


int main(int argc, char* argv[])
{
	for (int i=1; i<5; i++)
	{
		solve(pow(10,i));
	}
	return 0;
}
