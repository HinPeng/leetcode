/* 

Input
5 0
1 2 3
0 4
0 4
0 4
1 2 3

Output
4

*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;


int solve(vector<vector<int> >& v, int id)
{
  vector<int> t;

  const vector<int>& v_id = v.at(id);
  for (auto i : v_id)
    t.push_back(i);

  t.push_back(id);

  int res = -1;
  int same_num = 0;
  for (int i = 0; i < v.size(); ++i){
    if (find(t.begin(),t.end(),i)!=t.end())
      continue;

    int same_num_tmp = 0;
    for (auto ii : v.at(i)){
      if (find(v_id.begin(),v_id.end(),ii)!=v_id.end())
        ++same_num_tmp;
    }

    if (same_num_tmp > same_num){
      same_num = same_num_tmp;
      res = i;
    }
    else if (same_num == same_num_tmp){
      if (i < res && res != -1)
        res = i;
    }
  }

  return res;
}

int main()
{
  int n, id;
  cin >> n >> id;
  // cout << "n: " << n << "id: " << id << endl;
  cin.get();
  vector<vector<int>> users;
  for(int i=0;i<n;i++)
  {
    int tmp;
    vector<int> temp;
    cin >> tmp;
    temp.push_back(tmp);

    while (cin.get() != '\n'){
      cin >> tmp;
      temp.push_back(tmp);
    }

    users.push_back(temp);
  }
  int res = solve(users, id);
  cout << res << endl;

  return 0;
}