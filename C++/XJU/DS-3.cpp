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

    Chars(const Chars& str) {
        length = str.length;
        capacity = str.capacity;
        data = new char[capacity];
        strcpy(data, str.data);
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

    size_t find(const char* substr) const {
        if (!substr || !data)
            return static_cast<size_t>(-1);
        size_t sublen = strlen(substr);
        if (sublen > length)
            return static_cast<size_t>(-1);
        for (size_t i = 0; i <= length - sublen; i++) {
            size_t j = 0;
            for (; j < sublen; j++) {
                if (data[i + j] != substr[j])
                    break;
            }
            if (j == sublen)
                return i;
        }
        return static_cast<size_t>(-1);
    }
};

int main() {
    cout << "Input your first string:\n";
    string input1;
    getline(cin, input1);
    Chars strs[2];
    strs[0] = Chars(input1.c_str());
    cout << "Input your second string:\n";
    string input2;
    getline(cin, input2);
    strs[1] = Chars(input2.c_str());
    cout << "Length of the first string: " << strs[0].length << endl
         << "Length of the second string: " << strs[1].length << endl;
    size_t pos = strs[0].find(strs[1].data);
    if (pos != static_cast<size_t>(-1))
        cout << "The second string is a substring of the first string.\n"
             << "The starting index of the substring is: " << pos << endl;
    else
        cout << "The second string is not a substring of the first string.\n";
    system("pause");
    return 0;
}