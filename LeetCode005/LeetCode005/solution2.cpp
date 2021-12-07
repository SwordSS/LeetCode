#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() < 2)return s;

		int start = -1;
		int end = -1;

		for (int index_i = 0; index_i < s.size(); index_i++)
		{
			pair<int,int> single = ExpendAroundCenter(s, index_i, index_i);
			pair<int,int> both = ExpendAroundCenter(s, index_i, index_i+1);
			if (single.second - single.first > end - start)
			{
				start = single.first;
				end = single.second;
			}
			if (both.second - both.first > end - start)
			{
				start = both.first;
				end = both.second;
			}
		}
		return s.substr(start,end- start + 1);
	}

	pair<int,int> ExpendAroundCenter(const string& s, int index_i, int index_j)
	{
		while (index_i >= 0 && index_j <= s.size()-1)
		{
			if (s[index_i] == s[index_j])
			{
				index_i--;
				index_j++;
			}
			else
			{
				break;
			}
		}
		return make_pair(index_i+1, index_j-1);
	}
};


void test()
{
	string test_str = "abbab";
	Solution slt;
	cout << slt.longestPalindrome(test_str) << endl;
}

int main()
{
	test();
}