#include <iostream>

/* 
   As we are using vector so include
   it from the library
*/

#include <vector>

// Don't have to use std:: before cout and cin

using namespace std;

int main() {

    int score {10};

    int *score_ptr {nullptr};

    // Set the pointer score_ptr points to box of score
    // and adress of score is equal to value of score_ptr 
    score_ptr = &score;

    cout << "Value of score is " << score << endl;
    cout << "Value of score is " << *score_ptr << endl;
    cout << "Address of p is " << &score << endl;
    cout << "value of score_ptr is " << score_ptr << endl;        // Address of the variable it is pointing to
    cout << "Address of score_ptr is " << &score_ptr << endl;

}