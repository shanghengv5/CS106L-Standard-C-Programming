//
//  x-macro.hpp
//  C++
//
//  Created by qt on 2024/3/11.
//

#ifndef x_macro_hpp
#define x_macro_hpp
#include <string>

using namespace std;
enum Color {
     #define DEFINE_COLOR(color, opposite) color,
     #include "color.h"
     #undef DEFINE_COLOR
 };

Color GetOppositeColor(Color c);
string ColorToString(Color c);

#endif /* x_macro_hpp */
