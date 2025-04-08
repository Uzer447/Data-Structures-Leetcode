class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int maxprofit=0;
        int cyclecnt=0;
        int ans=-1;
        int remcust=0;
        int processed=0;
        for(auto it:customers)
        {
            remcust+=it;
            processed+=min(4,remcust);
            remcust-=min(4,remcust);
            cyclecnt++;
            int profit=boardingCost*processed-cyclecnt*runningCost;
            if(profit>maxprofit)
            {
                maxprofit=profit;
                ans=cyclecnt;
            }
        }
        while(remcust>0)
        {
            processed+=min(4,remcust);
            remcust-=min(4,remcust);
            cyclecnt++;
            int profit=boardingCost*processed-cyclecnt*runningCost;
            if(profit>maxprofit)
            {
                maxprofit=profit;
                ans=cyclecnt;
            }
        }
        if(maxprofit==0)
        return -1;
        return ans;
    }
};