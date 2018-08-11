#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int main()
{
  int i;
  vector<int> v;

  cin >> i;
  v.push_back(i);
  while(cin.get() != '\n'){
    cin >> i;
    v.push_back(i);
  }

  // test rightness
  for (auto i : v)
    cout << i << std::endl;

  return 0;
}