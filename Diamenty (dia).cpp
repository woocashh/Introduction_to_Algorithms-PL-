#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    int T,w,h;
    
    cin>>T;
    for (int i=0;i<T;i++){
        cin>>w>>h;
        
        int board[w][h];
        
        for(int j=0;j<h;j++){
            
            for(int k=0;k<w;k++){
                cin>>board[k][j];
            }
        }
        
        int maxi[w][h];
    
        for(int j=0;j<h;j++){
            
            for(int k=0;k<w;k++){
                
                if(k>0 && j>0){
                    
                    maxi[k][j]=max(maxi[k-1][j], maxi[k][j-1])+ board[k][j];
                    
                }
                else if(k>0){
                    
                    maxi[k][j]=maxi[k-1][j]+ board[k][j];
                }
                
                else if(j>0){
                    
                    maxi[k][j]=maxi[k][j-1]+ board[k][j];
                }
                else{
                    maxi[k][j]=0+ board[k][j];
                    
                }
            }
            
        }
        
        cout<<maxi[w-1][h-1]<<endl;
        

    }
    
    return 0;
}
