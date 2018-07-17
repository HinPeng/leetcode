#include <iostream>
#include <string>
#include <vector>

using std::string;

string Manacher(string str);
string longestPalindromic(string str);  // use dp
// TODO: can eliminate the extra O(n*2) space

int main()
{
  string s1("abbab");
  string s2("abbabb");
  string s3("waabwswfd");
  // std::cout << Manacher(s1) << std::endl;
  // std::cout << Manacher(s2) << std::endl;
  // std::cout << Manacher(s3) << std::endl;

  std::cout << longestPalindromic(s1) << std::endl;
  std::cout << longestPalindromic(s2) << std::endl;
  std::cout << longestPalindromic(s3) << std::endl;
}

string Manacher(string str)
{
  string tmp("$#");
  for (int i = 0; i < str.size(); ++i){
    tmp += str[i];
    tmp += "#";
  }

  std::vector<int> p(tmp.size(), 0);
  int mx = 0, id = 0, resLen = 0, resCenter = 0;
  for (int i = 1; i < tmp.size(); ++i){
    p[i] = mx > i ? std::min(p[2 * id - i], mx - i) : 1;
    while (tmp[i + p[i]] == tmp[i - p[i]])
      ++p[i];
    if (mx < i + p[i]){
      mx = i + p[i];
      id = i;
    }
    if (resLen < p[i]){
      resLen = p[i];
      resCenter = i;
    }
  }

  return str.substr((resCenter - resLen) / 2, resLen - 1);
}

string longestPalindromic(string str)
{
  const int length = str.size();
  int *dp = new int[length * length]();

  int len = 0, left = 0, right = 0;

  for (int j = 0; j < length; ++j){
    for (int i = 0; i <= j; ++i){
      if ((str[i] == str[j]) && (j - i <= 2 || dp[(i + 1) * length + j - 1]))
        dp[i * length + j] = 1;

      if ((dp[i * length + j] == 1) && len < j - i + 1){
        len = j - i + 1;
        left = i;
        right = j;
      }
    }
  }

  return str.substr(left, right - left + 1);
}