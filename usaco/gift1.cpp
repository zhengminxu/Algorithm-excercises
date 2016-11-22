/*
 ID: xxzzmm31
 PROG: gift1
 LANG: C++
 */

#include <stdio.h>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

int main(){
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");
    
    int n;
    fin >> n;
    
    map<string,int> gift;
    vector<string> s;
    
    string name;
    for(int i = 0; i < n; i++){
        fin >> name;
        s.push_back(name);
        gift[name] = 0;
    }
    
    while(fin >> name && name != "\n"){
        int money, people;
        fin >> money >> people;
        if(people != 0 && money != 0)
            gift[name] -= (money - money % people);
        string name1;
        for(int i = 0; i < people; i++){
            fin >> name1;
            gift[name1] += (money / people);
        }
    }
    for(int i = 0; i < n; i++){
        name = s[i];
        fout << name << ' ' << gift[name] << endl;
    }
    
    return 0;
    
}
