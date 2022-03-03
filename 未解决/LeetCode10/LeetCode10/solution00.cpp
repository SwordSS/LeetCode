#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {

	}

private:
	void InitRule(string target_str)
	{
		rule_ptr = 0;
		for (int index_i = 0; index_i < target_str.size(); index_i++)
		{
			rule.push_back(""+ target_str[index_i]);
			if (index_i + 1 >= target_str.size())
			{
				if (target_str[index_i + 1] == '*')
				{
					rule.back() += '*';
					index_i++;
				}
				else if (target_str[index_i + 1] == '.')
				{
					rule.back() += '.';
					index_i++;
				}
			}
		}
	}

	bool RuleJudge(string source_str,int index_j) {

	}

private:
	vector<string> rule;
	int rule_ptr;
};

void test()
{
	string source_str = "aa";
	string target_str = "a*";
	Solution slt;
	cout << slt.isMatch(source_str, target_str) << endl;
}

int main()
{

}