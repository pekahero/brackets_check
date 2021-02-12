#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool brackets_correct(const string &text_to_test) {
	//Stack to store brackets
	vector<char> stack;
	// If bracket is opening, program puts it to the stack.
	// If bracket is closing and top stack element matches respective opening bracket, 
	// program deletes last element of the stack.
	for (size_t i = 0; i < text_to_test.length(); i++) {
		if ((text_to_test[i] == '(') || (text_to_test[i] == '[') || (text_to_test[i] == '{')) {
			stack.push_back(text_to_test[i]);
		}
		if ((text_to_test[i] == ')') || (text_to_test[i] == ']') || (text_to_test[i] == '}'))
			if (stack.size() && (((text_to_test[i] == ')') && (stack.back() == '('))
				|| ((text_to_test[i] == ']') && (stack.back() == '['))
				|| ((text_to_test[i] == '}') && (stack.back() == '{')))) {
				stack.pop_back();
			}
			// If bracket is closing and top stack element doesn't matche respective opening bracket, 
			// program returns false, brackets placed incorrectly.
			else
				return false;
	}
	// If stack size != 0, brackets placed incorrectly.
	if (stack.size())
		return false;
	// If size == 0, all brackets matched correctly.
	else
		return true;
}


int main()
{
	cout << "Enter text to check brackets:" << endl;
	//Text to check for brackets correctness.
	string text_to_test;
	getline(cin, text_to_test);

	if (brackets_correct(text_to_test))
		cout << "Brackets are correct." << endl;
	else
		cout << "Brackets are incorrect." << endl;
}


