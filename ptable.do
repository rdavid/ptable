# shellcheck shell=sh
# vi:et lbr noet sw=2 ts=2 tw=79 wrap
# Copyright 2023 David Rabkin
redo-ifchange ./*.h ./*.cpp
g++ -Wall -Werror -pedantic -o "$3" main.cpp
