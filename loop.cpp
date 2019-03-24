#include <iostream>
/* 
   As we are using vector so include
   it from the library.
*/
#include <vector>
#include <algorithm>
// Don't have to use std:: before cout and cin.
using namespace std;

int main() 
{
    char selection {};  
    int integer {};
    vector <int> lst {};
    /*
       Using do while because inspite of the condition, 
       the statement gets printed atlease one time.
    */
    do {
        
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display the mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl << endl;
        
        cout << "Enter your choice: ";
        cin >> selection;

        if (selection == 'P' || selection == 'p') {
            if (lst.size() == 0)
                cout << "[] - the list is empty" << endl << endl;
            else {
                cout << "[ " ;
                for (int val:lst)
                    cout << val << " " ;
                cout << "]" << endl << endl;
            }
        }
        
        else if (selection == 'A' || selection == 'a') {
            cout << "Enter an integer to add to the list: " ;
            cin >> integer;
            cout << integer << " added" << endl << endl;
            lst.push_back(integer);
        }

        else if (selection == 'M' || selection == 'm') {
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

        else if (selection == 'S' || selection == 's') {
             if (lst.size() == 0)
                cout << "[] - the list is empty" << endl << endl;

             else {
               auto min_value = *std::min_element(lst.begin(),lst.end());
               cout << "The smallest number is "<< min_value << endl << endl;
             } 
        }

        else if (selection == 'L' || selection == 'l') {
             if (lst.size() == 0)
                cout << "[] - the list is empty" << endl << endl;

             else {
               // Shortcut for finding max value in a vector.
               auto max_value = *std::max_element(lst.begin(),lst.end());
               cout << "The largest number is " << max_value << endl << endl;
             } 
        }

        else {
            cout << "Unknown selection, please try again" << endl << endl;
        }

    } while (selection !='Q' && selection != 'q');

    cout << endl;
    cout << "Goodbye..." << endl << endl;
    return 0;
}
