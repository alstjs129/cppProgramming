#include <iostream>

using namespace std;

string add(string num1, string num2) {
    string result;

    int carry = 0;
    int size1 = num1.size() - 1;
    int size2 = num2.size() - 1;

    while (size1 >= 0 || size2 >= 0 || carry > 0) {
        int sum = carry;

        if (size1 >= 0) {
            sum += num1[size1] - '0';
            size1 -= 1;
        }

        if (size2 >= 0) {
            sum += num2[size2] - '0';
            size2 -= 1;
        }
        
        result = to_string(sum % 10) + result;
        carry = sum / 10;
    }
    return result;
}

string sub(string num1, string num2) {
    string result;

    int sign = 0;
    if (num1.compare(num2) == -1) {
        swap(num1, num2);
        sign = 1;
    } else if (num1.compare(num2) == 0) return "0";

    int borrow = 0;
    int size1 = num1.size() - 1;
    int size2 = num2.size() - 1;

    while (size1 >= 0) {
        int diff = num1[size1] - '0' - borrow;
        size1 -= 1;

        if (size2 >= 0) {
            diff -= num2[size2] - '0';
            size2 -= 1;
        }

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else borrow = 0;

        result = to_string(diff) + result;
    }

    while (result.front() == '0') {
        result.erase(0, 1);
    }

    if (sign) return result.insert(0, "-");
    else return result;
}

int main() {
    // "1234567891234567890123
    string num1, num2;
    cout << "First number  >> ";
    cin >> num1;

    cout << "Second number >> ";
    cin >> num2;

    cout <<"Sum           >> " << add(num1, num2) << endl;
    cout <<"Sub           >> " << sub(num1, num2) << endl;

    return 0;
}