    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) {return 0;}
        vector<int> :: iterator pos;
        int count=0;
        pos = nums.begin();
        for(auto it = (nums.begin()+1); it!=nums.end(); it++) {
            if(*pos == *(it)) {
                nums.erase(it);
                it--;
            } else {
                pos = it;
            }
        }
        return nums.size();
    }