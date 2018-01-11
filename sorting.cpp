#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>

using namespace std;

//global variables
int arraySize;
int *arrayUsed;

static void decideSize(){
    cout<<"Hey! pick the amount of elements to sort. \n";
    cin >> arraySize;
}

static int pickRandom(){
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(-1000, 1000); // define the range

    return distr(eng); // generate numbers
}

void fillArray(){ 
    arrayUsed = new int[arraySize];
    for(int i = 0; i <= arraySize; i++){
        *(arrayUsed + i) = pickRandom();
    }
}

static void printArray(){
    cout << "[ ";
    for(int i = 0; i < arraySize - 1; i++){
        cout << " " << *(arrayUsed + i) << " ,";
    }
    cout<< " " << *(arrayUsed + arraySize) << " ]\n";
}

static void insertionSort(){
    for(int i = 1; i <= arraySize; i++){
    int x = *(arrayUsed + i);
    int j = i - 1;
    while(j >= 0 && *(arrayUsed + j) > x){
        *(arrayUsed + (j+1)) = *(arrayUsed + j);
        j = j -1;
    }
    *(arrayUsed + (j+1)) = x;
    printArray();
    }
}

static void bubbleSort(){
    for(int i = arraySize; i >= 1; i--){
        for(int j = 0; j <= i; j++){
            if( *(arrayUsed + j) > *(arrayUsed + (j+1))){
                int k = *(arrayUsed + j);
                int l = *(arrayUsed + (j+1));
                *(arrayUsed + j) = l;
                *(arrayUsed + (j+1)) = k;
            }
            printArray();
        }
    }
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && *(arrayUsed + l) > *(arrayUsed + largest))
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && *(arrayUsed + r) > *(arrayUsed + largest))
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        int k = *(arrayUsed + i);
        int l = *(arrayUsed + largest);
        *(arrayUsed + i) = l;
        *(arrayUsed + largest) = k;

 
        // Recursively heapify the affected sub-tree
        heapify(n, largest);
    }
}
 
// main function to do heap sort
static void heapSort(int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 -1; i >= 0; i--)
        heapify(n, i);
 
    // One by one extract an element from heap
    for (int i=n; i>=0; i--)
    {
        // Move current root to end
        int k = *(arrayUsed);
        int l = *(arrayUsed + i);
        *(arrayUsed) = l;
        *(arrayUsed + i) = k;

 
        // call max heapify on the reduced heap
        heapify( i, 0);
        printArray();
    }
}

int main(){
    decideSize();

    
    cout << "cool, now pick a sorting algorithm \n";
    
    int input;
    
    cout<<" 1. insertion sort\n";
    cout<<" 2. bubble sort\n ";
    cout<<"3. heap sort\n ";
    cout<<"Selection: ";
   
    cin>> input;
    fillArray();
    printArray();

    switch ( input ) {
case 1:            // Note the colon, not a semicolon
    insertionSort();
    break;
case 2:
    bubbleSort();
    break;
case 3: 
    heapSort(arraySize);
    break;
default:            // Note the colon, not a semicolon
    cout<<"Error, bad input, quitting\n";
    break;
  }
    printArray();

    delete[] arrayUsed;
}
