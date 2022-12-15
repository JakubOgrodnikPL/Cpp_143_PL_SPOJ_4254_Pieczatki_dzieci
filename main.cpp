#include <iostream>
#include <string>
using namespace std;
int howMany5(string);

string operator++(string &s)
{
	if (s == "9")
	{
		s = string("10");
		return s;
	}
	else if (s[s.length() - 1] != '9')
	{
		s = s.substr(0, s.length()-1) + string(1,s[s.length()-1]+1);
		return s;
	}
	else
	{
		string temp = s.substr(0, s.length()-1);
		s =  ++temp + "0";
		return s;
	}
	return s;
}

int main()
{
	string n;
	int k, i, j;

	cin >> n >> k;
	++n;

	while (howMany5(n) < k)
	{
		for (i = n.length() - 1; i >= 0; --i)
			if (n[i] != '5')
				break;
		if (i > 0)
		{
			if (n[i] < '5')
			{
				n[i] = '5';
			}
			else
			{
				n[i] = '5';
				j = i - 1;
				while (1)
					if (j >= 0)
					{
						if (n[j] == '4')
						{
							n[i] = '0';
							n[j] = '5';
							break;
						}
						else if (n[j] < '9')
						{
							++n[j];
							break;
						}
						else
						{
							n[j] = '0';
							--j;
						}
					}
					else
					{
						n = "1" + n;
						break;
					}
			}
		}
		else if (i == 0)
		{
			if (n[i] < '5')
			{
				n[i] = '5';
			}
			else
			{
				n = "15" + n.substr(1, string::npos);
			}
		}
		else
		{
			n = "5" + n;
		}
	}

	cout << n << endl;

	return 0;
}

int howMany5(string n)
{
// funkcja zliczajaca wystapienia cyfry 5 w zapisie liczby n
	int res = 0;

	for (int i = 0; i < n.length(); ++i)
		if (n[i] == '5')
			++res;
	return res;
}
