class Solution {
private:
    bool check(int a[26],int b[26]){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int arr1[26]={0};
        for(int i=0;i<s1.size();i++){
            int index=s1[i]-'a';
            arr1[index]++;
        }
        int arr2[26]={0};
        int window=s1.size();
        int i=0;
        while(i<window && i<s2.size()){
            int index=s2[i]-'a';
            arr2[index]++;
            i++;
        }
        if(check(arr1,arr2)){
            return true;
        }
        while(i<s2.size()){
            int index=s2[i]-'a';
            arr2[index]++;
            
            int index2=s2[i-window]-'a';
            arr2[index2]--;
            if(check(arr1,arr2)){
                return true;
            }
            i++;
        }
        return false;
    }
};