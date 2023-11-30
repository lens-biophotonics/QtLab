# QtLab

QtLab is a set of shared libraries to make it easier to work with some lab
hardware in Qt and C++. It currently supports the following hardware:

* Hamamatsu cameras
* National Instruments boards
* Physik Instrumente systems
* Cobolt lasers
* Thorlabs filter wheel and motor controller
* Some other serial devices.

## Dependency installation

Some of the library features will not be compiled if the necessary dependencies
are not met. Please follow the instructions below to install them.

On Ubuntu 22.04:
```bash
sudo apt install build-essential cmake coccinelle qtbase5-dev qt5-qmake libqt5serialport5-dev libqwt-qt5-dev libtiff-dev
```

## National Instruments
Download and install the Linux Device Drivers from [here][ni-linux].

QtLab uses automatically generated wrappers for NIDAQmx. These wrappers are
generated using coccinelle, also known as `spatch`, which needs to be installed
on your system. Alternatively, a docker container will be used to generate the
wrappers. The process might take a few minutes.

[ni-linux]: https://www.ni.com/en-us/support/downloads/drivers/download.ni-linux-device-drivers.html

## How to configure Qt Creator to use MSVC

In the corresponding kit, CMake generator configuration should be:

* Generator: Visual Studio 16 2019
* Extra generator: <none>
* Platform: empty
* Toolset: empty

CMake configuration: `CMAKE_PREFIX_PATH:STRING=%{Qt:QT_INSTALL_PREFIX}`

In Projects > Build Steps, select `ALL_BUILD` instead of `all`.
