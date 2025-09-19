#include <bits/stdc++.h>
using namespace std;
class Spreadsheet {
    int r;
    unordered_map<string, int> mp;
    bool isNum(const string &s){return isdigit(s[0]);}
public:
    Spreadsheet(int rows) : r(rows) {}
    void setCell(string cell, int value) { mp[cell] = value; }
    void resetCell(string cell) { mp[cell] = 0; }
    int getValue(string formula) {
        string expr = formula.substr(1);
        int pos = expr.find('+');
        string a = expr.substr(0, pos), b = expr.substr(pos+1);
        int val1 = isNum(a) ? stoi(a) : (mp.count(a)?mp[a]:0);
        int val2 = isNum(b) ? stoi(b) : (mp.count(b)?mp[b]:0);
        return val1+val2;
    }
};