//
//  main.cpp
//  C++
//
//  Created by qt on 2024/2/26.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
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

void UseSStream() {
//    stringstream message;
//    message << "Hello the number is " << 99 << endl;
//    cout << message.str() << endl;
    
    stringstream myConverter;
     int myInt;
     string myString;
     double myDouble;
     myConverter << "137 Hello 2.71828"; // Insert string data
     myConverter >> myInt >> myString >> myDouble; // Extract mixed data
    cout << myInt << myString << myDouble << endl;
}

string GetLine() {
     string result;
     getline(cin, result);
     return result;
}


int GetInteger() {
    int integer;
    while(true) {
        stringstream converter;
        converter << GetLine();
        
        if(converter >> integer) {
            char remaining;
            if (converter >> remaining) {
                cout << "Unexpected character:" << remaining << endl;
            }
            return integer;
        } else {
            cout << "Please enter an integer"  << endl;
        }
        cout << "Retry :" << endl;
    }
}

bool GetReal() {
    int    integer;
    stringstream converter;
    converter << GetLine();
    
    if(converter >> integer) {
        char remaining;
        if (converter >> remaining) {
            return false;
        }
        return true;
    }
    return false;
}

bool GetBoolean() {
    string str;
    stringstream converter;
    converter << GetLine();
    
    if(converter >> str && str == "true") {
        return true;
    }
    return false;
}


void TestOfstream() {
    ofstream output("/Users/qt/Documents/C++/C++/C++/C++/write.txt");
    if(!output.is_open()) {
        PrintOpenFileErr();
    }
    output << "Text to write";
    output.close();
    cout << "write done " << endl;
}

string ConvertIntToStringByStringstream(int integer) {
    stringstream converter;
    string result;
    converter << integer;
    converter >> result;
    return result;
}

bool HasHexLetters(int num) {
    stringstream ss;
    ss << hex << num;
    string hexString = ss.str();

    for (char c : hexString) {
        if (isalpha(c)) {
            return true;
        }
    }

    return false;
}

void DrawTriangle(int height) {
    if (height < 1) {
        cerr << "The triangle must higher than 1" << endl;
        return;
    }
    int large = height * 2+1;

    for (int i = 0;i < height; i++) {
        cout << setfill(' ') << setw(large-i) << "";
        cout << setfill('#') << setw(i*2+1) << "" << endl;
    }
}

void OpenFileByPrompt() {
    ifstream input;
    while (true) {
        stringstream ss;
        ss << GetLine();
        string fileName;
        ss >> fileName;
        input.open(fileName);
        if(!input.is_open()) {
            PrintOpenFileErr();
            cerr << "filename is " << fileName << endl;
            input.clear();
            continue;
        }
        
        cout << "open file success " << fileName << endl;
        break;
    }
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
//    PrintWorldCaptial();
//    TestGetLine();
//    PrintTableHeader();
//    PrintTableBody();
//    CinErr();
//    UseSStream();
//    GetInteger();
//    TestOfstream();
//    cout << "This is a string now:" <<ConvertIntToStringByStringstream(1111) << endl;
//    cout << boolalpha << GetReal() << endl;
//    cout << boolalpha << GetBoolean() << endl;
//    int num2 = 0xABC;
//    cout << "Number 0x3D45E has hex letters: ";
//    cout << boolalpha << HasHexLetters(num2) << endl;
//    DrawTriangle(3);
    OpenFileByPrompt();
    return 0;
}


