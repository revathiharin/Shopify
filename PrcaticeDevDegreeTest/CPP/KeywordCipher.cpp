/*https://www.geeksforgeeks.org/keyword-cipher/*/

// CPP program for decoding the string
// which generate using classical cipher
 
#include <bits/stdc++.h>
using namespace std;
 
// Original Set of letters
string plaintext = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 
// Function generates the encoded text
string encoder(string key)
{
    string encoded = "";
    bool arr[26] = { 0 };
 
    // This loop inserts the keyword
    // at the start of the encoded string
    for (int i = 0; i < key.size(); i++) {
        if (key[i] >= 'A' && key[i] <= 'Z') {
            // To check whether the character is inserted
            // earlier in the encoded string or not
            if (arr[key[i] - 65] == 0) {
                encoded += key[i];
                arr[key[i] - 65] = 1;
            }
        }
        else if (key[i] >= 'a' && key[i] <= 'z') {
            if (arr[key[i] - 97] == 0) {
                encoded += key[i] - 32;
                arr[key[i] - 97] = 1;
            }
        }
    }
 
    // This loop inserts the remaining
    // characters in the encoded string.
    for (int i = 0; i < 26; i++) {
        if (arr[i] == 0) {
            arr[i] = 1;
            encoded += char(i + 65);
        }
    }
    return encoded;
}
 
// This function will decode the message
string decipheredIt(string msg, string encoded)
{
    // Hold the position of every character (A-Z)
    // from encoded string
    map<char, int> enc;
    for (int i = 0; i < encoded.size(); i++) {
        enc[encoded[i]] = i;
    }
 
    string decipher = "";
 
    // This loop deciphered the message.
    // Spaces, special characters and numbers remain same.
    for (int i = 0; i < msg.size(); i++) {
        if (msg[i] >= 'a' && msg[i] <= 'z') {
            int pos = enc[msg[i] - 32];
            decipher += plaintext[pos];
        }
        else if (msg[i] >= 'A' && msg[i] <= 'Z') {
            int pos = enc[msg[i]];
            decipher += plaintext[pos];
        }
        else {
            decipher += msg[i];
        }
    }
    return decipher;
}
 
// Driver code
int main()
{
    // Hold the Keyword
    string key;
    key = "TOBI LUTKE"; //Computer
    cout << "Keyword : " << key << endl;
 
    // Function call to generate encoded text
    string encoded = encoder(key);
 
    // Message that need to decode
    string message = "VIAGUIGTLBILOCSDQN"; //EUUDN TIL EUUDN
    cout << "Message before Deciphering : " << message
         << endl;
 
    // Function call to print deciphered text
    cout << "Ciphered Text : "
         << decipheredIt(message, encoded) << endl;
 
    return 0;
}