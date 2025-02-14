
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{

	double x0;
	double y0;
	double R;

	ifstream in1(argv[1]);

	if (in1.is_open())
	{
		double a;
		int i = 0;

		while (in1 >> a)
		{
			if (i == 0)
			{
				x0 = a;
				i++;
				continue;
			}
			if (i == 1)
			{
				y0 = a;
				i++;
				continue;
			}
			if (i == 2)
			{
				R = a;
				i++;
				continue;
			}
		}
	}

	in1.close();

	int p[100][2];
	int j = 0;
	
	ifstream in2(argv[2]);

	if (in2.is_open())
	{
		
		double x;
		double y;

		while (in2 >> x >> y)
		{
			p[j][0] = x;
			p[j][1] = y;
			j++;
		}
	}

	in2.close();

	for (int i = 0; i < j; i++)
	{
		if (pow(p[i][0] - x0, 2) + pow(p[i][1] - y0, 2) < pow(R, 2))
		{
			cout << "1" << "\n";
			continue;
		}

		if (pow(p[i][0] - x0, 2) + pow(p[i][1] - y0, 2) > pow(R, 2))
		{
			cout << "2" << "\n";
			continue;
		}

		if (pow(p[i][0] - x0, 2) + pow(p[i][1] - y0, 2) == pow(R, 2))
		{
			cout << "0" << "\n";
			continue;
		}
	}

	return 0;
}
