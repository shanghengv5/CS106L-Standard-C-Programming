//
//  chapter7.cpp
//  C++
//
//  Created by qt on 2024/3/25.
//

#include "chapter7.hpp"

void PrintAverage() {
    ifstream input("/Users/qt/Documents/C++/C++/C++/data.txt");
    multiset<int> values;
    
    int currValue;
    while(input >> currValue)
        values.insert(currValue);
    
    double total = 0.0;
    for(multiset<int>::iterator itr = values.begin(); itr != values.end(); ++itr)
        total += *itr;
    
    cout << "Average is: " << total / values.size() << endl;
}
