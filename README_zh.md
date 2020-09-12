[中文](README_zh.md)  [英文](README.md)

一个简单的C++程序，一个小型的课堂实验，实现简单的数据加密交换。

加密规律如下：（括号中是一个“原文 -> 密文”的例子） 

1.原文中所有的字符都在字母表中被循环左移了三个位置（dec -> abz） 

2.逆序存储（abcd -> dcba ） 

3.大小写反转（abXY -> ABxy）

**输入**：

一个加密的字符串。（长度小于50且只包含大小写字母）

**输出**：

输出解密后的字符串。

 **样例输入**：

GSOOWFASOq

**样例输出**:

Trvdizrrvj

这个小实验是**解密**算法，我实现的正向的**加密**算法如下，代码比较简单，仅作记录而已。

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
        pp[i] = p[len-i-1];
    }
    pp[len] = '\0';

    //cout<<pp<<endl;
    ptr = pp;

    while(*ptr!='\0'){
        /* 大小写转换 */
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
    char p[50];  // 明文
    char p2[50];  // 明文的副本
    cout<<"请输入明文："<<endl;
    cin>>p;
    int i;
    for(i=0; i<50; i++){
        p2[i] = p[i];
    }
    Cryption cryp;  // 加密类的一个对象cryp
    cryp.getCryption(p2);
    //cout<<'A'-'a'<<endl;  // 'a'-'A'=32
    return 0;
}
```

开发环境是CodeBlocks 20.03.