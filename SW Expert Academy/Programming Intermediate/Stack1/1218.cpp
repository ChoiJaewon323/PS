#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
	int test_case;

	for (test_case = 1; test_case <= 10; test_case++)
	{
		stack<char> st;
		string brackets;
		int length;
		int result = 1;
		
		cin >> length;
		cin >> brackets;

		for (auto b : brackets)
		{
			if (b == '(' || b == '[' || b == '{' || b == '<')	// ���� ��ȣ�϶�
			{
				st.push(b);
			}
			else
			{
				if (st.empty())	// ������ ��������� pop�Ұ� ���� -> ��ȿ X
				{
					result = 0;
					break;
				}
				else
				{
					char temp = st.top();

					if (b == ')' && temp == '(')	// () ��ġ
					{
						st.pop();
					}
					else if (b == ')' && temp != '(')	// () ����ġ
					{
						result = 0;
						break;
					}

					if (b == ']' && temp == '[')	// [] ��ġ
					{
						st.pop();
					}
					else if (b == ']' && temp != '[')	// [] ����ġ
					{
						result = 0;
						break;
					}

					if (b == '}' && temp == '{')	// {} ��ġ
					{
						st.pop();
					}
					else if (b == '}' && temp != '{')	// {} ����ġ
					{
						result = 0;
						break;
					}

					if (b == '>' && temp == '<')	// <> ��ġ
					{
						st.pop();
					}
					else if (b == '>' && temp != '<')	// <> ����ġ
					{
						result = 0;
						break;
					}
				}
			}
		}

		if (!st.empty())
		{
			result = 0;
		}

		cout << "#" << test_case << " " << result << '\n';
	}
}