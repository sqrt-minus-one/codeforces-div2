#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef pair<double,int> pdi;

int main() {
    int n,t1,t2,k; cin>>n>>t1>>t2>>k;
    pdi mashroomH[n];
    for (int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        mashroomH[i].first=-max((a*t1)*(1.0-k*0.01)+b*t2, b*t1*(1.0-k*0.01)+a*t2);
        mashroomH[i].second=i+1;
    }
    sort(mashroomH,mashroomH+n);
    cout<<fixed;
    cout<<setprecision(2);
    for (int i=0;i<n;i++) cout<<mashroomH[i].second<<' '<<-mashroomH[i].first<<'\n';
    return 0;
}