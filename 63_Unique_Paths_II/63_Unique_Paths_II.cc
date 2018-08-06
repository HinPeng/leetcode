#include <iostream>
#include <vector>
#ifdef _WIN32
#include <cstdlib>
#endif

using std::vector;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);

int main()
{
  vector<vector<int>> vv;
  vector<int> v1 = {0,0,0};
  vector<int> v2 = {0,1,0};
  vector<int> v3 = {0,0,0};
  vv.push_back(v1);
  vv.push_back(v2);
  vv.push_back(v3);

  int res = uniquePathsWithObstacles(vv);
  printf("%d\n", res);
  #ifdef _WIN32
  system("PAUSE");
  #endif

  return 0;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
  int row = obstacleGrid.size();
  int col = obstacleGrid[0].size();

  vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
  dp[0][1] = 1;
  for (int i = 1; i <= row; ++i)
    for (int j = 1; j <= col; ++j)
      if (!obstacleGrid[i-1][j-1])
        dp[i][j] = dp[i-1][j] + dp[i][j-1];

  return dp[row][col];
}