# 2048
Writer: Yifan Ruan ([20302010010](20302010010@fudan.edu.cn))

Latest Build: v1.0, 2021/6/27, Linux .OUT

_Note: **For lab8, please read `lab8-analysis.md`.** For lab7, please read `lab7-howto.txt`. For lab6, please read `readme.txt`._
_Note: **For versions after v0.5-beta, use WAZS.** For earlier versions, this game uses WASD to control, NOT WAZS._

## Test Environment
### Ubuntu 20.04.2.0 (latest: v1.0)
GCC 9.3.0
### Windows10 20H2 (latest: v0.6)
MinGW + GCC 9.3.0
### macOS 11.2.3 (latest: v0.5)
GCC 10.2.0 (Installed from Homebrew)

_Note: You have to install [`bits/stdc++.h`](https://github.com/khaveesh/macOS-bits-stdc-.h) first._

## Compile Command
### Linux
`g++ -O2 *.cc -o main.out`
### Windows (Powershell)
`g++ -O2 board.cc bonus.cc cheat.cc direction.cc game_cli.cc game.cc log.cc main.cc play.cc player.cc test.cc util.cc -o main.exe`
### macOS
`g++-10 -O2 *.cc -o main`

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

`-log` : Open log.

`-p`: Open bonus feature. 
### Mode
`1` : Single mode.
`2` : Dual mode.
#### Cheat
`c [arg]` : Type `c [arg]` in Dual mode. Can only be used once.
#### Retraction
Please follow the prompts in the game.

_Please run in the same directory!_
