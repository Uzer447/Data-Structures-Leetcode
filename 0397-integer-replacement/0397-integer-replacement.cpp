class Solution {
public:
    int f(int n){
      if(n<=0) return 0;
      if(n==1) return 0;
     int r=1e8,fa=1e8,y=1e8,p=1e8;
      if(n%2==0) 
       r=1+f(n/2);
      else
      {
         fa=1+f(n-1);
         y=1+f(n+1);
         p=min(fa,y);
      } 
      return min(r,p);
    }
    int integerReplacement(int n) {
        if(n==1) return 0;
        if(n==INT_MAX) return 32;
        return f(n);
    }
};