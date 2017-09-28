#include<stdio.h>
//NEWTON-RAPHSON METHOD
float a,b,c,d,a2,b2,c2;
float f(float x){
	float res=a*x*x*x+b*x*x+c*x+d;
	return res;
}
float fd(float x){
	a2=3*a;b2=2*b;
	float res=a2*x*x+b2*x+c;
	return res;
}
int main(){
	int n,i;
	float x,y,k[100];
	printf("Enter the constants of biquadratic equation :\n");
	scanf("%f%f%f%f",&a,&b,&c,&d);
	printf("1.Enter the limits\n2.Enter the root\n");
	scanf("%d",&n);
	if(n==1){
		printf("Enter the limits :\n");
		scanf("%f%f",&x,&y);
		if(f(x)*f(y)>=0){
			printf("Wrong Input. Restarting!");
			main();
		}
		k[0]=(x+y)/2;
	}
	else if(n==2){
		printf("Enter the root : ");
		scanf("%f",&k[0]);
	}
	printf("Enter the number of iterations : ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		k[i+1]=k[i]-f(k[i])/fd(k[i]);
	}
	printf("Root : %f",k[n-1]);
	return 0;
}
