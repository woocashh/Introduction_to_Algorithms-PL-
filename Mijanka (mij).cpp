#include <iostream>

using namespace std;

int main() {
    
    
    int n;
    cin >>n;
    int tab[n];
    long long int sum=0;
    long long int out=0;
    
    for(int i=0;i<n;i++){
        
        cin>>tab[i];
        
    }
    
    for(int i=0;i<n;i++){
        
        if(tab[i]==1){
            
            out+=sum;
        }
        else{
            
            sum++;
        }
        
    }

    cout<<out;

    return 0;
}
