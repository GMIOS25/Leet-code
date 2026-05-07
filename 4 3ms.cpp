class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size()+nums2.size();
        int t= 0;
        int i = 0,j = 0;
        int previous = 0;
        int ans = 0;
        while(t!=size/2+1){
            previous = ans;
            if(i==nums1.size()){ans = nums2[j];t++;j++;continue;}
            if(j == nums2.size()){ans = nums1[i];t++;i++;continue;}
            if(nums1[i]<nums2[j]) {ans = nums1[i];i++;}
            else {ans = nums2[j]; j++;}
            t++;
        }  
        cout<<previous<<ans;
        return size%2==0? (previous+ans)/2.0:ans; 
    }
};