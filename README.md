# Galileo Controller
Controller for a rotary actuator servomotor implemented for Intel Galileo Gen2.

**Author:** Levindo Gabriel Taschetto Neto.

## Components

*  Pushbutton;
*  Servomotor;
*  Grove-LCD RGB Backlight v4.0;
*  Potentiometer;

## How to use
### Configure the Cross Compiler
```
$ cd scripts/
$ source iss_setup.sh
```

### Compile the controller for Galileo on the host
```
$ cd ../src/
$ make clean
$ make
```

### GPIO Setup
#### On the host
```
$ scp init/config root@<IP_GALILEO>:
```
#### On the Galileo Gen2 ($root)
```
$ groupadd -r configcontroller
$ groupmems -g configcontroller -a <USERNAME>
$ cp ~/configController /etc/init.d
$ chmod +x /etc/init.d/configController
$ update-rc.d configController defaults
$ reboot
```

### Copy the executable to the Intel Galileo Gen2
$ scp controller <USER>@<IP_GALILEO>:
```
