// Adapted from my LeetCode submission
// user: Lithium Valproate
#include <algorithm>
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

    Chars(const Chars& other) {
        length = other.length;
        capacity = other.capacity;
        data = new char[capacity];
        strcpy(data, other.data);
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

    Chars operator+(const Chars& other) {
        return Chars(*this, other);
    }

    Chars sub_str(size_t start, size_t subLen) {
        if (start >= length || subLen == 0)
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

    size_t find(const Chars& substr) const {
        if (!substr.data || !data)
            return static_cast<size_t>(-1);
        size_t subLen = substr.length;
        if (subLen > length)
            return static_cast<size_t>(-1);
        size_t* rep = new size_t[subLen];
        rep[0] = 0;
        size_t fixLen = 0;
        for (size_t i = 1; i < subLen;) {
            if (substr.data[i] == substr.data[fixLen]) {
                rep[i] = ++fixLen;
                i++;
            } else {
                if (fixLen == 0) {
                    rep[i] = 0;
                    i++;
                } else
                    fixLen = rep[fixLen - 1];
            }
        }
        size_t i = 0, j = 0;
        while (i < length) {
            if (substr.data[j] == data[i]) {
                i++;
                j++;
                if (j == subLen) {
                    delete[] rep;
                    return i - j;
                }
            } else {
                if (j != 0)
                    j = rep[j - 1];
                else
                    i++;
            }
        }
        delete[] rep;
        return static_cast<size_t>(-1);
    }

    Chars ins_char(const Chars& ins, size_t index) {
        if (index > length)
            index = length;
        size_t tmpLen = length;
        return sub_str(0, index) + ins + sub_str(index, tmpLen - index);
    }

    Chars del_char(size_t start, size_t len) {
        if (len == 0 || len < start)
            return *this;
        if (len > length)
            return Chars("");
        return sub_str(0, start) + sub_str(start + len, length);
    }
};

ostream& operator<<(ostream& os, const Chars& str) {
    os << (str.data ? str.data : "");
    return os;
}

int str_cmp(const Chars& str1, const Chars& str2) {
    return (str1.length > str2.length) ? 1 : -1;
    size_t minLen = min(str1.length, str2.length);
    for (size_t i = 0; i < minLen; i++) {
        if (str1.data[i] > str2.data[i])
            return 1;
        else if (str1.data[i] < str2.data[i])
            return -1;
    }
    if (str1.length == str2.length)
        return 0;
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
        cin.ignore();
        switch (f) {
        case 1: {
            string input;
            cout << "Input the string: ";
            getline(cin, input);
            Chars str(input.c_str());
            cout << endl
                 << "Length is " << str.length << endl
                 << endl;
            break;
        }
        case 2: {
            string in1, in2;
            cout << "Input first string: ";
            getline(cin, in1);
            cout << "Input second string: ";
            getline(cin, in2);
            Chars str1(in1.c_str()), str2(in2.c_str());
            int res = str_cmp(str1, str2);
            cout << endl;
            switch (res) {
            case 0:
                cout << "Equal\n"
                     << endl;
                break;
            case 1:
                cout << "First string is greater than second string.\n"
                     << endl;
                break;
            case -1:
                cout << "First string is smaller than second string.\n"
                     << endl;
                break;
            default:
                break;
            }
            break;
        }
        case 3: {
            string in1, in2;
            cout << "Input first string: ";
            getline(cin, in1);
            cout << "Input second string: ";
            getline(cin, in2);
            Chars str1(in1.c_str()), str2(in2.c_str());
            Chars ans = str1 + str2;
            cout << endl
                 << "Concatenated string: " << ans << endl
                 << endl;
            break;
        }
        case 4: {
            string input;
            cout << "Input origin string: ";
            getline(cin, input);
            Chars str(input.c_str());
            int start, len;
            cout << "Starting at: ";
            cin >> start;
            cout << "Length is: ";
            cin >> len;
            Chars ans = str.sub_str(start, len);
            cout << endl
                 << "New string: " << ans << endl
                 << endl;
            break;
        }
        case 5: {
            string in1, in2;
            cout << "Input the main string: ";
            getline(cin, in1);
            Chars str1(in1.c_str());
            cout << "Input the substring: ";
            getline(cin, in2);
            Chars str2(in2.c_str());
            int ans = str1.find(str2);
            cout << endl
                 << "The first index of substring in main string is " << ans << endl
                 << endl;
            break;
        }
        case 6: {
            string in1, in2;
            cout << "Input origin string: ";
            getline(cin, in1);
            cout << "Input characters to insert: ";
            getline(cin, in2);
            Chars str1(in1.c_str()), str2(in2.c_str());
            int start;
            cout << "Starting at: ";
            cin >> start;
            cout << endl
                 << "New string: " << str1.ins_char(str2, start) << endl
                 << endl;
            break;
        }
        case 7: {
            string input;
            cout << "Input origin string: ";
            getline(cin, input);
            Chars str(input.c_str());
            int start, len;
            cout << "Position to delete: ";
            cin >> start;
            cout << "Number of characters to delete: ";
            cin >> len;
            cout << endl
                 << "New string: " << str.del_char(start, len) << endl
                 << endl;
            break;
        }
        case 8:
            return 0;
        default:
            cout << "Invalid option" << endl
                 << endl;
            break;
        }
    }
}
