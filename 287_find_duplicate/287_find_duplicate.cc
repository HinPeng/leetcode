/* Problem description

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. 
Assume that there is only one duplicate number, find the duplicate one.

Input: [1,3,4,2,2]
Output: 2

Note:
  * You must not modify the array (assume the array is read only).
  * You must use only constant, O(1) extra space.
  * Your runtime complexity should be less than O(n2).
  * There is only one duplicate number in the array, but it could be repeated more than once.

*/


#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

int findDuplicate(vector<int>& nums);

int main()
{
  vector<int> v1{1,3,2,4,2};
  vector<int> v2{3,1,3,4,2};

  printf("%d\n", findDuplicate(v1));
  printf("%d\n", findDuplicate(v2));

  return 0;
}

int findDuplicate(vector<int>& nums)
{
  assert(nums.size() > 0);

  int slow = 0, fast = 0;
  while (true){
    slow = nums[slow];
    fast = nums[nums[fast]];

    if (slow == fast)
      break;
  }

  int finder = 0;
  while (true){
    slow = nums[slow];
    finder = nums[finder];

    if (slow == finder)
      return slow;
  }
}