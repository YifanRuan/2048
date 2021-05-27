#include "direction.h"
using namespace std;

map<Direction, char> direction_to_char = {
    {W, 'w'}, {A, 'a'}, {S, 'z'}, {D, 's'}};

map<char, Direction> char_to_direction = {
    {'w', W}, {'a', A}, {'z', S}, {'s', D}};

map<Direction, string> direction_to_string = {
    {W, "Up"}, {A, "Left"}, {S, "Down"}, {D, "Right"}};
