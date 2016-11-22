
// The Dole Queue UVa133


#include <stdio.h>
#include <iostream>

using namespace std;

#define maxn 25
int n, k, m, a[maxn];

int go(int p, int d, int t){  //d = 1, counterclockwise, d = -1, clockwise
    while(t--){
        do{
            p = (p+d+n-1) % n + 1;  //用取余处理循环的数组
        }while(a[p] == 0);   //do while: 先执行一次再判断条件
    }
    return p;
}

int main(){
    while(cin >>n && n > 0){
        cin >> k >> m;
        for(int i = 1; i <= n; i++) //initialize array
            a[i] = i;
        
        int left1 = n;  //n people left
        int p1 = n, p2 = 1;
        while(left1){
            p1 = go(p1, 1, k);
            p2 = go(p2, -1, m);
            cout << p1;
            left1--;
            if(p2 != p1){
                cout << ' ' << p2;
                left1--;
            }
            a[p1] = a[p2] = 0;  //选过的人变成0，所以在每次选的时候会跳过等于0的
            if(left1)
                cout << ',';
        }
        cout << '\n';
    }
    return 0;
}
