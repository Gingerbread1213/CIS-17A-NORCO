#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;
int linearSearch(int arr[],int size,int target);
int binarySearch(int arr[], int size, int target);
void bubbleSort(int arr[], int size);
void read(int arr[], int size);
void bubbleSortOptimal(int arr[], int size);
void selectionSort(int arr[], int size);
void dualSort(vector<double> &x, vector<double> &y);

int main(){
    
    
    
    vector<double> arrx;
    
    vector<double> arry;
    
    arrx.push_back(12);
    arrx.push_back(11);
    arrx.push_back(131);
    arrx.push_back(124);
    arrx.push_back(19);
    
    arry.push_back(121);
    arry.push_back(123);
    arry.push_back(1312);
    arry.push_back(194);
    arry.push_back(191);
    
    
    dualSort(arrx, arry);
    
    
    
    
    
    return 100;
    
}


// Search through every element
int linearSearch(int arr[],int size,int target){
    
    int position = -1;
    
    for (int i=0; i<size; i++){
    
        if(target == arr[i]){
            position=i;
            return position+1;
        }
        
    }
    
    return position;
}

// divides the array into three sections:
    // middle element
    // elements on one side of the middle element
    // elements on the other side of the middle element
// If the middle element is the correct value, done. Otherwise, go to step 1. using only the half of the array that may contain the correct value
// Continue step 1, and 2. Until either the value is found or there are no more elements to examine
int binarySearch(int arr[], int size, int target){
    
    int first = 0;
    int last = size - 1;
    int middle;
    bool state = true;
    
    
    while (state == true && last >= first) {
        
        middle = (last + first)/2;
        if(arr[middle]==target){
            return middle+1;
        }else if(arr[middle]>target){
            last = middle-1;
        }else{
            first = middle+1;
        }
    }
    
    return 0;
}


// Compare 1st two elements
    // if out of order, exchange them to put in order
// move down one element, compare 2nd and 3rd elements, exchange if necessary. continue until end of array
// Pass through array again, exchanging as necessary
// Repeat until pass made with no exchanges
void bubbleSort(int arr[], int size){
    
    bool x=true;
    int i=0;
    int j=1;
    int save;
    
    while (x) {
        if(arr[i]>arr[j]){
            save = arr[i];
            arr[i] = arr[j];
            arr[j] = save;
            i = 0;
            j = 1;
        }else if(arr[i]<arr[j] && j<size){
            i++;
            j++;
        }else {
            for(int k=0; k<size; k++){
                cout << arr[k] << " ";
            }
            return;
        }
    }
    
    return;
}

void bubbleSortOptimal(int arr[], int size){
    
    bool x = true;
    int position = 0;
    
    while (x) {
        x = false;
        for (int i =0; i<size-1; i++){
            if (arr[i]>arr[i+1]){
                position = arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=position;
                x = true;
            }
        }
    }
    read(arr, size);
    return;
}

// regard this as a functional design.
void read(int arr[], int size){
    
    for (int i=0; i<size; i++){
        
        cout << arr[i] <<" ";
        
    }
    return;
}



// Locate smallest element in array. Exchange it with element in position 0
// Locate next smallest element in array. Exchange it with element in position 1.
// continue until all elements are arranged in order
void selectionSort(int arr[], int size){
    
    int sort[size];
    int max = *max_element(arr , arr + size);
    for (int i=0; i<size ; i++){
        sort[i] = *min_element(arr , arr + size);
        arr[linearSearch(arr, size, *min_element(arr , arr + size))-1] = max+1;
        read(arr, size);
        cout << endl;
    }
    read(sort, size);
    return;
}


// sort two array base on a single array
void dualSort(vector<double> &x, vector<double> &y){
    int rank, size;
    size = x.size();
    int order[size];
    for (int i = 0; i<size ;i++){
        rank = 0;
        for (int j = 0; j<size; j++){
            if(y[i]>y[j]){
                rank = rank+1;
            }
        }
        order[i] = rank;
    }
    for (int i =0; i<size; i++){
        cout << x[order[i]] << "    " ;
        cout << y[order[i]] << endl ;
    }
    return;
}

