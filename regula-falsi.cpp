#include<stdio.h>
//REGULAFALSI METHOD
float a,b,c,d;
float f(float x){
	float res=a*x*x*x+b*x*x+c*x+d;
	return res;
}
int main(){
	int n,i;
	float x,y,k;
	printf("Enter the constants of biquadratic equation :\n");
	scanf("%f%f%f%f",&a,&b,&c,&d);
	printf("Enter the limits :\n");
	scanf("%f%f",&x,&y);
	if(f(x)*f(y)>=0){
		printf("Wrong Input. Restarting!");
		main();
	}
	else{
		printf("Enter the number of iterations : ");
		scanf("%d",&n);
		for(i=0;i<n;i++){
			k=(x*f(y)-y*f(x))/(f(y)-f(x));
			if(f(k)*f(x)<0){
				y=k;
			}
			else if(f(k)*f(y)<0){
				x=k;
			}
		}
		printf("Root : %f",k);
	}
	return 0;
}
