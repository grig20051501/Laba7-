#include <iostream>
#include <string>
#include <vector>

using namespace std;

string text[100] = { "word word worl woll well null", "word werd"};

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
    
    /*while (word.size() < 4) {
        word += " ";
    }
    */
    return word;
}

vector<string> split(string text[]) {
    vector<string> words;
    for (int i = 0; i < 100; i ++) {
        string str = text[i] + " ";
        while (str.find(' ') != string::npos) {
            string word = str.substr(0, str.find(' '));
            str.erase(0, str.find(' ') + 1);
            words.push_back(word);
        }
    }
    return words;
}

bool isEqual(string word1, string word2, int count) {
    string str1 = word1.substr(0, count), str2 = word2.substr(0, count);
    return str1 == str2;
}

int main()
{
    int numOfOne = 0, numOfTwo = 0, numOfThree = 0, numOfFour = 0;
    
    vector<string> words = split(text);
    string word1 = words[0];

    for (int i = 1; i < words.size(); i++) {
        if (isEqual(word1, words[i], 1)) {
            numOfOne++;
        }
        if (isEqual(word1, words[i], 2)) {
            numOfTwo++;
        }
        if (isEqual(word1, words[i], 3)) {
            numOfThree++;
        }
        if (isEqual(word1, words[i], 4)) {
            numOfFour++;
        }
    }
    for (auto i : words) {
        cout << i << " ";
    }
    cout << endl;

    cout << "one: " << numOfOne << " two: " << numOfTwo << " three: " << numOfThree << " four: " << numOfFour << endl;
 
    return 0;
}