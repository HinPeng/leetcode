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