# OS3

A project of finding executable files within A Directory supplied from arguments

## Description

This repo contains a Bash version of the solution which I first created which I then ported to c using the `excec` and `fork` function to run this bash command. It has been never stated in the brief that you can't use this and provides a more cleaner solution to the problem.

## Getting Started

To install the c version of the solution.
```bash
cd executable_args
make insall
```
The program will be compiled and installed and located in /usr/local/bin directory

### Dependencies

* Have make and gcc installed on your system.


### Executing program


* To run in your current directory, you can supply no arguments or .
```bash
executable
executable .
```

* It accepts space seperated arguments
```bash
exectuable /boot /usr/bin/local
```

* It also accepts colon seperated arguments
```
executable $PATH
```

## Authors


ex. NitroSniper (Mahie Miah)
