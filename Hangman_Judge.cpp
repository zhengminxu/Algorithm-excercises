/*
UVa 489 刽子手游戏

刽子手游戏是一款猜单词游戏，游戏规则：计算机想一个单词让你猜，你每次可以猜一个单词。如果单词里有那个字母，所有该字母都会显示出来，如果没有那个字母，则错误次数加1，错7次意味着失败了。
*/

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string s, s2;  //使用全局变量来减少在调用函数时需要传的参数
int win, lose;  //用flag来减少状态的判断
int left1, chance;  //用left会导致ambiguous variable，可能是因为已经有定义为left的变量


void guess(char ch){
    int bad = 1;
    for(int i = 0; i < s.size(); i++)
        if(s[i] == ch){
            left1--;
            s[i] = ' ';  //标记字母已经猜过
            bad = 0;
        }
    if(bad)
        --chance;
    if(!chance)
        lose = 1;
    if(!left1)
        win = 1;
}

int main(){
    int rnd;
    while(cin >> rnd && rnd != -1){  //每次读取一组输入就计算输出，不用等到所有输入都读取完再一起计算
        cin >> s >> s2;
        cout << "Round " << rnd << endl;
        win = lose = 0;
        left1 = s.size();
        chance = 7;
        for(int i = 0; i < s2.size(); i++){
            guess(s2[i]);  //T(n) = mn, m = s.size(), n = s2.size()
            if(win || lose)
                break;
        }
        if(win)
            cout << "You win.\n";
        else if (lose)
            cout << "You lose.\n";
        else
            cout << "You chickened out.\n";
    }
    return 0;
    
}
