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

## Aravis

[Aravis][aravis] is a vision library for genicam based cameras. How to install:

```bash
sudo apt install meson libglib2.0-dev libxml2-dev libusb-1.0-0-dev

git clone https://github.com/AravisProject/aravis
cd aravis

sudo cp src/aravis.rules /etc/udev/rules.d

meson build --prefix=/path/to/install/prefix -Dviewer=disabled -Dgst-plugin=disabled -Ddocumentation=disabled -Dintrospection=disabled
cd build
ninja
ninja install
```

[ni-linux]: https://www.ni.com/en-us/support/downloads/drivers/download.ni-linux-device-drivers.html
[aravis]: https://github.com/AravisProject/aravis
