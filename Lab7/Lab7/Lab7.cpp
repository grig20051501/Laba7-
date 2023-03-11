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

vector<string> split(string str[]) {
    vector<string> words;
  
    for (int i = 0; i < 100; i++) {
        text[i] += " ";
        for (int j = 0; j < text[i].size(); j++) {
            if (text[i][j] == ' ') {
                string word = purify(text[i].substr(0, j));
                words.push_back(word);
                text[i].erase(0, j);
            }
        }
    }
    return words;
}

int main()
{


    return 0;
}