#include <iostream>
#include <string>
#include <map>

using namespace std;

#include<stdio.h>

// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
 the pivot element at its correct position in sorted
 array, and places all smaller (smaller than pivot)
 to left of pivot and all greater elements to right
 of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
    
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
 low  --> Starting index,
 high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
         at right place */
        int pi = partition(arr, low, high);
        
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main() {
    
    void quickSort(int arr[], int low, int high);
    
    int n;
    int s;
    
    cin>>n>>s;
    
    map<int, string>names;
    
    int nums[n];
    
    string temp;
    int tnum;
    for(int i=0;i<n;i++){
        
        cin>>temp>>tnum;
        nums[i]=tnum;
        names[tnum]=temp;
        
    }
    
    quickSort(nums,0, n);
    
    int l=0;
    int h=n-1;
    
    
    while (true){
        

        if (nums[l]+nums[h]<s){
            
            l++;
        }
        else if(nums[l]+nums[h]>s){
            h--;
        }
        else{
            cout<<names[nums[l]]<<" "<<names[nums[h]];
            break;
        }
        
        if(l>=h){
            cout<<"NIE";
            break;
        }
        
        
    }
    
    return 0;
}
