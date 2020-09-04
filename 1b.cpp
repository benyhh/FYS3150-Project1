#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


int main(int argc, char* argv[])
{
	int n = 1000;
	vector <double> x(n+1);
	vector <double> a(n,-1);
	vector <double> b(n,2);
	vector <double> c(n,-1);
	vector <double> d(n);
	vector <double> v(n);
	vector <double> b_tilde(n);
	vector <double> d_tilde(n);

	double h = 1/(double(n)+1);
	double hh = 100*h*h;
	for (int i=0; i<=n; i++)
	{
			x[i]=i*h;
			d[i]=hh*exp(-10*x[i]);
	}

	b_tilde[0]=b[0];
	d_tilde[0] = d[0];
	v[0]=0;
	for (int i = 1; i<n; i++)
	{
		b_tilde[i] = b[i]-a[i-1]*c[i-1]/b_tilde[i-1];
		d_tilde[i] = d[i]-a[i-1]*d_tilde[i-1]/b_tilde[i-1];
		v[i] = (d_tilde[i-1]-b_tilde[i-1]*v[i-1])/c[2];
	}

	return 0;

}
