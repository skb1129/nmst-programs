#include<stdio.h>
//GAUSS ELIMINATION METHOD WITHOUT PARTIAL PIVOTING
int main(){
	float num[100][100]={0},res[100]={0},x=0;
	int n,i,j,k;
	printf("Enter the number of variables : ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the constants of equation %d :\n",i+1);
		for(j=0;j<=n;j++)
			scanf("%f",&num[i][j]);
	}
	for(k=0;k<n-1;k++){
		for(i=1;i+k<n;i++){
			x=num[i+k][k]/num[k][k];
			for(j=0;j<=n;j++){
				num[i+k][j+k]-=num[k][j+k]*x;
			}
		}
	}
	printf("Upper Triangular Matrix :\n\n");
	for(i=0;i<n;i++){
		for(j=0;j<=n;j++)
			printf("%f\t",num[i][j]);
		printf("\n");
	}
	for(i=n-1;i>=0;i--){
		res[i]=num[i][n];
		for(j=i+1;j<n;j++){
			res[i]-=num[i][j]*res[j];
		}
		res[i]/=num[i][i];
	}
	for(i=0;i<n;i++){
		printf("\nVar%d: %f",i+1,res[i]);
	}
}
