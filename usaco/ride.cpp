/*
 ID: xxzzmm31
 PROG: ride
 LANG: C++
 */

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int ride(){
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    
    string a,b;
    fin >> a >> b;
    int p1 = 1,p2 = 1;
    for(int i = 0; i < a.size(); i++){
        p1 *= (a[i] - 'A' + 1);
    }
    for(int j = 0; j < b.size(); j++){
        p2 *= (b[j] - 'A' + 1);
    }
    if(p1%47 == p2%47)
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;
    return 0;
}
