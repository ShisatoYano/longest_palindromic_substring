#include <bits/stdc++.h>

using namespace std;

// print a substring
// str[low...high]
void print_substr(string str, int low, int high) {
    for (int i = low; i <= high; ++i) {
        cout << str[i];
    }
}

// print the longest substring
// it also returns the length
int longest_palindromic(string str) {
    // length of input string
    int n = str.size();

    // table[i][j] will be false if substring
    // str[i..j] is not palindrome
    // else table[i][j] will be true
    bool table[n][n];
    memset(table, 0, sizeof(table));

    // all substrings of length 1
    // are palindromes
    int max_len = 1;

    for (int i = 0; i < n; ++i) {
        table[i][i] = true;
    }

    // check for sub string of length2
    int start = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (str[i] == str[i + 1]) {
            table[i][i + 1] = true;
            start = i;
            max_len = 2;
        }
    }

    // check for lengths greater than 2
    // k is length of substring
    for (int k = 3; k <= n; ++k) {
        // fix starting index
        for (int i = 0; i < n - k + 1; ++i) {
            // get ending index of substring from
            // starting index i and length k
            int j = i + k - 1;

            if (table[i + 1][j - 1] && str[i] == str[j]) {
                table[i][j] = true;

                if (k > max_len) {
                    start = i;
                    max_len = k;
                }
            }
        }
    }

    cout << "Longest palindrome substring is: ";
    print_substr(str, start, start + max_len - 1);

    return max_len;
}

int main() {
    string str = "forgeeksskeegfor";

    int length = longest_palindromic(str);

    cout << "\nLength is: " << length;

    return 0;
}
