//
//  chapter6.hpp
//  C++
//
//  Created by qt on 2024/3/21.
//

#ifndef chapter6_hpp
#define chapter6_hpp
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include "helper.hpp"

using namespace std;
int SixSidedDie();
long RepeatNum();
void PrintSteps();
set<string> LoadKeywords();
void PreprocessString(string& text);
void PrintReserved();
map<string, size_t> GenerateKeywordReport(string fileCotents);
#endif /* chapter6_hpp */
