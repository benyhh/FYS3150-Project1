#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <math.h>
using namespace std;

int wfiletime(int n, double time, string filename)
{
	ofstream results;
	results.open (filename, ios_base::app);
	results << n << " " << time << endl;

	return 0;
}
int wfile(int n, 	double *x, double *v)
{
	int pow = (int)log10(n);
	string filename = "num_result_pow" + to_string(pow) + ".txt";
	ofstream results;
	results.open (filename);
	results << "x           v" << endl;
	//cout << pow << "  " << sizeof(x) << endl;
	for (int i = 0; i < n+1; i++)
	{
		results << x[i] << " " << v[i] << endl;
	}
	results.close();
	return 0;
}

int error(double *x,double *v,int n)
{
	double u[sizeof(x)];
	double max_err = 0;
	double err;
	for (int i = 0; i < sizeof(x); i++)
	{
		u[i] = 1 - (1 - exp(-10))*x[i] - exp(-(double)10*x[i]);
		err = log10(abs((v[i]-u[i])/u[i]));
		if (err > max_err)
		{
			max_err = err;
		}
	}
	cout << "Max error for n = " << n << ": " << max_err << endl;
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
	//Filling a, b and c
	for (int i = 0; i < n; i++)
	{
		a[i] = c[i] = -1;
		b[i] = -2;
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
	}

	v[n-1] = d_tilde[n-1]/b_tilde[n-1];

	for (int i = n-2; i > 0; i--)
	{
		v[i] = (d_tilde[i]-c[i]*v[i+1])/b_tilde[i];
	}
	//Write to file
	wfile(n,x,v);

	delete[] x;
	delete[] v;
	delete[] a;
	delete[] b;
	delete[] c;
	delete[] d;
	delete[] b_tilde;
	delete[] d_tilde;

	return 0;
}
int solve_spec(int n)
{
	double *x = new double[n+1];
	int a = -1;
	int b = 2;
	int c = -1;
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

	//Initial values
	b_tilde[0] = b;
	d_tilde[0] = d[0];
	v[0]=0;
	v[n]=0;
	//Solving algorithm

	int ac = a*c;

	double start = clock();
	for (int i = 1; i < n; i++)
	{
		b_tilde[i] = b - ac / b_tilde[i-1];
		d_tilde[i] = d[i] - a * d_tilde[i-1] / b_tilde[i-1];
	}
	double finish = clock();
	double time = (finish - start)/CLOCKS_PER_SEC;

	wfiletime(n, time, "times_spec.txt");

	v[n-1] = d_tilde[n-1]/b_tilde[n-1];

	for (int i = n-2; i > 0; i--)
	{
		v[i] = (d_tilde[i]-c*v[i+1])/b_tilde[i];
	}
	//Write to file
	//wfile(n,x,v);
	error(x,v,n);


	delete[] x;
	delete[] d;
	delete[] v;
	delete[] b_tilde;
	delete[] d_tilde;

	return 0;
}

int main(int argc, char* argv[])
{
	double time = clock();
	/*
	for (int i=1; i<6; i++)
	{
		double start = clock();
		solve(pow(10,i));
		double finish = clock();
		double time = (finish - start)/CLOCKS_PER_SEC;
		cout << "Time used for n = 10^" << i << ": " << time << "s" <<endl;
	}
*/

	for (int i=1; i<7; i++)
	{
		//double start = clock();
		solve(pow(10,i));
		//double finish = clock();
		//double time = (finish - start)/CLOCKS_PER_SEC;
		//cout << "Spec: Time used for n = 10^" << i << ": " << time << "s" <<endl;
	}

	double tot_time = (clock() - time)/CLOCKS_PER_SEC;
	cout << "Total runtime = " << tot_time << "s" << endl;
	return 0;
}
