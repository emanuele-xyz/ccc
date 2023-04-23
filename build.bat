@echo off

set dbg_opts=/Od /Zi /Fdmain /DCCC_DBG_BREAK_ON_CRASH

set src_dir=..\src
set inc_dir=..\include

set srcs=%src_dir%\main.c
set srcs=%srcs% %src_dir%\alloc.c

pushd build
cl /nologo %dbg_opts% /std:c17 /FC /Wall /I %inc_dir% %srcs%
popd
