#include <iostream>
#include <unordered_map>

using namespace std;

#define MAX_STR_BUFFER 100

void pickChars(int N, unordered_map<char, int> &megazines);
int checkForXmas(unordered_map<char, int> &megazines);

int main() {
    int num_magazines, num_lines;
    int num_Xmas;
    unordered_map<char, int> megazines;

    cin >> num_magazines;

    while (num_magazines--) {
        cin >> num_lines; getchar();

        pickChars(num_lines, megazines);
    }

    num_Xmas = checkForXmas(megazines);

    cout << num_Xmas << '\n';

    return 0;
}

void pickChars(int num_lines, unordered_map<char, int> &megazines) {
    string str;

    while (num_lines--) {
        getline(cin, str, '\n');

        for (int i = 0; i < str.size(); i++) {
            megazines[tolower(str[i])]++;
        }
    }
}

int checkForXmas(unordered_map<char, int> &megazines) {
    const string Xmas_greeting = "merrychristmas";
    int count = 0;

    while (true) {
        for (int i = 0; i < Xmas_greeting.size(); i++) {
            if (!megazines[Xmas_greeting[i]]--) return count;
        }
        count++;
    }
}