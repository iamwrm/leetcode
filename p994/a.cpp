#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int minute = 0;
        while (true)
        {
            bool changed = false;

            for (int i = 0; i < grid.size(); i++)
            {
                for (int j = 0; j < grid[0].size(); j++)
                {
                    if (grid[i][j] == 2)
                    {
                        if ((i - 1 >= 0) && (grid[i - 1][j] == 1))
                        {
                            grid[i - 1][j] = 3;
                        }
                        if ((j - 1 >= 0) && (grid[i][j - 1] == 1))
                        {
                            grid[i][j - 1] = 3;
                        }
                        if ((i + 1 < grid.size()) && (grid[i + 1][j] == 1))
                        {
                            grid[i + 1][j] = 3;
                        }
                        if ((j + 1 < grid[0].size()) && (grid[i][j + 1] == 1))
                        {
                            grid[i][j + 1] = 3;
                        }
                    }
                }
            }
            for (int i = 0; i < grid.size(); i++)
            {
                for (int j = 0; j < grid[0].size(); j++)
                {
                    cout << grid[i][j] << " ";
                    if (grid[i][j] == 3)
                    {
                        grid[i][j] = 2;
                        changed = true;
                    }
                }
                cout << endl;
            }
            if (changed == false)
            {
                break;
            }
            minute++;
        }

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {

                    return -1;
                }
            }
        }

        return minute;
    }
};

int main(int argc, const char **argv)
{
    vector<vector<int>> v;
    v.push_back(vector<int>{1, 2});
    Solution s;
    int num = s.orangesRotting(v);
    cout << num;
    return 0;
}