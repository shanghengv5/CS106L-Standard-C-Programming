//
//  main.cpp
//  C++
//
//  Created by qt on 2024/2/26.
//

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//const int NUM_LENS = 4;
const int NUM_COLUMNS = 3;
const int COLUMN_WIDTH = 20;

void PrintOpenFileErr() {
    cerr << "Can't open file" << endl;
}


void PrintWorldCaptial() {
    ifstream input("/Users/qt/Documents/C++/C++/C++/C++/world-capitals.txt");
    if(!input.is_open()) {
        PrintOpenFileErr();
    }
    string capitalName;
    string countryName;
    while(getline(input, capitalName) && getline(input, countryName)) {
        cout << capitalName << "is the capital of " << countryName << endl;
    }
        
}


void PrintTableHeader() {
    for (int i = 0;i < NUM_COLUMNS - 1;i++) {
        cout  << setfill('-') << setw(COLUMN_WIDTH) << "" << "-+-";
    }
    cout << setw(COLUMN_WIDTH) << "";
    // undo setfill
    cout << setfill(' ') << endl;
}

void  PrintTableBody() {
    ifstream tableFile("/Users/qt/Documents/C++/C++/C++/C++/table-data.txt");
    if (!tableFile.is_open()) {
        cerr << "Can't open file" << endl;
    }
    
    int rowNumber = 0;
    int intValue;
    double doubleValue;

    while(tableFile >> intValue >> doubleValue) {
        cout << setw(COLUMN_WIDTH) << rowNumber+1 << " | ";
        cout << setw(COLUMN_WIDTH) << intValue << " | ";
        cout << setw(COLUMN_WIDTH) << doubleValue << endl;
    }
}

void TestGetLine() {
//    int dummyInt;
    string dummyString;
//    cin >> dummyInt;
    getline(cin, dummyString);
    cout << dummyString << endl;
}

void CinErr() {
    int myInteger;
    cin >> myInteger;
    if(cin.fail()) {
        cout << "integer get fail:" << boolalpha << cin.fail() << endl;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    PrintWorldCaptial();
//    TestGetLine();
//    PrintTableHeader();
//    PrintTableBody();
//    CinErr();
    return 0;
}


