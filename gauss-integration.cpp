#include<iostream>
#include<cmath>
using namespace std;
double c[10],p[10];
int k;
double fi(double u,double x1,double x2){
	int i;
	double x=x1+x2*u;
	double res=0;
	for(i=0;i<k;i++){
		res+=c[i]*pow(x,p[i]);
	}
	return res;
}
int main(){
	int i;
	cout<<"Enter the number of x-terms in equation : ";
	cin>>k;
	for(i=0;i<k;i++){
		cout<<"Enter the value of constant and power of x-term "<<i+1<<" :\n";
		cin>>c[i]>>p[i];
	}
	double a,b,n;
	cout<<"Enter the lower and upper limits :\n";
	cin>>a>>b;
	cout<<"Enter the 'n' value (2/3/4) : ";
	cin>>n;
	double dx=(b-a)/2;
	double x1=(b+a)/2;
	double x2=(b-a)/2;
	double u[4],w[4];
	if(n==2){
		u[0]=0.5773502;
		u[1]=-0.5773502;
		w[0]=1;
		w[1]=1;
	}
	else if(n==3){
		u[0]=0;
		u[1]=0.77459602;
		u[2]=-0.77459602;
		w[0]=0.888;
		w[1]=0.5555;
		w[2]=0.5555;
	}
	else if(n==4){
		u[0]=0.33999810436;
		u[1]=-0.33999810436;
		u[2]=0.86113631;
		u[3]=-0.86113631;
		w[0]=0.6521451;
		w[1]=0.6521451;
		w[2]=0.3478585;
		w[3]=0.3478585;
	}
	double eq=0;
	for(i=0;i<n;i++){
		eq+=w[i]*fi(u[i],x1,x2);
	}
	eq*=dx;
	cout<<eq;
}
