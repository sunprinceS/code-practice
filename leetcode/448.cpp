public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> check(nums.size(),false);
		vector<int> ret;
		ret.reserve(nums.size());
		for(size_t i=0;i<nums.size();++i){
			check[nums[i]-1] = true;
		}
		for (size_t i=0;i<nums.size();++i){
			if(!check[i]){
			  ret.push_back(i+1);  
			} 
		}
		return ret;
    }
};
