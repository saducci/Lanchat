# LHmsg

Simple LAN messenger built with Qt and C++.

## Features

- LAN messaging
- Qt Widgets UI
- TCP sockets using `QTcpSocket` / `QTcpServer`
- Cross-platform

## Requirements

- Qt 6
- CMake
- C++17 compiler

## Clone Repository

```bash
git clone https://github.com/saducci/Lanchat/
cd LHmsg
```

## Linux Build

Install dependencies:

```bash
sudo apt install qt6-base-dev qt6-tools-dev cmake g++
```

Build:

```bash
cmake -B build
cmake --build build
```

Run:

```bash
./build/LHmsg
```

## macOS Build

Install dependencies:

```bash
brew install cmake qt
```

Also install:
- Xcode Command Line Tools
- Qt 6

Build:

```bash
cmake -B build
cmake --build build
```

Run:

```bash
./build/LHmsg.app
```

Create macOS app bundle:

```bash
macdeployqt build/LHmsg.app
```

## Windows Build

Install:
- Qt 6
- CMake
- Visual Studio or MinGW

Build:

```bash
cmake -B build
cmake --build build --config Release
```

Run:

```bash
build\Release\LHmsg.exe
```

## LAN Usage

Run the server first.

Connect clients using:

```cpp
socket->connectToHost("SERVER_IP", 1234);
```

Example:

```cpp
socket->connectToHost("192.168.1.5", 1234);
```

## Notes

- Both devices must be on the same network
- Port `1234` may need to be opened in firewall
- Built for learning Qt networking

## License

MIT
