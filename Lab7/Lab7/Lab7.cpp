#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

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

vector<string> split(string text) {
    vector<string> words;
        string str = text + ' ';
        while (str.find(' ') != string::npos) {
            string word = str.substr(0, str.find(' '));
            str.erase(0, str.find(' ') + 1);
            words.push_back(word);
        }
    return words;
}

string formForBin(string text) {
    string str = "";
    vector<string> words = split(text);
    for (auto word : words) {
        str += word;
    }
    sort(str.begin(), str.end());
    return str;
}

int binarSearch(string str, char chr) {

    int left = 0, right = str.size() - 1, mid = (str.size() - 1) / 2;
    int count = 0;
    while (left <= right) {
        if (chr == str[mid]) {
            return mid;
        }
        if (chr > str[mid]) {
            left = mid + 1;
            mid = (right - left) / 2 + left;
        }
        else {
            right = mid - 1;
            mid = (right - left) / 2 + left;
        }
    }
    if (chr == str[mid]) { return mid; }
    else {
        return -1;
    }
}

int countSimm(string str, char chr) {
    int count = 0;
    int pos = binarSearch(str, chr);
    while (pos != -1) {
        count++;
        str.erase(pos, 1);
        pos = binarSearch(str, chr);
    }
    return count;
}

bool isEqual(string word1, string word2, int count) {
    string str1 = word1.substr(0, count), str2 = word2.substr(0, count);

    while (str1.size() < count) {
        str1 += " ";
    }
    while (str2.size() < count) {
        str2 += " ";
    }

    return str1 == str2;
}

int main()
{
    int numOfOne = 0, numOfTwo = 0, numOfThree = 0, numOfFour = 0;

    string text;
    cout << "Enter the text" << endl;
        getline(cin,text);

    vector<string> words = split(text);

    string word1;
    cout << "Enter the word " << endl;
    cin >> word1;
    char chr = word1[0];

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

    cout << "one: " << numOfOne << " two: " << numOfTwo << " three: " << numOfThree << " four: " << numOfFour << endl;
 
    string a = formForBin(text);
    int b = countSimm(a,chr);
    cout << "Number of matches of the symbol " << chr << " is : " << b;

    

    return 0;
}