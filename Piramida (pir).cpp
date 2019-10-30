#include <iostream>
#include <string>

using namespace std;


int main() {
    
    int n;
    int k;
    
    cin>>n>>k;
    
    string pul;
    
    cin>>pul;
    
    int sum;

    
    if (n>=6){
        
        sum=1;
        bool flag=true;
        int last6[6];
        
        int count6=1;
        
        last6[6-count6]=1%k;;
        
        
        for(int i=n-2;i>n-7;i--){
            if (pul[i]=='1'){
                count6++;
  
                
                if (flag){
                    last6[6-count6]=1%k;
                    flag=false;
                }
                else{
                    sum*=2;
                    sum=sum%k;
                    last6[6-count6]=sum;
                }
            }
            
            else{
                count6++;
                last6[6-count6]=0;
            }
        }
        
        for(int j=n-7;j>=0;j--){
            count6++;

            if (count6>6){
                count6=1;
            }
            if (pul[j]=='1'){
                sum=0;
                for(int p=0;p<6;p++){
                    sum+=last6[p];
                    sum=sum%k;
                }
                last6[6-count6]=sum;
            }
            else{
                last6[6-count6]=0;
            }
    
        }
        
    
    }
    
    else{
        
        sum=1;
        bool flag=true;
        int last6[6];
        
        int count6=1;
        
        last6[6-count6]=1%k;;
        
        
        for(int i=n-2;i>=0;i--){
            if (pul[i]=='1'){
                count6++;
                if (flag){
                    last6[6-count6]=1%k;
                    flag=false;
                }
                else{
                    sum*=2;
                    sum=sum%k;
                    last6[6-count6]=sum;
                }
            }
            
            else{
                count6++;
                last6[6-count6]=0;
            }
        }
        
        
    }
    
    cout<<sum;
    

        
        
    return 0;
}
