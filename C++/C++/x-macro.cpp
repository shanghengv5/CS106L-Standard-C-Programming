//
//  x-macro.cpp
//  C++
//
//  Created by qt on 2024/3/11.
//

#include "x-macro.hpp"
using namespace std;

Color GetOppositeColor(Color c) {
    switch (c) {
        #define DEFINE_COLOR(color, opposite) case color: return opposite;
        #include "color.h"
        #undef DEFINE_COLOR
        default: return c;
    };
}

string ColorToString(Color c) {
    switch (c) {
     #define DEFINE_COLOR(color, opposite) case color: return #color;
     #include "color.h"
     #undef DEFINE_COLOR
     default: return "<unknown>";
    };
}

