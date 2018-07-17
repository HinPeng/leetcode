#include <iostream>
#include <functional>

using std::function;
using std::cout;
using std::endl;

typedef function<void()> Closure;
typedef function<void(Closure)> Runner;

void Process(int a, int b){cout << a+b << endl;}

int main()
{
  Runner runner = nullptr;
  for (int i = 0; i < 10; ++i){
    runner([=]() { Process(i, i+1); });
  }

  return 0;
}