# Calculator

WxWidgets calculator for linux.

lib/calcmath contains the library on ASM code, compiled as a shared library and added to vscode in the enviroment

compile shared objects with
```
$ nasm -felf64 $(name).s -o $(name).o
$ gcc -shared $(name).o -o $(name).so
```