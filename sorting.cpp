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
    std::uniform_int_distribution<> distr(0, 9); // define the range

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
    }
}

int main(){
    decideSize();
    fillArray();
    printArray();
    insertionSort();
    printArray();
    delete[] arrayUsed;
}
