//Message Decoding UVa 213

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int code[8][1<<8];

int readchar(){
    for(;;){  //while(1)
        int ch = getchar();
        if(ch != '\n' && ch != '\r') //'\r'是回车，回到当前行的行首。如果碰到换行符就读下一行的字符
            return ch;
    }
}

int readint(int c){
    int v = 0;
    while(c--)
        v = v*2 + readchar() - '0'; //每获取一位新的数字就把前面几位左移1位
    return v;
}


int readcodes(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < (1<<8); j++){
            code[i][j] = 0;
        }
    }
    code[1][0] = getchar();
    for(int len = 2; len <= 7; len++){
        for(int i = 0; i < (1<<len)-1; i++){
            int ch = getchar();
            if(ch == EOF) //end of file
                return 0;
            if(ch == '\n' || ch == '\r')
                return 1;
            code[len][i] = ch;
        }
    }
    return 1;
}

int main(){
    while(readcodes()){
        //printcodes();
        for(;;){
            int len = readint(3); //获取编码长度
            if(len == 0)
                break;
            //cout << len << endl;
            for(;;){
                int v = readint(len); //读下一个len位编码的字符
                //cout << v << endl;
                if(v == (1 << len) - 1)
                    break; //如果全1，break
                putchar(code[len][v]); //输出字符
            }
        }
        cout << endl;
    }
    return 0;
}
