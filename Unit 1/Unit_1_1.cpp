/*
Implement basic string operations such as length calculation, copy, reverse, and 
concatenation using character single dimensional arrays without using built-in 
string library functions. 
*/

#include<iostream>
using namespace std;

int stringLength(char str[]){
    int length = 0;

    while(str[length]!='\0'){
        length++;
    }
    return length;
}

void strCopy(char dest[],char src[]){
    int i=0;

    while(src[i]!='\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] ='\0';

}

void concatinate(char str1[] , char str2[]){
    int len1 = stringLength(str1);
    int i=0;
    while(str2[i]!='\0'){
        str1[len1+i] = str2[i];
        i++;
    }
    str1[len1+i]='\0';
}

void reverseString(char str[]){
    int start = 0;
    int end = stringLength(str) - 1;
    char temp;
    while(start<end){
        temp = str[start];
        str[start] = str[end];
        str[end]= temp;
        start++;
        end--;
    }
} 

int main(){
    char str1[100], str2[100], copyStr[100];

    cout << "Enter first string: ";
    cin.getline(str1, 100);

    cout << "Enter second string: ";
    cin.getline(str2, 100);

    // Length
    cout << "\nLength of first string: " << stringLength(str1);

    // Copy
    strCopy(copyStr, str1);
    cout << "\nCopied string: " << copyStr;

    // Reverse
    reverseString(str1);
    cout << "\nReversed first string: " << str1;

    // Concatenate
    concatinate(str1, str2);
    cout << "\nConcatenation result: " << str1;

    return 0;
}