
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	vector <int> nums;

	int m = 0;
	int p = 0;
	int n;

	ifstream in(argv[1]);

	if (in.is_open())
	{
		while (in>>n)
		{
			nums.push_back(n);
		}
	}
	
	in.close();
	

	for (int i = 0; i < nums.size(); i++)
	{
		m = m + nums[i];
	}

	m = m / nums.size(); // целевое число

	for (int i = 0; i < nums.size(); i++)
	{
		p = p + abs(m - nums[i]);
	}

	cout << p;

	return 0;
}
