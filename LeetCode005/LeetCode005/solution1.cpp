#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

void PrintList(const vector<vector<int>>& dp)
{
	static int i = 0;
	cout <<"i : "<< i << endl;
	i++;
	for (int i = 0; i < dp.size(); i++)
	{
		for (int j = 0; j < dp.size(); j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

class Solution {
public:
	string longestPalindrome(string s) {
		int str_size = s.size();
		if (str_size < 2) return s;

		max_str_index = make_pair(-1, -1);
		max_length = -1;

		vector<vector<int>> dp(str_size, vector<int>(str_size,0));
		queue<pair<int, int>> dp_queue;

		/*  
			初始化状态
			1 2 0 0 0
			0 1 2 0 0
			0 0 1 2 0
			0 0 0 1 2
			0 0 0 0 1
		*/
		for (int i = 0; i < str_size; i++)
		{
			int new_length = 1;
			dp[i][i] = new_length;
			JudgeAndUpdateMax(new_length, i, i);
			dp_queue.push(make_pair(i, i));
			PrintList(dp);
			if (i + 1 < str_size)
			{
				if (s[i] == s[i + 1])
				{
					int new_length = 2;
					dp[i][i + 1] = new_length;
					JudgeAndUpdateMax(new_length, i, i+1);
					dp_queue.push(make_pair(i, i+1));
					PrintList(dp);
				}
			}
		}
		
		/*
			利用队列等右上方向传播
			1 2 0 0 0
			0 1 2 0 0
			0 0 1 2 0
			0 0 0 1 2
			0 0 0 0 1
		*/
		while (dp_queue.size() > 0)
		{
			pair<int, int> dp_index = dp_queue.front();
			dp_queue.pop();
			int next_i = dp_index.first - 1;
			int next_j = dp_index.second + 1;
			if ((next_i < str_size && next_i >= 0) && (next_j < str_size &&next_j >= 0))
			{
				if (s[next_i] == s[next_j])
				{
					if (dp[dp_index.first][dp_index.second] > 0)
					{
						int new_length = dp[dp_index.first][dp_index.second] + 2;
						dp[next_i][next_j] = new_length;
						JudgeAndUpdateMax(new_length, next_i, next_j);
						dp_queue.push(make_pair(next_i, next_j));
						PrintList(dp);
					}
				}
			}
		}

		return s.substr(max_str_index.first, max_length);

	}

private:
	void JudgeAndUpdateMax(const int& length,const int& index_i,const int& index_j)
	{
		if (length > max_length)
		{
			max_length = length;
			max_str_index.first = index_i;
			max_str_index.second = index_j;
		}
}	

public:
	pair<int, int> max_str_index;
	int max_length;
};


void test()
{
	string test_str = "aaaaa";
	Solution slt;
	cout << slt.longestPalindrome(test_str) << endl;
}

int main()
{
	test();
}