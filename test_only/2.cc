/*

Input
3 2
5 8 5

Output
0 2
2 1
2 3

*/


#include <iostream>
#include <vector>
#include <map>
// #include <unordered_map>
#include <algorithm>

using std::vector;
using std::map;
// using std::unordered_map;
using std::cout;

struct A{
  int id;
  int high;

  A(int i, int j):id(i), high(j){}

  bool operator<(const A& other) const
  {
    if (high == other.high)
      return id < other.id;
    return high < other.high;
  }
};

int main()
{
  int n, k;
  vector<A> v;
  // map<int, int> m;
  // unordered_map<int, int> res;
  vector<A> res;
  v.reserve(n);
  scanf("%d%d", &n, &k);

  for (int i = 0; i < n; ++i){
    int tmp;
    scanf("%d", &tmp);
    v.push_back(A(i, tmp));
  }

  int k_count = 0;
  int _min = 100001;
  for (int i = 0; i < k; ++i){
    sort(v.begin(), v.end()); // need the operator < is const.
    int min = v[0].high;
    int max = v[n - 1].high;
    int to = v[0].id;
    int from = v[n-1].id;
    if ((max - min) == 0 || (max - min) == 1){
      break;
    }
    cout << from+1 << " " << to+1 << std::endl;
    res.push_back(A(from+1, to+1));
    // res.insert(unordered_map<int, int>::value_type(from+1, to+1));
      // cout << "insert fail" << std::endl;
    ++k_count;
    v[0].high++;
    v[n-1].high--;
    _min = v[n-1].high - v[0].high;
    // cout << max << " " << min << std::endl;
    // res.insert(unordered_map<int, int>::value_type(from, to));
  }

  // cout << "size is " << res.size() << std::endl;
  cout << _min << " " << k_count << std::endl;
  vector<A>::iterator it;
  for (it = res.begin(); it != res.end(); ++it){
    cout << it->id << " " << it->high << std::endl;
  }

  return 0;
}