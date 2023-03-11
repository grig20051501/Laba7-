﻿#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string text[100] = { "lerd wor worl woll well null", "word werd"};

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

string formForBin(string text[]) {
    string forBin = "";
    vector<string> words = split(text);
    for (auto word : words) {
        forBin += word;
    }
    return forBin;
}

int countSimm(string str, char chr) {
    sort(str.begin(), str.end());
    cout << str << endl;
    int left = 0, right = str.size() - 1, mid = (str.size() - 1) / 2;
    while ((chr != str[mid]) and (right > left )) {
        if (chr > str[mid]) {
            left = mid;
            mid = (right - left) / 2 + left;
        }
        else {
            right = mid;
            mid = (right - left) / 2 + left;
        }
    }
    return mid;
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
    
    vector<string> words = split(text);
    string word1 = "word";
    char chr = 'w';

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
 
    string a = formForBin(text);
    cout << a << endl;
    int b = countSimm(a,chr);
    cout << b;

    

    return 0;
}