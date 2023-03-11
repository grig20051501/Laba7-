#include <iostream>
#include <string>
#include <vector>

using namespace std;

string text[100] = { "word well" };

string purify(string str) {
    string word = str;
    string restricted = ".,;:!?& ";
    for (int i = 0; i < word.size(); i++) {
        for (int j = 0; j < restricted.size(); j++) {
            if (word[i] == restricted[j]) {
                word.erase(i, 1);
            }
        }
    }
    return word;
}

vector<string> split(string str) {
    vector<string> words;
    return words;
}

int main()
{
    string word1 = ".abc, ";
    string word2 = purify(word1);
    cout << word2 << " " << 1;

    return 0;
}