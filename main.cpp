#include <iostream>
#include<string>
#include<string.h>

using namespace std;


// leaving alphabet as a parameter makes it more portable can change
// could make alphabet a global variable

string encryptMessage(const string& message, const int& key, const string& alphabet)
{

    string encrypted;
    string ch;
    string newCh;

    int pos;
    int newPos;


    for (int i=0; i<message.length(); i++) // could use null instead
    {

        ch = message.at(i);
        pos = alphabet.find(ch);

        newPos = pos + key;



        if (newPos > alphabet.size() - 1) // or 51 // for wraparound
        {

            newPos = newPos - alphabet.size(); // or 52 // for wraparound

            // should be alphabet size and alphabet size -1 for universability

        }

        newCh = alphabet.at(newPos);

        encrypted += newCh;




    }


    return encrypted;


}


string decryptMessage(const string& message, const int& key,  const string& alphabet)
{

// could use the property
// Cipher(n) = De-cipher(52-n)
// would save space

    string decrypted;

    string ch;
    string newCh;

    int pos;
    int newPos;


    for (int i=0; i < message.length() ; i++)
    {

        ch = message.at(i);
        pos = alphabet.find(ch);

        newPos = pos - key;


        if (newPos < 0)
        {

            newPos = alphabet.size() + newPos;

            // better to use absolute then subtraction
            // for wraparound

            // should be alphabet size
            // then can do 52 -

        }

        newCh = alphabet.at(newPos);

        decrypted += newCh;




    }




    return decrypted;


}



int findCesarKey(const string& message, const string& hint, const string& alphabet)
{

    string temp;
    int pos;
    int key;

    for(unsigned int i = 1 ; i <= alphabet.size(); ++i)
    {

        temp = decryptMessage(message, i, alphabet);


        pos = temp.find(hint);

        // cout << temp <<endl;

        if (pos != -1 )
        {

            key = i;
            // cout << key <<endl;

            // assumed only 1 correct outcome where we get the hint

            // can probably exit the loop since will probably only find one case

            i = alphabet.size();
            // maybe a way to swap uper and lower case

            // an exit


        }

        // search for hint




        // try all possible combonations
        // look for the hint
        // if the hint is found you have the key



    }

    return key;


}




int main()
{


    const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    const string clue = "Yanks";

    const string code1 = "uIFzBOLTbSFbMTPlOPXObTuIFcSPOYcPNCFST";

    int key;

    key = findCesarKey(code1, clue, alphabet);

    cout << "The shift number is: " << key <<  endl;

    cout << endl;

    // can print the alphabet and the corresponding encrypted alphabet

    string translation1;

    translation1 = decryptMessage(code1, key, alphabet);

    cout << "The encrypted code is " << endl;
    cout << code1<< endl;

    cout << "The decrypted code is " << endl;
    cout << translation1<< endl;

    cout << endl;

    // code1 has yanks
    // this means Yanks is zBOLT
    // this means the number is 27

    // since Y becomes z
    // how to find this out the other way though


    // I need to search the string for the equivalent of Yanks
    // I guess find a section of the code where the difference between the characters is the same as Yanks

    // Y to a is 2
    // a to n is 13
    // n to k is -3

    // k to s is 8

    // for a loop of the string find string[i+1] - string[i] = 2
    // then find


    // go through the whole string
    // once we find it we can compare Y to what we get

    // or maybe brute force

    const string code2 = "dBFTBSdJQIFSfYFSDJTFxJUIdqMVTqMVT";
    string translation2;

    translation2 = decryptMessage(code2, key, alphabet);

    cout << "The encrypted code is " << endl;
    cout << code2<< endl;

    cout << "The decrypted code is " << endl;
    cout << translation2<< endl;





// string translation3;

    //translation3 = encryptMessage(translation1, key, alphabet);

    // cout << "The encrypted code is " << endl;
    //cout << translation1<< endl;

    // cout << "The decrypted code is " << endl;
    // cout << translation3<< endl;













    //string translation3;

    // translation3 = encryptMessage("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", key, alphabet);

    // cout << "The encrypted code is " << endl;
    // cout << code2<< endl;

    // cout << "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" << endl;
    //cout << translation3<< endl;



// what about a cipher that codes upper as lowecase and vice versa
// would require 2 alphabets

// ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
// bcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZa





    cout << endl;


    // try all possible shift?

    // brute force?

    // for i = 1 to 52
    // shift the encrypted by i
    // search for Yanks

    return 0;

}
