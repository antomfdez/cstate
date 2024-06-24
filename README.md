# cstate
Minimal command to hibernate, sleep or freeze a Linux system.

### Usage:
```bash
Usage: cstate [--help] [--version] [--hibernate] [--sleep] [--freeze]

Optional arguments:
  -h, --help        shows help message and exits
  -v, --version     prints version information and exits
  -hi, --hibernate  Save the state of the system in swap and shutdown.
  -sl, --sleep      Save the state of the system in ram and put the system in sleep mode.
  -fr, --freeze     The freeze option, when set, will initiate a lightweight software-based-only sleep state for your system and the Linux user space will be frozen (hence the term) and all I/O devices will be put into a low power state.
```

### Build and install:
#### Clone project
```bash
git clone https://github.com/antomfdez/cstate.git
cd cstate
```
#### Build with cmake
```bash
sudo cmake --build .
```
#### Install in path
```bash
sudo cmake --install .
```