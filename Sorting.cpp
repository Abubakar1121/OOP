#include<iostream>
using namespace std;
int main(){
	int A[]={3,5,1,4,6,2,11,0};
	for(int i=0;i<8/2;i++){
		for (int j=0;j<8;i++){
			swap(A[j],A[j+1]);
		}
	}
	for (int j=0;j<8;j++){
		cout<<A[j]<<' ';	
	}
	return 0;
}
