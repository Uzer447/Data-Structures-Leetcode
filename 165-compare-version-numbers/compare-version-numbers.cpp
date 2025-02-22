class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n=version1.size();
        int m=version2.size();
        vector<int> ver1;
        vector<int> ver2;
        string temp="";
        for(int i=0;i<n;i++)
        {
            if(version1[i]!='.')
            {
                temp=temp+version1[i];
            }
            else
            {
                ver1.push_back(stoi(temp));
                temp="";
            }
        }
        ver1.push_back(stoi(temp));
        temp="";
        for(int i=0;i<m;i++)
        {
            if(version2[i]!='.')
            {
                temp=temp+version2[i];
            }
            else
            {
                ver2.push_back(stoi(temp));
                temp="";
            }
        }
        ver2.push_back(stoi(temp));
        while(ver1.size()<ver2.size())
        {
            ver1.push_back(0);
        }
        while(ver2.size()<ver1.size())
        {
            ver2.push_back(0);
        }
        for(int i=0;i<ver1.size();i++)
        {
            if(ver1[i]>ver2[i])
            return 1;
            if(ver1[i]<ver2[i])
            return -1;
        }
        return 0;
    }
};