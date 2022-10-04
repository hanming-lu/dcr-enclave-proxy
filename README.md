# Build and run - Linux
## OpenEnclave
### Prerequisites
- Use an OE SDK-supported machine or development environment (like Intel SGX).

### Install OpenEnclave SDK package and dependencies for your environment
- Install the OE SDK package and dependencies for your environment. [getting started page of the Open Enclave SDK](https://github.com/openenclave/openenclave/blob/master/docs/GettingStartedDocs/README.md).

### Source the openenclaverc file

```bash
. /opt/openenclave/share/openenclave/openenclaverc
```

## Install packages
### Install libzmq via git clone and cmake
```bash
cd ~
git clone https://github.com/zeromq/libzmq.git
cd libzmq && mkdir -p build && cd build
cmake ..
sudo make -j4 install
```

### Install cppzmq via git clone and cmake
```bash
cd ~
git clone https://github.com/zeromq/cppzmq.git
cd libzmq && mkdir -p build && cd build
cmake ..
sudo make -j4 install
```

### Install Protobuf
```bash
sudo apt-get install libprotobuf-dev protobuf-compiler
```

## Build DCR Proxy via CMake
This uses the CMake package provided by the Open Enclave SDK.

```bash
cd ~
git clone https://github.com/hanming-lu/dcr_proxy.git
cd dcr_proxy && mkdir -p build && cd build
cmake ..
make
```

### Run in Simulation Mode
```bash
make simulate
```

### Run with SGX
```bash
make run
```