#include <iostream>
using namespace std;

int binpow(int a, int n){
    
    if (n==1){
        
        return a;
    }
    
    else if (n%2==0){
        
        return (binpow(a,n/2)*binpow(a,n/2))%10000;
    }
    else{
        
        return (a* binpow(a,n-1))%10000;
    }
}


int main() {
    int binpow (int a, int n);
    int n;
    cin>>n;
    
    int as[n];
    int ns[n];
    
    for(int i =0; i<n;i++){
        
        cin>>as[i];
        cin>>ns[i];
        
    }
    
    for(int i =0; i<n;i++){
        
        cout<<binpow(as[i]+1,ns[i])%10000<<endl;
        
    }

    return 0;
}
