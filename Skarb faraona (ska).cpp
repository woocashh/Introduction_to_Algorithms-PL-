#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int zes;
    cin>>zes;
    for(int zs=0;zs<zes;zs++){
        int ilP, poj;
        cin>>ilP>>poj;
        vector<int>Wart,Masa;
        for(int i=0;i<ilP;i++){
            int a, b;
            cin>>a>>b;
            Masa.push_back(a);
            Wart.push_back(b);
        }
        vector<vector<int> > A;
        vector<int> filler;
        filler.assign(poj+1, 0);
        A.assign(ilP+1, filler);
        for(int i=1;i<=ilP;i++){
            for(int j = 1;j<=poj;j++){
                if(j-Masa[i-1]>=0)
                    A[i][j]=max(A[i-1][j], A[i-1][j-Masa[i-1]]+Wart[i-1]);
                else
                    A[i][j]=A[i-1][j];
            }
        }
        cout<<A[ilP][poj]<<endl;
    }
    }
