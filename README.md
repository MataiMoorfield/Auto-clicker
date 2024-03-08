# Auto-clicker
A auto clicker made in C++ for macOS, Windows, or Linux. Demo video [here](https://youtu.be/FrYrm2OMDDk)

<img width="800" alt="Screenshot 2024-03-08 at 18 42 19" src="https://github.com/MataiMoorfield/Auto-clicker/assets/138086469/4bf637f6-0c8b-4ad0-8c10-a11da680e142">


# Installation
## Mac:
Follow these steps for [here](https://www3.cs.stonybrook.edu/~alee/g++/g++_mac.html) or install with Homebrew [here](http://cs.millersville.edu/~gzoppetti/InstallingGccMac.html)

## Windows:
Follow these steps [here](https://code.visualstudio.com/docs/cpp/config-mingw). 

## Linux:
**Ubuntu, Debian, and related distributions:**
Follow these steps [here](https://linuxhint.com/install-and-use-g-on-ubuntu/)

**CentOS, Fedora, and related distributions:**
Follow steps [here](https://www.cyberciti.biz/faq/centos-rhel-7-redhat-linux-install-gcc-compiler-development-tools/)

# How to compile
## Mac
```
cd Auto-clicker/main/mac
g++ -o autoclicker main.cpp -framework ApplicationServices -std=c++11
```
## Windows
```
cd Auto-clicker/main/windows
g++ -o autoclicker.exe main.cpp -std=c++11
```

## Linux
```
cd Auto-clicker/main/linux
g++ -o autoclicker main.cpp -std=c++11
```

# How to run
> The autocliker clickes once, allowing the user to start the program and leave the mouse over the CPS test. The first single click will swap windows. After the single click, the autoclicker will click rapidially for **1 second**

## Mac
```
./autoclicker
```

## Windows
```
autoclicker.exe
```

## Linux
```
./autoclicker
```
