# 2048
Writer: Yifan Ruan ([20302010010](20302010010@fudan.edu.cn))

Latest Build: v0.4, 2021/4/19, Linux .OUT

_Note: this game uses WASD to control, NOT WAZS._

## Test Environment
### Ubuntu 20.04.2.0
GCC 9.3.0
### Windows10 20H2 (v0.4 not tested)
MinGW + GCC 9.3.0
### macOS 11.2.3 (v0.4 not tested)
GCC 10.2.0 (Installed from Homebrew)

_Note: You have to install [`bits/stdc++.h`](https://github.com/khaveesh/macOS-bits-stdc-.h) first._

## Compile Command
### Linux
`g++ -O2 main.cc status.cc game.cc status.h game.h -o main.out`
### Windows (Powershell)
`g++ -O2 main.cc status.cc game.cc status.h game.h -o main.exe`
### macOS
`g++-10 -O2 main.cc status.cc game.cc status.h game.h -o main`

_Note: Don't use clang on that command._

To use `g++` instead of `g++-10`, check your G++ version using `g++ --version`.

## Usage
### Run command
#### Linux
`./main.out [Option]`
#### Windows & macOS
`./main [Option]`
### Option
`-t` : Set the ending number to 64. Default is 2048.

`-s [size]` : Set the size of the map. Range from 2 to 5. Default is 4.
### Mode
`1` : Single mode.
`2` : Dual mode.
#### Cheat
`c [arg]` : Type `c [arg]` in Dual mode. Can only be used once.

_Please run in the same directory!_
