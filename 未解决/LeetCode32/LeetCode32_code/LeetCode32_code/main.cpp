#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	int longestValidParentheses(string s)
	{
		vector<int> dp(s.size(),-1);
		dp[0] = 0;
		for (int index_i = 1; index_i <= s.size() - 1; index_i++)
		{
			if (s[index_i] == '(')
			{
				dp[index_i] = dp[index_i - 1];
			}
			else
			{
				int max_value = maxValueInString(s, index_i);
				dp[index_i] = max_value > dp[index_i - 1] ? max_value : dp[index_i - 1];
				cout << "max_value:" << max_value << endl;
			}
		}
		cout << "dp:" << endl;
		for (auto menber : dp)
		{
			cout << menber << " ";
		}
		cout << endl;
		return dp[s.size() - 1];
	}

private:
	int maxValueInString(string& s,int end)
	{
		int max_value = 0;
		for (int index_i = 0; index_i <= end; index_i++)
		{
			for (int index_j = index_i; index_j <= end; index_j++)
			{
				if (s[index_i] == '('&&s[index_j] == ')')
				{
					if (max_value < index_j - index_i)
					{
						max_value = index_j - index_i;
					}
				}
			}
		}
		return max_value;
	}
};

void test1()
{
	string str = "(()";
	Solution slt;
	cout << slt.longestValidParentheses(str) << endl;
}

int main()
{
	test1();
}
