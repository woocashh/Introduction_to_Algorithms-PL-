#include <iostream>
using namespace std;


int main() {
    
    int T;
    cin >> T;
    int tab[2*T];

    for(int i=0;i<2*T;i+=2){
        cin>>tab[i]>>tab[i+1];
    }

    bool tablica[2000001];
    
    for(int i = 2; i <= 2000000; i++){
        tablica[i] = true;}
    
    
    long long taby[2000001];
    taby[0]=0;
    taby[1]=0;
    

    for(int i = 2; i <= 2000000; i++){  // bierzemy kolejną liczbę i
        if (tablica[i]){
            
            taby[i]=taby[i-1]+i;
    
            for(int j = 2 * i; j <= 2000000; j = j + i)   // iterujemy się po wszystkich
                tablica[j] = false;
        }
        else{
            taby[i]=taby[i-1];
        }}
    
    
    for(int i=0;i<2*T;i+=2){
        

        cout<<taby[tab[i+1]]-taby[tab[i]-1]<<endl;}
        

    
    
    return 0;
}
