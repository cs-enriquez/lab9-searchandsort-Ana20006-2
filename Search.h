#include <iostream>
#include <string>

using namespace std;
// write a function to print the contents of your array
//   bonus! try to implement your function so that it can accept
//     many types of data (int, char, string, etc.)
template <typename T> // ???
void printArray(T *arr, int length) {
    for(int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
}

// Implement a sequential search algorithm
// your function should search for a target value (target)
//    within the indices of "start" to "end"
// return true if target exists in the array within this range,
//    return false otherwise
bool seqSearch(string target, string arr[], int start, int end) {
    for(int i = start; i <= end; i++){
        if(arr[i] == target){
            return true;
        }
    }
    return false;
}

// Implement an iterative binary search 
// Return true if target exists in the array with size n,
//    return false otherwise 
bool binSearch(float target, float arr[], int n) {
    int center = n/2;
    float mid = arr[center];
  
  while(n > 0){
    if(mid == target){
      return true;
    } 
    else if (mid > target){
      n /= 2;
      center = n/2;
      mid = arr[center];
    }
    else{
      arr += (center+1);
      n = n - (center+1);
      center = n/2;
      mid = arr[center];
    }
  } 
    return false;
}


// Implement a recursive binary search 
// Return true if target exists in the array with size n
//   return false otherwise
bool binSearchR(char target, char charray[], int n) {
    int center = n/2;
    int mid = charray[center];
    // base case
    if(n == 0){
        return false;
    }
    //general case
    else if(mid == target){
        return mid;
    }
    else if(mid > target){
        return binSearchR(target, charray, n/2);
    } else {
        return binSearchR(target, charray+n/2, n/2);
    }
    return false;
}

// Implement a brand new sorting algorithm
//    Don't use a reference for this!
//    Be sure to do your best to implement the algorithm's logical steps
// Step 1: implement a function swap() that will swap any two elements in an array,
//          given their indices
// Step 2: implement a function minFind() that will find and return 
//          the *index* of the smallest element in an array
/*
Step 3: Finally, use your two functions above to complete the following in newSort():
        1 - search through the array to find the location of the smallest value
        2 - swap this value with the value at the start of the array
        3 - the first element is now sorted! 
            Redo your sort on the remaining elements (from index 1 to end)
            On the next iteration, you should be swapping the smallest remaining value 
                with the second index value in the array
            ...then swapping the smallest remaining value with the third indexed value... etc.
            
        4 - continue iterating until you reach the end of the list
        * You can make this recursive, if you wish!
*/

void swap(double darray[], int a, int b) {
    double x = darray[a];
    darray[a] = darray[b];
    darray[b] = x;
}

int minFind(double darray[], int n) {
    double min = darray[0];
    int minIndex = 0;
    for(int i = 1; i < n; i++){
        if(darray[i] < min){
            min = darray[i];
            minIndex = i;
        }
} return minIndex;
}

void newSort(double darray[], int n) {
    for(int i = 0; i < n - 1; i++){
        int minIndex = minFind(darray + i, n - i) + i;
        swap(darray, i, minIndex);
    }

}