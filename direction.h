#ifndef DIRECTION_H_
#define DIRECTION_H_

#include <map>
#include <string>

enum Direction { W, A, D, S };

constexpr int kDirection = 4;

extern std::map<Direction, char> direction_to_char;
extern std::map<char, Direction> char_to_direction;
extern std::map<Direction, std::string> direction_to_string;

#endif // DIRECTION_H_
