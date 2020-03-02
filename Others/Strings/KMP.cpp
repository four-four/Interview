#include <string>
#include <vector>
#include <iostream>

using namespace std;

class KMP {
private:
    int M;
    vector<vector<int>> dp;

public:
    void printDP() {
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                if (dp[i][j] != 0) {
                    cout << i << " meet " << j << " next " << dp[i][j] << endl;
                }
            }
        }
    }
    void calculatePattern(string pat) {
        M = pat.length();
        vector<int> row;
        row.assign(256, 0);
        dp.assign(M, row);

        dp[0][pat[0]] = 1;
        int X = 0;
        for (int j = 1; j < M; j++) {
            for (int c = 0; c < 256; c++) {
                if (pat[j] == c) {
                    dp[j][c] = j + 1;
                } else {
                    dp[j][c] = dp[X][c];
                }
            }
            X = dp[X][pat[j]];
        }
    }

    int search(string txt) {
        int N = txt.length();

        int j = 0;
        for (int i = 0; i < N; i++) {
            j = dp[j][txt[i]];
            if (j == M) {
                return i - M + 1;
            }
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    KMP kmp;
    string pat = "aaab";
    string txt = "aaacaaab";
    kmp.calculatePattern(pat);
    //kmp.printDP();
    int result = kmp.search(txt);
    cout << result << endl;
}