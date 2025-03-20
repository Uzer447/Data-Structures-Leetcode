#include <string>
#include <utility>
using namespace std;
class Solution {
public:
    long long myGcd(long long a, long long b) {
        while(b) { long long t = a % b; a = b; b = t; }
        return a;
    }
    pair<long long,long long> parse(const string &s) {
        size_t posDot = s.find('.');
        string intPart, nonRepeat, repeat;
        if(posDot == string::npos) {
            intPart = s;
        } else {
            intPart = s.substr(0, posDot);
            size_t posParen = s.find('(', posDot);
            if(posParen == string::npos) {
                nonRepeat = s.substr(posDot+1);
            } else {
                nonRepeat = s.substr(posDot+1, posParen-posDot-1);
                repeat = s.substr(posParen+1, s.size()-posParen-2);
            }
        }
        long long A = stoll(intPart);
        if(repeat.empty()){
            long long n = nonRepeat.size();
            long long B = nonRepeat.empty() ? 0 : stoll(nonRepeat);
            long long den = 1;
            for(int i=0;i<n;i++) den *= 10;
            long long num = A * den + B;
            long long g = myGcd(num, den);
            return {num/g, den/g};
        } else {
            long long n = nonRepeat.size();
            long long m = repeat.size();
            long long B = nonRepeat.empty() ? 0 : stoll(nonRepeat);
            long long R = stoll(repeat);
            long long base = 1;
            for(int i=0;i<n;i++) base *= 10;
            long long repBase = 1;
            for(int i=0;i<m;i++) repBase *= 10;
            long long den = base * (repBase - 1);
            long long num = A * den + B * (repBase - 1) + R;
            long long g = myGcd(num, den);
            return {num/g, den/g};
        }
    }
    bool isRationalEqual(string s, string t) {
        return parse(s) == parse(t);
    }
};