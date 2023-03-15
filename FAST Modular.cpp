#include<bits/stdc++.h>
using namespace std;
int powerMod(int a, int b, int m)
{
    int res = 1;
    a = a % m;
    while(b>0)
    {
        if(b&1)
            res = (res * a) % m;
        
        a = a * a;
        b = b >> 1;
    }
    return res;
}
int main()
{
    cout<<"(2 pow 22) % 100 = "<<powerMod(2, 22, 100)<<endl;
    cout<<"(3 pow 9) % 5000 = "<<powerMod(3, 644, 40)<<endl;
    return 0;
}





