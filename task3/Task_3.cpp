
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

void search( json& j, map <int, string> v)
{
	int t;
	string temp;

	for (auto it = j.begin(); it != j.end(); ++it)
	{
		if (it->is_structured())
		{
			search(*it, v);
		}
		else
		{
			if (it.key() == "id")
			{
				t = it.value();
				
			}
			if (it.key() == "value")
			{
				it.value() = v[t];
			}
			
		}
	}
}

int main(int argc, char* argv[])
{
	map <int, string> value;

	ifstream in(argv[1]);
	json json1 = json::parse(in);

	for (auto data : json1["values"])
	{
		value[data["id"]] = data["value"];

	}

	in.close();

	ifstream in2(argv[2]);
	json json2 = json::parse(in2);

	search(json2, value);

	ofstream out(argv[3]);

	out << json2;

	in2.close();
	out.close();

	return 0;
}