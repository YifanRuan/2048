#include "direction.h"

std::map<Direction, char> direction_to_char = {
    {W, 'w'}, {A, 'a'}, {S, 'z'}, {D, 's'}};
std::map<char, Direction> char_to_direction = {
    {'w', W}, {'a', A}, {'z', S}, {'s', D}};
