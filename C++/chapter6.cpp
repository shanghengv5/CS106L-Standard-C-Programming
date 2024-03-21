//
//  chapter6.cpp
//  C++
//
//  Created by qt on 2024/3/21.
//

#include "chapter6.hpp"

int SixSidedDie() {
    return (rand() % 5) + 1;
}

long RepeatNum() {
    set<int> rolls;
    while(true) {
        int nextRoll = SixSidedDie();
        if(rolls.count(nextRoll)) return rolls.size()+1;
        rolls.insert(nextRoll);
    }
}

void PrintSteps() {
    srand(static_cast<unsigned>(time(NULL)));
    size_t total = 0;
    for(size_t k = 0; k < 10000; ++k) {
        total += RepeatNum();
    }
    
    cout << "Average number of steps:" << double(total) / 10000 << endl;
}
