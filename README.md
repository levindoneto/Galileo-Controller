# Galileo Controller
Controller for a rotary actuator servomotor implemented for Intel Galileo Gen2.

**Author:** Levindo Gabriel Taschetto Neto.

## Components (all from the grove-starter kit)

*  Pushbutton.
*  Servomotor.
*  Grove-LCD RGB Backlight v4.0.
*  Potentiometer.
*  LED socket v1.5.
*  Buzzer v1.2.

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
Access [init/](init/).

### Copy the executable to the Intel Galileo Gen2
$ scp controller <USER>@<IP_GALILEO>:
```
