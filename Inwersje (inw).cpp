#include <iostream>
using namespace std;



void merge(int arr[], int l, int m, int r, long long int &linw)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    
    /* create temp arrays */
    int L[n1], R[n2];
    
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            linw+=n1-i;
        }
        k++;
    }
    
    /* Copy the remaining elements of L[], if there
     are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    /* Copy the remaining elements of R[], if there
     are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
 sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r,long long &linw)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        
        // Sort first and second halves
        mergeSort(arr, l, m,linw);
        mergeSort(arr, m+1, r,linw);
        
        merge(arr, l, m, r,linw);
    }
}



int main() {
    void merge(int arr[], int l, int m, int r, long long int &linw);

    long long int linw=0;
    
    
    int n;
    
    cin>>n;
    
    int tab[n];

    
    for(int i=0;i<n;i++){
        
        
        cin>>tab[i];
    }
    
    
    mergeSort(tab,0,n-1,linw);
    
    
    for(int i=0;i<n-1;i++){
        
        cout<<tab[i]<<" ";
    }
    
    cout<<tab[n-1]<<endl;
    cout<<linw;
    
    
    return 0;
}
