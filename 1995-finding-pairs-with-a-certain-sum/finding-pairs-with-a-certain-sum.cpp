class FindSumPairs {
    vector<int> a,b;
    unordered_map<long long,int> freq;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2){
        a=nums1;
        b=nums2;
        for(int v:b) freq[v]++;
    }
    
    void add(int index, int val){
        int old=b[index];
        if(--freq[old]==0) freq.erase(old);
        int nw=old+val;
        b[index]=nw;
        freq[nw]++;
    }
    
    int count(int tot){
        long long ans=0;
        for(int x:a){
            auto it=freq.find(tot-x);
            if(it!=freq.end()) ans+=it->second;
        }
        return (int)ans;
    }
};