#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


void find_base(int zez[],int v, int L, int R, int a, int b,int &maxy) //'v' jest numerem węzła w drzewie
{
    if (L == a && R == b) {
        if (zez[v]>maxy){
            maxy=zez[v];
        }
        return;
    }
    
    int mid = (a + b - 1) / 2;
    if (R <= mid) {
        find_base(zez,2 * v, L, R, a, mid, maxy);
    } else if (L > mid) {
        find_base(zez,2 * v + 1, L, R, mid + 1, b,maxy);
    } else {
        find_base(zez,2 * v, L, mid, a, mid,maxy);
        find_base(zez,2 * v + 1, mid + 1, R, mid + 1, b,maxy);
    }
}



int main() {
    void find_base(int zez[],int v, int L, int R, int a, int b,int &maxy);
    int n,m;
    
    cin>>n>>m;
    
    int pow=1;
    
    while (true){
        if (pow>=n){
            break;
        }
        pow*=2;
    }
 
    
    int zez[2*pow];
    
    //wczytaj dane
    for(int i=0;i<n;i++){
        
        cin>>zez[i+pow];
        
    }
    // zbuduj drzewko
    
    int first=pow;
    int tracker=n;
    while(tracker!=1){
        
        first/=2;

        
        for(int j=0;j<tracker/2+tracker%2;j++){
            
       
            zez[j+first]=max(zez[2*(first+j)], zez[2*(first+j)+1]);
                
            
        }
        
        tracker=tracker/2+tracker%2;
    }
    
    
    if (n>1){
        zez[1]=max(zez[2],zez[3]);
    }
   
    // commands
    
    
    string command;
    int outcomes[m];
    int maxis=0;
    for(int i=0;i<m;i++){
        
        cin>>command;
        
        if (command=="UPDATE"){
            
            int what, how;
            
            cin>>what>>how;
            
            
            zez[pow+what-1]=how;
            
            
            if(what==n && n%2==1){
                
                int tracker=pow+what-1;
                
                while(tracker!=1){
                    
                    zez[tracker/2]=how;
                    tracker/=2;
                }
            }
            
            else{
                
                int tracker=pow+what-1;
                
                while(tracker!=1){
                    
                    if(tracker%2==0){
                        
                        zez[tracker/2]=max(zez[tracker],zez[tracker+1]);
                    }
                    else{
                        
                        zez[tracker/2]=max(zez[tracker],zez[tracker-1]);
                        
                    }
                    tracker/=2;
                    
                }
            }
            zez[1]=max(zez[2],zez[3]);
        }
        
        if(command=="MAX"){
            
            int mini, maxi;
            
            cin>>mini>>maxi;
            
            int maxy=zez[pow+mini-1];
            
            find_base( zez,1, pow+mini-1, pow+maxi-1, pow, 2*pow-1,maxy);
   
            outcomes[maxis]=maxy;
            maxis++;
            
        }
        
        
    }
    
    
    for(int i=0;i<maxis;i++){
        
        cout<<outcomes[i]<<endl;
    }
    
    return 0;
}
