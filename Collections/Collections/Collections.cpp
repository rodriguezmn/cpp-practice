#include <iostream>
using std::cout;
using std::cin;

#include <string>
using std::string;

#include <vector>
using std::vector;
using std::begin;
using std::end;

#include <algorithm> 
using std::sort;
using std::count;

int main()
{
	vector<int> nums; 

	for (int i = 0; i < 10; i++)
	{
		nums.push_back(i);
	}

	for (auto item : nums)
	{
		cout << item << " ";
	}
	cout << '\n';

	vector<string> words;

	cout << "Enter three words: ";
	for (int i = 0; i < 3; i++)
	{
		string s;
		cin >> s;
		words.push_back(s);
	}

	for (auto item : words)
	{
		cout << item << " ";
	}
	cout << '\n';

	cout << "Int vector nums has " << nums.size() << " elements." << '\n';

	nums[5] = 3;
	nums[6] = -1;
	nums[1] = 99;

	for (auto item : nums)
	{
		cout << item << " ";
	}
	cout << '\n';

	for (unsigned int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << '\n';

	// Vector functions begin and end return iterators
	// Iterators can be dereferenced with *

	// the same as for (auto i = nums.begin(); i != nums.end(); i++)
	for (auto i = begin(nums); i != end(nums); i++) 
	
	{
		cout << *i << " ";
	}
	cout << '\n';


	// Sort vector alphabetically 

	// The same as sort(words.begin(), words.end());
	sort(begin(words), end(words)); 



	for (auto item : words)
	{
		cout << item << " ";
	}
	cout << '\n';

	int threes = count(begin(nums), end(nums), 3);
	cout << "Vector of ints has " << threes << " elements with value 3" << '\n';


	// words[0] is a collection of letters. The same member functions can be applied to it

	int tees = count(begin(words[0]), end(words[0]), 't');
	cout << "First word has " << tees << " letter t's" << '\n';

	return 0;

}

