#include <iostream>
#include <vector>

using namespace std;


int add(int *a); // Declare a pass by reference function

// Define a pass by reference function
int add(int *a){

    int b = *a + 1; // Dereference the pointer and increment the value by 1

    *a = 5; // Modify the value of the variable

    return b; // Return the value of b
}

// Main function
int main() {

    int myVariable = 2; // Define a variable

    int myAnswer = add(&myVariable); // Pass the variable by reference

    cout << myAnswer<<std::endl; // Print the value of myAnswer

    cout << myVariable << endl; // Print the value of myVariable

    return 0;
}