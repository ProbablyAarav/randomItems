/*
This code is created and maintained by Aarav Yadav
Created: May 13th, 2025
randomItem.cpp: a program created to select a number of random items from a list specified by a user-defined file
This was created using only the standard libraries of random (for random selection), iostream (for terminal output), vector (to store items) and fstream (for file opening)
Contact:
aarav25803691@gmail.com
(512) 763-0880
https://buymeacoffee.com/arainvinn
*/
#include <random>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main() {
    vector<string> songs;
    string file, idk;
    int r, items, r1, r2, r3, count;
    cout << "What is the filename? ";
    cin >> file;
    cout << endl << "How many items would you like from the file? (Make sure all items are seperated by newlines): ";
    cin >> items;
    ifstream fin(file);
    if (!fin.is_open()) {
        cerr << "Cannot open the file " << file << "!" << endl;
        return 1;
    }
    while (getline(fin, idk)) {
        songs.push_back(idk);
        count++;
    }
    if (songs.size() < items) {
        cerr << "There must be at least " << items << " elements present in the dataset! There are currently " << songs.size() << " items present in the list. Please correct this!" << endl;
        return 1;
    }
    fin.close();
    count = songs.size();
    r = count / 3;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, r - 1);
    r1 = distrib(gen);
    r2 = distrib(gen) + r;
    r3 = distrib(gen) + (2 * r);
    cout << "Song 1: " << songs[r1] << endl << "Song 2: " << songs[r2] << endl << "Song 3: " << songs[r3] << endl;
    return 0;
}