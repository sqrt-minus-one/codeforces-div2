#include <bits/stdc++.h>
using namespace std;

int power(long long x, unsigned int y, int p)  
{  
    long long res = 1;
  
    x = x % p;
   
    if (x == 0) return 0;
  
    while (y > 0)  
    {
        if (y & 1)  
            res = (res*x) % p;  
        y = y>>1;
        x = (x*x) % p;  
    }  
    return res;  
}
int main() {
    long long n,p; cin>>n>>p; 
    cout<< (power(3,n,p)*1ll + p*1ll-1ll)%p;
    return 0;
}