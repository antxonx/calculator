# Calculator

WxWidgets calculator for linux.

lib/calcmath contains the library on ASM code, compiled as a shared library and added to vscode in the enviroment.
compiled shared objects with:
```
$ nasm -felf64 $(name).s -o $(name).o
```
```
$ gcc -shared $(name).o -o $(name).so
```
then:
```
$ make
```
```
$ make clean
```
to run with make:
```
$ make clean
```
if `error while loading shared libraries: arith.so: cannot open shared object file: No such file or directory`. you can execute this line just before running the program in the same shell instance.
```
$ LD_LIBRARY_PATH=lib/calcmath && export LD_LIBRARY_PATH
```