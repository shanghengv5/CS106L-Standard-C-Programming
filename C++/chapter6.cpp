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

set<string> LoadKeywords() {
    ifstream input("/Users/qt/Documents/C++/C++/C++/keywords.txt");
    set<string> result;
    string keyword;
    while(input >> keyword) {
        result.insert(keyword);
    }

//    for(set<string>::iterator itr = result.begin();itr != result.end(); ++itr)
//        cout << "Keywords: " << *itr << endl;
    return result;
}

void PrintReserved() {
    ifstream input;
    OpenUserFile(input);
    map<string, size_t> report = GenerateKeywordReport(GetFileContents(input));
    
    for(map<string, size_t>::iterator itr = report.begin();
        itr != report.end(); ++itr)
        cout << "Keyword " << itr->first << " occurred " << itr->second << " times." << endl;
        
}

map<string, size_t> GenerateKeywordReport(string fileCotents) {
    set<string> keywords = LoadKeywords();
    PreprocessString(fileCotents);
    
    stringstream tokenizer;
    tokenizer << fileCotents;
    
    string word;
    map<string, size_t> result;
    while(tokenizer >> word) {
        if (keywords.count(word))
            ++result[word];
    }
    
    return result;
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
