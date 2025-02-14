
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	vector <int> nums;

	int n = atoi(argv[1]);
	int m = atoi(argv[2]);
	int j = 0;


	for (int i = 1; i <= 5; i++)
	{
		nums.push_back(i);
	}

	string str = to_string(nums[0]);

	while (true)
	{
		j = (j + m - 1) % n;

		if (nums[0] == nums[j])
		{
			break;
		}

		str = str + to_string(nums[j]);
	}

	cout << str;

	return 0;
}
