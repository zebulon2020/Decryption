#include <iostream>

using namespace std;

class Decryption{
public:
    void getDecryption(char* s);
};

void Decryption::getDecryption(char* s){
    char *ptr = s;
    int len = 0;  // 字符串的长度
    while(*ptr!='\0'){
        /* 大小写转换 */
        if(*ptr>='a' && *ptr<='z'){
            *ptr = char(*ptr + 'A' - 'a');
            len++;
        }
        else{
            *ptr = char(*ptr + 'a' - 'A');
            len++;
        }

        ptr++;
    }
    //cout<<s<<endl;
    //cout<<len<<endl;
    int i;
    char ss[len+1];
    for(i=0; i<len; i++){
        /*逆序存储到ss这个字符数组中*/
        ss[i] = s[len-i-1];
    }
    ss[len] = '\0';
    //cout<<ss<<endl;

    ptr = ss;
    while(*ptr != '\0'){
        /* 移位操作，根据ASCII码。注意xyz(XYZ)右移三位要对应abc(ABC)，所以要分两种情况 */
        if(*ptr=='x'|| *ptr=='y'||*ptr=='z'||*ptr=='X'||*ptr=='Y'||*ptr=='Z'){
            *ptr = char(*ptr - 23);
        }
        else{
            *ptr = char(*ptr + 3);
        }

        ptr++;
    }
    cout<<ss<<endl;
}

int main()
{
    char s[50];  // 密文
    char s2[50];  // 密文的副本
    cout<<"请输入密文："<<endl;
    cin>>s;
    int i;
    for(i=0; i<50; i++){
        s2[i] = s[i];
    }
    Decryption dec;  // 解密类的一个对象dec
    dec.getDecryption(s2);
    //cout<<'A'-'a'<<endl;  // 'a'-'A'=32
    return 0;
}
