#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    bool is_palindrome(int x) {
        if (x < 0)
            return false;
        vector<int> dig;
        do {
            int tmp = x % 10;
            dig.push_back(tmp);
            x /= 10;
        } while (x > 0);
        for (int d : dig)
            cout << d;
        cout << endl;
        for (int i = 0; i < dig.size() / 2; i++)
            if (dig[i] != dig[dig.size() - i - 1])
                return false;
        return true;
    }
};
int main() {
    Solution solution;
    int x;
    cin >> x;
    if (solution.is_palindrome(x))
        cout << "Is palindrome." << endl;
    else
        cout << "Isn't palindrome." << endl;
    system("pause");
    return 0;
}
