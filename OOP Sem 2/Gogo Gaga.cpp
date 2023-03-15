#include<iostream>
#include<cmath>
using namespace std;
int PowMod(int a,int b,int m){
    int res=1;
    a=a%m;
    while(b>0){
        if(b&1)
            res=(res*a)%m;
        a=a*a;
        b=b>>1;}
    return res;}
int main(){
	string s[]={"APPLES AND ORANGES"};
	int temp[20];
	int k=PowMod(3, 644, 40);
	for(int i=0;i<18;i++){
		temp[i]=s[i]+k;}
	for(int i=0;i<s.length();i++){
		cout<<"Encrypted Message = "s[i];}}
