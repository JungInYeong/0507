#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ifstream input_file("hello.txt");
	string line;
	vector<string> lines;
	if (input_file.is_open())
	{
		while (getline(input_file, line))
		{
			cout << line << endl;
			lines.push_back(line);
		}
		
	}
	else
	{
		cout << "파일 없음" << endl;
		return 1;
	}
	input_file.close();


	cout << endl;
	cout << "output.txt" << endl;
	ofstream output_file("output.txt");

	for (int i = lines.size() - 1; i >= 0; --i) {
		output_file << lines[i] << endl;
		cout << lines[i] << endl;
	}
	output_file.close();

	return 0;
}