#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution1
{
public:
	void GenerateAllHelper(int couple, vector<string>& result)
	{
		if (couple <= 0)return;
		string str = "";
		GenerateAll(str, couple *2, result);
	}

private:
	void GenerateAll(string& str, int num, vector<string>& result)
	{
		//��ֹ����
		if (str.size() == num)
		{
			if (IsVaild(str))
			{
				result.push_back(str);
			}
			return;
		}

		//����
		str += '(';
		GenerateAll(str, num, result);
		str.pop_back();
		str += ')';
		GenerateAll(str, num, result);
		str.pop_back();
	}

	bool IsVaild(string& str)
	{
		int balance = 0;
		for (unsigned int index_i=0; index_i < str.size(); index_i++)
		{
			if (str[index_i] == '(')
			{
				balance++;
			}
			else
			{
				balance--;
			}
			if (balance < 0)return false;//����㣬һ����С��0�������Ϊ����
		}
		return balance == 0;
	}
};


class Solution2
{
	public:
		void GenerateAllHelper(int couple, vector<string>& result)
		{
			if (couple <= 0)return;
			string str = "";
			GenerateAll(str, couple * 2, 0,0,result);
		}

	private:
		void GenerateAll(string& str, int num, int open,int close,vector<string>& result)
		{
			//��ֹ����
			if (open + close == num)
			{
				result.push_back(str);
				return;
			}

			//����
			if (open < num / 2)
			{
				str += '(';
				GenerateAll(str, num, open+1,close,result);
				str.pop_back();
			}

			if (close < open)
			{
				str += ')';
				GenerateAll(str, num, open, close+1,result);
				str.pop_back();
			}

		}
};

void test1()
{
	Solution2 slt;
	vector<string> result;
	slt.GenerateAllHelper(3, result);
	for (auto menber : result)
	{
		cout << menber << endl;
	}

}

int main()
{
	test1();
}