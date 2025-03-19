#include <cctype>
#include <exception>
#include <iostream>
#include <string>
using namespace std;

class Stack {
  private:
    int* data;
    int top;
    int capacity;

    void resize() {
        int newCapacity = capacity * 2;
        int* newData = new int[newCapacity];
        for (int i = 0; i <= top; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

  public:
    Stack(int initSize = 20) : top(-1), capacity(initSize) {
        data = new int[capacity];
    }

    ~Stack() { delete[] data; }

    bool is_empty() const { return top == -1; }

    bool is_full() const { return top == capacity - 1; }

    bool push(int value) {
        if (is_full()) {
            resize();
        }
        data[++top] = value;
        return true;
    }

    bool pop(int& value) {
        if (is_empty())
            return false;
        value = data[top--];
        return true;
    }

    bool peek(int& value) const {
        if (is_empty())
            return false;
        value = data[top];
        return true;
    }
};

int detect(const string& numStr) {
    string digits = numStr;
    int base = 10;
    if (digits.size() >= 2) {
        if (digits.substr(0, 2) == "0x" || digits.substr(0, 2) == "0X") {
            base = 16;
            digits = digits.substr(2);
        } else if (digits.substr(0, 2) == "0b" || digits.substr(0, 2) == "0B") {
            base = 2;
            digits = digits.substr(2);
        } else if (digits[0] == '0') {
            base = 8;
            digits = digits.substr(1);
        }
    }
    auto is_valid_digit = [base](char c) -> bool {
        c = toupper(c);
        if (base <= 10) {
            return c >= '0' && c < ('0' + base);
        } else if (base == 16) {
            return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F');
        }
        return false;
    };
    for (char c : digits)
        if (!is_valid_digit(c))
            return -1;
    try {
        return stoi(digits, nullptr, base);
    } catch (const exception& e) {
        return -1;
    }
}

string convert(long long num, int base) {
    long long tmp = num;
    if (tmp == 0)
        return "0";
    Stack s;
    while (tmp > 0) {
        int remainder = tmp % base;
        s.push(remainder);
        tmp /= base;
    }
    string ans;
    int digit;
    while (!s.is_empty()) {
        s.pop(digit);
        if (base == 16 && digit >= 10)
            ans += char('A' + (digit - 10));
        else
            ans += to_string(digit);
    }
    return ans;
}

int main() {
    string num;
    cout << "Enter a number.\n"
         << "Binary: 0b--\n"
         << "Octal: 0--\n"
         << "Decimal: --\n"
         << "Hexadecimal: 0x--\n";
    cin >> num;
    int value = detect(num);
    if (value == -1) {
        cout << "Invalid number input.\n";
        system("pause");
        return 1;
    }
    cout << "Conversion results:" << endl;
    cout << "Binary: " << convert(value, 2) << endl;
    cout << "Octal: " << convert(value, 8) << endl;
    cout << "Decimal: " << convert(value, 10) << endl;
    cout << "Hexadecimal: " << convert(value, 16) << endl;
    system("pause");
    return 0;
}