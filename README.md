# Dependency installation

Some of the library features will not be compiled if the necessary dependencies
are not met. Please follow the instructions below to install them.

## National Instruments
Download and install the Linux Device Drivers from [here][ni-linux]. Then, on
openSUSE:
```bash
sudo rpm -i ni-software-2019-19.2.0.49152-0+f0.lp150.noarch.rpm
sudo zypper install libnidaqmx-devel
```
QtLab uses automatically generated wrappers for NIDAQmx. This repository comes
with wrappers pre-generated for version 2019 of the NI software. If you're using
a different version, please regenerate wrappers before compiling:
```bash
make NIDAQmx_wrappers
```

[ni-linux]: https://www.ni.com/en-us/support/downloads/drivers/download.ni-linux-device-drivers.html

## How to configure Qt Creator to use MSVC

In the corresponding kit, CMake generator configuration should be:
* Generator: Visual Studio 16 2019
* Extra generator: <none>
* Platform: empty
* Toolset: empty

CMake configuration: `CMAKE_PREFIX_PATH:STRING=%{Qt:QT_INSTALL_PREFIX}`

In Projects > Build Steps, select `ALL_BUILD` instead of `all`.
