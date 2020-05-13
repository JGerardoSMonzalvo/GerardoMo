#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

void Domain( double a, double b, int n, double D[])
{
	D[0]=(b-a)/n;
	for(int i=0; i<=n ; i ++)
		D[i+1]=a+(b-a)*i/n;
}

double LS( int n, double D[] , double R)
{
	for(int i=1; i<=n ; i++)
		R+=sin(D[i])*D[0];
	return R;
}
double RS( int n, double D[] , double R)
{
	for(int i=2; i<=n+1 ; i++)
		R+=sin(D[i])*D[0];
	return R;
}

int main() {
	double R=0;
	double a=0;
	double b=M_PI;
	int n=100000;
	double D[2*n];
	
	//Escoger y evaluar la función con todo y su intervalo.
	
	Domain(a,b,n,D);
	cout << LS(n,D,R) << endl;	
	cout << RS(n,D,R) << endl;	
	cout << LS(n,D,R) << endl;	
		
	return EXIT_SUCCESS;
}
