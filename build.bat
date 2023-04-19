@echo off

set src_dir=..\src
set inc_dir=..\include

set srcs=%src_dir%\main.c

pushd build
cl /nologo /FC /Wall %srcs%
popd