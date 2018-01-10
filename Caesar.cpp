#include "Caesar.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Caesar::Caesar(string _key) {
   key= _key;
     //Write the code
}

string Caesar::get_key() const{
   return key; 
}

string Caesar::encode(string s) const{
   string key = get_key();
   string encrypted = "";
   for (int i = 0; i < s.length(); i++) {
      int key_digit_index = i%key.length();
      char key_digit = key[key_digit_index];
      int bob = s[i] + key_digit - 32;
      char new_char = char(((bob-32)%91) +32);
      encrypted += new_char; 
   }
   return encrypted;
}

string Caesar::decode(string e) const{
   string key = get_key();
   string decrypted = "";
   for (int i = 0; i < e.length(); i++) {
      int key_digit_index = i%key.length();
      int key_digit = key[key_digit_index]; //32
      int current_digit = int(e[i]) - 32;
      int current_key = key_digit - 32;
      int new_char = current_digit - current_key;
      if(new_char < 0){
         new_char += 91;
      }
    char final_val = char(new_char + 32);
      decrypted += final_val;   
   }
   return string(decrypted);
}

