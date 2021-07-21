# Parallel: Get Device Info (DPC++)

Use Intel's oneAPI DPC++ to query for information from your accelerator devices.

Linux distro "Pop!_OS 21.04"

cmake version 3.18.4

Intel(R) oneAPI DPC++/C++ Compiler 2021.3.0 (2021.3.0.20210619)

## Steps

cd oneapi

./build.sh

./build/get-device-info

## History

dates: July 14 - 15, 2021

duration: 6 hours

### Code from Another Developer

This code came directly from Intel.

[oneAPI Base Training Module](https://devcloud.intel.com/oneapi/get_started/baseTrainingModules/)

I modified the original Intel code to crack open and output the available device info.

### Compilation

I placed this in my .bashrc file so the dpcpp compiler can be found.

> export ONEAPI_DIR="/opt/intel/oneapi"

> [ -s "$ONEAPI_DIR/setvars.sh" ] && \. "$ONEAPI_DIR/setvars.sh"  # initialize oneAPI environment

## Output

[Output](https://github.com/TallDave67/parallel-get-device-info/blob/main/oneapi/output.txt)
