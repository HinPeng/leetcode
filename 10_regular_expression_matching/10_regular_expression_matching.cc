#include <iostream>
#include <string>
#include <functional>
#ifdef _WIN32
#include <cstdlib>
#endif

using std::string;
using std::function;

bool isMatch(string s, string p);

// bool isMatchHelper(const string& s, const string& p, int sS, int pS);

int main()
{
  string s("aab");
  string p("c*a*b");

  int i = 1;
  if (isMatch(s, p))  i = 0;

  printf("%d", i);
  #ifdef _WIN32
  system("PAUSE");
  #endif
  return 0;
}

bool isMatch(string s, string p)
{
  const int sSize = s.size();
  const int pSize = p.size();

  function<bool(const string&, const string&, int, int)> Helper;
  Helper = [&](const string& s, const string& p, int sS, int pS) -> bool {
    if (pS == pSize)  return sS == sSize;

    if (p[pS+1] != '*'){
      if (sS < sSize && (p[pS] == s[sS] || p[pS] == '.')) return Helper(s, p, sS+1, pS+1);
    }
    else{
      if (Helper(s, p, sS, pS+2)) return true;
      while (sS < sSize && (p[pS] == s[sS] || p[pS] == '.'))  if (Helper(s, p, ++sS, pS+2)) return true;
    }

    return false;
  };

  if (Helper(s, p, 0, 0))
    return true;

  return false;
}

// bool isMatchHelper(const string& s, const string& p, int sS, int pS)
// {

// }