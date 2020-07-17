/*
Top K Frequent Elements

Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]

Note:

    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
    It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
    You can return the answer in any order.
*/
//Solution 1 : time : O ( n log n) : space : O ( n) 
/* store the pair of element and its frequency
sort the vector on frequency
return the last 'K' elements;
*/

//Solution 2 : time : O ( n ) : space : O ( n^2 )
/*
make a freq map,
make a 2 d buckets : index stores the numbers whose frequency equal to index
finally return K elements starting from the biggest index of buckets 2 d vector;
*/

// Solution 3 : time : 0 ( n ), O( n^2 ) ( but worst case probability is negligible ) : space : O ( n ) :
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==k) return nums;
        unordered_map<int,int> m; // freq map
        for(auto p: nums){
            m[p]++;
        }
        vector<int> ans; // unique elements array
        for(auto p:m ){
            ans.push_back(p.first);
        }
        if(ans.size() == k) return ans;
        int l=0,h=ans.size()-1;
        int nans = ans.size();
        int piv = rand()%nans; // Pick Pivot
        int j = -1;
        while(j!= nans-k){
            swap(ans[piv],ans[nans-1]);
            j=l;
            int i=l;
            while(i<nans){
                if(m[ans[i]]<m[ans[nans-1]]){
                    swap(ans[j],ans[i]);
                    j++;
                }
                i++;
            }
            swap(ans[nans-1],ans[j]); // Pivot element now in its correct position
            if(j < nans-k){
                l=j; // the required piv ( i.e, n-k ) is between l and h (inclusive) , and l is to be updated
            }
            else{
                h=j; // the required piv ( i.e, n-k ) is between l and h (inclusive) , and h is to be updated
            }
            piv = l + rand()%(h-l+1); // new pivot in [ l, h ]
        }
        
        return vector<int> (ans.begin()+j, ans.end());
    }
};
