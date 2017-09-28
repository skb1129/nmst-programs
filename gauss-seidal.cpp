#include<iostream>
using namespace std;
class matrix{
	float m[99][100],var[100]={0};
	int n,i,j;
	public:
		void input(){
			cout<<"Enter the number of equations : ";
			cin>>n;
			for(i=0;i<n;i++){
				cout<<"Enter the constants of equation "<<i+1<<endl;
				for(j=0;j<=n;j++){
					cin>>m[i][j];
				}
			}
			cout<<"Enter the initial value of variables"<<endl;
			for(i=0;i<n;i++){
				cin>>var[i];
			}
		}
		void display(){
			for(i=0;i<n;i++){
				cout<<var[i]<<endl;
			}
		}
		void iterate(){
			for(i=0;i<n;i++){
				var[i]=m[i][n]/m[i][i];
				for(j=0;j<n;j++){
					if(i!=j)
						var[i]=var[i]-m[i][j]*var[j]/m[i][i];
				}
			}
		}
};
int main(){
	int itr,i;
	matrix mat;
	mat.input();
	cout<<"Enter the number of iterations : ";
	cin>>itr;
	for(i=0;i<itr;i++){
		mat.iterate();
	}
	mat.display();
}
