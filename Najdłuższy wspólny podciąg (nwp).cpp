#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    string word1;
    string word2;
    cin>>word1>>word2;
    
    int P[word1.size()+1][word2.size()+1];
    
    
    for(int i=0;i<= word1.size();i++){

        P[i][0]=0;
    }
    
    for(int i=0;i<=word2.size();i++){
        
        P[0][i]=0;
    }
    
    for(int i=1;i<=word1.size();i++){
        
        for(int j=1;j<=word2.size();j++){
            
            if(word1[i-1]==word2[j-1]){
                
                P[i][j]=max(P[i-1][j],P[i][j-1]);
                
                if (P[i-1][j-1]+1>P[i][j]){
                    
                    P[i][j]=P[i-1][j-1]+1;
                }
            }
            else{
                
                P[i][j]=max(P[i-1][j],P[i][j-1]);
            }
        }
    }
    
    cout<<P[word1.size()][word2.size()];
        
        
    r
