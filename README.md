# 2048
Writer: Yifan Ruan ([20302010010](20302010010@fudan.edu.cn))

Latest Build: ver. 0.3, 2021/3/30, Windows EXE

_Note: this game uses WASD to control, NOT WAZS._

## Test Environment
### Windows10 20H2
MinGW + GCC 9.3.0
### macOS 11.2.3
GCC 10.2.0 (Installed from Homebrew)

_Note: You have to install `bits/stdc++.h` first._

Tutorial: [https://github.com/khaveesh/macOS-bits-stdc-.h](#)
### Ubuntu 20.04.2.0
GCC 9.3.0

## Compile Command
### Windows (Powershell)
`g++ -O2 main.cc status.cc game.cc status.h game.h -o main.exe`
### macOS
`g++-10 -O2 main.cc status.cc game.cc status.h game.h -o main`

_Note: Don't use clang on that command._

To use `g++` instead of `g++-10`, check your GCC version using `g++ --version`.
### Linux
`g++ -O2 main.cc status.cc game.cc status.h game.h -o main`

## Usage
`./main [Option]`
### Option
`-t` : Set the ending number to 64. Default is 2048.

_Please run in the same directory!_
