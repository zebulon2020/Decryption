[Chinese(中文)](README_zh.md)  [English](README.md)

A simple C++ program, a small classroom experiment, to implement a simple data encryption exchange.

The encryption rules are as follows: (an example of "sic -> ciphertext" is in parentheses) 

1.All the characters in the original text have been cyclically shifted left three places in the alphabet (dec -> abz) 

2.reverse-order storage (abcd -> dcba ) 

3.case reversal (abXY -> ABxy)

**Enter**:

An encrypted string. (less than 50 in length and contains only upper and lower case letters)

**Output**:

Output the decrypted string.

 **Sample input**:

GSOOWFASOq

**Sample output**:

Trvdizrrvj

This little experiment is a **decryption** algorithm, I implemented the following positive **encryption** algorithm, the code is relatively simple, just for the record.

```c++
#include <iostream>

using namespace std;

class Cryption{
public:
    void getCryption(char* p);
};

void Cryption::getCryption(char* p){
    int len=0;
    char *ptr = p;
    while(*ptr != '\0'){
        /* 移位操作，根据ASCII码。注意abc(ABC)左移三位要对应xyz(XYZ)，所以要分两种情况*/
        /*The shift operation, according to ASCII code. Note that abc(ABC) is shifted three places to the left to correspond to xyz(XYZ), so there are two cases.*/
        if(*ptr=='a'|| *ptr=='b'||*ptr=='c'||*ptr=='A'||*ptr=='B'||*ptr=='C'){
            *ptr = char(*ptr + 23);
            len++;
        }
        else{
            *ptr = char(*ptr - 3);
            len++;
        }

        ptr++;
    }
    //cout<<p<<endl;

    int i;
    char pp[len+1];

    for(i=0; i<len; i++){
        /*逆序存储到ss这个字符数组中*/
        /*Stored in reverse order in an array of characters called ss.*/
        pp[i] = p[len-i-1];
    }
    pp[len] = '\0';

    //cout<<pp<<endl;
    ptr = pp;

    while(*ptr!='\0'){
        /* 大小写转换 */
        /* case sensitive conversion */
        if(*ptr>='a' && *ptr<='z'){
            *ptr = char(*ptr + 'A' - 'a');
        }
        else{
            *ptr = char(*ptr + 'a' - 'A');
        }

        ptr++;
    }
    cout<<pp<<endl;
}

int main()
{
    char p[50];  // 明文 Plaintext
    char p2[50];  // 明文的副本 A copy of Plaintext
    cout<<"Please enter the plaintext："<<endl;
    cin>>p;
    int i;
    for(i=0; i<50; i++){
        p2[i] = p[i];
    }
    Cryption cryp;  // 加密类的一个对象cryp  //An object of the encryption class cryp
    cryp.getCryption(p2);
    //cout<<'A'-'a'<<endl;  // 'a'-'A'=32
    return 0;
}
```

The development environment is CodeBlocks 20.03.