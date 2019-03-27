#include <iostream>
/* 
   As we are using vector so include
   it from the library.
*/
#include <vector>
#include <algorithm>

// Don't have to use std:: before cout and cin.
using namespace std;

vector <int> lst {};    // Used in many places so variable declared globally.

void print_list(char selection);    // Prototype
void add_integer();                 // Prototype
void mean();                        // Prototype         
void smallest_number();             // Prototype
void largest_number();              // Prototype       

int main() 
{
    
    
    /*
       Using do while because inspite of the condition, 
       the statement gets printed atlease one time.
    */
    do {
        display_menu();
        char selection = get_selection();
       
        if (selection == 'P' || selection == 'p') 
            // Calling function
            print_list(selection);     // Don't use char selection. 
                   
        else if (selection == 'A' || selection == 'a')
            // Calling function
            add_integer();
           
        else if (selection == 'M' || selection == 'm')
            // Calling function
            mean();
         
        else if (selection == 'S' || selection == 's')
            // Calling function
            smallest_number();
        
        else if (selection == 'L' || selection == 'l')
            // Calling function
            largest_number();

        else if (selection == 'Q' || selection == 'q')
            cout << "" << endl;
    
        else {
            cout << "Unknown selection, please try again" << endl << endl;
        }

    } while (selection != 'Q' && selection != 'q');

    
    cout << "Goodbye..." << endl << endl;
    return 0;
}

void display_menu() {
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display the mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl << endl;
    cout << "Enter your choice: ";
}

char get_selection() {
    char selection {};
    cin >> selection;
    return selection;
}

void print_list(char selection) {
    if (lst.size() == 0)
        cout << "[] - the list is empty" << endl << endl;
    else {
            cout << "[ " ;
        for (int val:lst)
                cout << val << " " ;
        cout << "]" << endl << endl;
   }
}

void add_integer() {
    int integer {};
    cout << "Enter an integer to add to the list: " ;
    cin >> integer;
    cout << integer << " added" << endl << endl;
    lst.push_back(integer);
}


void mean() {
    if (lst.size() == 0)
        cout << "[] - the list is empty" << endl << endl;
    else {
        /*
            Don't use double sum, mean {}, sum wil
            get garbage value.
        */
        double sum {}, mean {};
        for (auto val:lst){
            sum += val;
        }
        mean = sum/lst.size();
        cout << "list size is " << lst.size() << endl;
        cout << "mean is " << mean << endl << endl;
    } 
}  

void smallest_number() {
    if (lst.size() == 0)
    cout << "[] - the list is empty" << endl << endl;

    else {

    auto min_value = *std::min_element(lst.begin(),lst.end());
    cout << "The smallest number is "<< min_value << endl << endl;

   } 
}

void largest_number() {
    if (lst.size() == 0)
    cout << "[] - the list is empty" << endl << endl;

    else {
    
    // Shortcut for finding max value in a vector.
    auto max_value = *std::max_element(lst.begin(),lst.end());
    cout << "The largest number is " << max_value << endl << endl;

   } 
}
