#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

int wfile(int n, 	double *x, double *v)
{
	int pow = (int)log10(n);
	string filename = "num_result_pow" + to_string(pow) + ".txt";
	ofstream results;
	results.open (filename);
	results << "x           v" << endl;
	for (int i = 0; i < n+1; i++)
	{
		results << x[i] << " " << v[i] << endl;
	}
	results.close();
	return 0;
}

int solve(int n)
{
	double *x = new double[n+1];
	int *a = new int[n];
	int *b = new int[n];
	int *c = new int[n];
	double *d = new double[n];
	double *v = new double[n+1];
	double *b_tilde = new double[n];
	double *d_tilde = new double[n];

	double h = 1/(double(n)+1);
	double hh = 100*h*h;

	for (int i=0; i<n+1; i++)
	{
			x[i]=i*h;
			d[i]=hh*exp(-10*x[i]);
	}

	for (int i = 0; i < n; i++)
	{
		a[i]=c[i]=-1;
		b[i] = 2;
	}

	//Initial values
	b_tilde[0] = b[0];
	d_tilde[0] = d[0];
	v[0] = v[n] = 0;



	//Solving algorithm
	for (int i = 1; i < n; i++)
	{
		b_tilde[i] = b[i] - a[i-1] * c[i-1] / b_tilde[i-1];
		d_tilde[i] = d[i] - a[i-1] * d_tilde[i-1] / b_tilde[i-1];
	}

	v[n-1] = d_tilde[n-1]/b_tilde[n-1];

	for (int i = n-2; i > 0; i--)
	{
		v[i] = (d[i]- c[i]*v[i+1])/b_tilde[i];
	}
	//Write to file
	wfile(n,x,v);

	delete [] a;
	delete [] b;
	delete [] c;
	delete [] d;
	delete [] b_tilde;
	delete [] d_tilde;
	delete [] x;
	delete [] v;

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
