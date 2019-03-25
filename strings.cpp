#include <iostream>
// Include string library to use strings
#include <string>
using namespace std;

int main() 
{
   // Substitution Cipher
   string message {};
   string encrypted_message {};
   string decrypted_message {};
   string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ "};
   string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr "};

   cout << "Enter your secret message: ";
   getline(cin, message);            /* Use getline method to print word after spaces, ex - if message = "hello there"
                                        it will print only hello if the getline method was not used. */
   cout << endl;
   // Encryption starts
   cout << "Encrypting message..." << endl << endl;

   // Deploying logic
   for (int i {0};i < message.length();++i) {
       size_t position = alphabet.find(message[i]);

       if (position != string::npos) {
           message[i] = key[position];
           encrypted_message += message[i];
       } 
       else 
           cout << "Position not found!!" << endl;      
   }
   
   cout << "Encrypted message: " << encrypted_message << endl << endl;

   cout << "Do you want to decrypt this message? ";
   char decision {};
   cin >> decision;
   cout << endl;

   if (decision == 'Y' || decision == 'y') { 
        // Decryption starts
        cout << "Decrypting message..." << endl << endl;

        // Deploying logic
        for (int i {0};i < encrypted_message.length();++i) {
            size_t position = key.find(encrypted_message[i]);

            if (position != string::npos) {
                encrypted_message[i] = alphabet[position];
                decrypted_message += encrypted_message[i];
            } 
            else 
                cout << "Position not found!!" << endl;
            
        }
        cout << "Decrypted message: " << decrypted_message << endl << endl;
   }

   else 
      cout << "Goodluck deciphering it yourself" << endl;

   return 0;
}

   /*
    string part1 {"C++"};
    string part2 {" is good"};
    cout <<  part1 + part2 << endl;
    cout << "C++" +  " is good" << endl;   // Can't use "C++" + " is good as they are as we are
                                           // combining two c-style string, use strcat().
    
    cout << part2 + "good" << endl;         // Works because we part2 is string object and now "good"
                                            // also becomes string object. object + c-style string is allowed.
    */
