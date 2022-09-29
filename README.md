## Build and run - Linux
### Prerequisites
- Use an OE SDK-supported machine or development environment (like Intel SGX).

### Install OpenEnclave SDK package and dependencies for your environment
- Install the OE SDK package and dependencies for your environment. [getting started page of the Open Enclave SDK](https://github.com/openenclave/openenclave/blob/master/docs/GettingStartedDocs/README.md).

### Source the openenclaverc file

```bash
. /opt/openenclave/share/openenclave/openenclaverc
```
#### CMake
This uses the CMake package provided by the Open Enclave SDK.

```bash
cd dcr_enclave_proxy
mkdir build && cd build
cmake ..
make
```

#### Intel SGX Simulation
```bash
make simulate
```

#### Intel SGX Hardware
```bash
make run
```