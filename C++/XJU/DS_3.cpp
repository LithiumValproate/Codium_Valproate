// Adapted from my LeetCode submission
// user: Lithium Valproate
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Chars {
	char* data;
	size_t length;
	size_t capacity;

	Chars(const char* str = "") {
		length = strlen(str);
		capacity = length + 1;
		data = new char[capacity];
		strcpy(data, str);
	}

	Chars(const Chars& str1, const Chars& str2) {
		length = str1.length + str2.length;
		capacity = length + 1;
		data = new char[capacity];
		strcpy(data, str1.data);
		strcat(data, str2.data);
	}

	~Chars() {
		delete[] data;
	}

	Chars& operator=(const Chars& other) {
		if (this != &other) {
			delete[] data;
			length = other.length;
			capacity = other.capacity;
			data = new char[capacity];
			strcpy(data, other.data);
		}
		return *this;
	}
	
	Chars& operator+(const Chars& other) {
		return Chars(*this, other);
	}
	
	Chars sub_str(size_t start, size_t subLen) {
		if (start > length || subLen == 0)
			return Chars("");
		if (start + subLen > length)
			subLen = length - start;
		char* subData = new char[subLen + 1];
		strncpy(subData, data + start, subLen);
		subData[subLen] = '\0';
		Chars res(subData);
		delete[] subData;
		return res;
	}

	size_t find(const char* substr) const {
		if (!substr || !data)
			return static_cast<size_t>(-1);
		size_t sublen = strlen(substr);
		if (sublen > length)
			return static_cast<size_t>(-1);
		for (size_t i = 0; i <= length - sublen; i++) {
			for (size_t j = 0; j < sublen; j++) {
				if (data[i + j] != substr[j])
					break;
				if (j == sublen)
					return i;
			}
		}
		return static_cast<size_t>(-1);
	}
};

int str_cmp(const Chars& str1, const Chars& str2) {
	if (str1.length == str2.length) {
		while (*str1.data && *str2.data) {
			if (*str1.data > *str2.data) return 1;
			else if (*str1.data < *str2.data) return -1;
			str1.data++;
			str2.data++;
		}
		return 0;
	} else if (str1.length > str2.length) {
		return 1;
	} else return -1;
}

int main() {
	while (1) {
		cout << "Enter number to select functions\n"
		     << "1. Return length of string\n"
		     << "2. Compare two strings\n"
		     << "3. Link two strings\n"
		     << "4. Create a new substring\n"
		     << "5. Find index of a substring\n"
		     << "6. Insert characters from an index\n"
		     << "7. Delete characters from an index\n"
		     << "8. Exit" << endl;
		int f;
		cin >> f;
		switch (f) {
			case 1:
				string input;
				cout << "Input the string\n";
				getline(cin, input);
				Chars str(input);
				cout << "Length is " << str.length << endl;
			case 2:
				string in1, in2;
				cout << "Input first string: ";
				getline(cin, in1);
				cout << endl << "Input second string: ";
				getline(cin, in2);
				cout << endl;
				Chars str1(in1), str2(in2);
				int res = str_cmp(in1, in2);
				switch (res) {
					case 0:
						cout << "Equal\n";
						break;
					case 1:
						cout << "First string is greater than second string\n";
						break;
					case -1:
						cout << "First string is smaller than second string\n";
						break;
					default:
						break;
				}
			case 3:
				string in1, in2;
				cout << "Input first string: ";
				getline(cin, in1);
				cout << endl << "Input second string: ";
				getline(cin, in2);
				cout << endl;
				Chars str1(in1), str2(in2);
				Chars ans = str1 + str2;
				cout << "Concatenated string: " << ans << endl;
			case 4:
				string input;
				cout << "Input origin string: ";
				getline(cin, input);
				Chars str(input);
				int start, len;
				cout << "Starting at: ";
				cin >> start;
				cout << endl << "Length is: ";
				cin >> len;
				Chars ans = str.sub_str(start, len);
				cout << "New string: " << ans << endl;
			case 5:
								
			default:
				cout << endl;
				break;
		}
	}
	system("pause");
	return 0;
}
