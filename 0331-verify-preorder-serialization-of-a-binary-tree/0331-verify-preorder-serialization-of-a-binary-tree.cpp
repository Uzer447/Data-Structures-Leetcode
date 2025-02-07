class Solution {
public:
    int getNextTreeIndx(string& preorder, int start){
        if (start >= size(preorder) || start < 0) return -1;

        if (preorder[start] == '#') return start+2; 
        int num = 0;
        while(isdigit(preorder[start])){
            start++;
            if (start == size(preorder)) 
                return -1;
        }
        int right_indx = getNextTreeIndx(preorder, start+1);
        int next_tree_indx = getNextTreeIndx(preorder,right_indx);
        return next_tree_indx;

    }
    bool isValidSerialization(string preorder) {
        return getNextTreeIndx(preorder, 0) == size(preorder)+1;

    }
};