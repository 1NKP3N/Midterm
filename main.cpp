/*
 Midterm CS 162 Spring 2017
 Name: Johnny Phelan
 Compiler:
 */

#include <iostream>
#include "polynomial.h"

using namespace std;

// Create Fibonacci List
// Pass in n representing nth fib number
// Return pointer to allocated array of int
//    containing n fibonacci numbers.
// Use 0, 1 as the first two numbers
// Return 'nullptr' if n < 1.
int* getFibs(int n) {

    int* arr = new int[n];
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i < n; i++){
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr;
}

// Print Array of int
// Pass in the array and the size
// Print the elements on one line with spaces between
void printList(int arr[], int size) {
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

// Test fib code
// Prompt user for n
// Create fib list
// Print fib list
void fibTester(int n) {

    getFibs(n);
    printList(getFibs(n), n);

    cout << endl;
}


// Create class objects

// Test the class methods

void classTester() {

    vector<int> coefs{1,6,3};       // 1x^2 + 6x^1 + 3
    Polynomial poly{coefs};
    poly.print();

    vector<int> coefs2{5,-1};       // 5x^1 + -1
    Polynomial poly2{coefs2};
    poly2.print();

    vector<int> coefs3{-2,0,5};    // -2x^2 + 0x^1 + 5
    Polynomial poly3{coefs3};
    poly3.print();

    //vector<int> coefs{1,6,3};     // 1x^2 + 6x^1 + 3
    Polynomial poly4{coefs};
    poly4.print();

    cout << poly << endl;
    cout << poly2 << endl;

    cout << boolalpha << (poly == poly2) << endl;
    cout << boolalpha << (poly != poly4) << endl;

}


int main() {

    cout << "Name: Johnny Phelan" << endl;
    fibTester(15);
    classTester();

    return 0;
}
