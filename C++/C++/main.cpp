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

const int NUM_LENS = 4;
const int NUM_COLUMNS = 3;
const int COLUMN_WIDTH = 20;


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
        cerr << "Can't open table-data" << endl;
    }
    
//    ofstream outputFile("table-data-output.txt");
    for (int i = 0; i < NUM_LENS; ++i) {
        int intValue;
        double doubleValue;
        tableFile >> intValue >> doubleValue;
        cout << setw(COLUMN_WIDTH) << i+1 << " | ";
        cout << setw(COLUMN_WIDTH) << intValue << " | ";
        cout << setw(COLUMN_WIDTH) << doubleValue << endl;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    PrintTableHeader();
    PrintTableBody();
    return 0;
}


