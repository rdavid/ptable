# shellcheck shell=sh
# vi:et lbr noet sw=2 ts=2 tw=79 wrap
# SPDX-FileCopyrightText: 2023-2025 David Rabkin
# SPDX-License-Identifier: 0BSD
# std::bind2nd is deprecated in C++11 and removed in C++17. Use -std=c++03.
redo-ifchange ./*.cpp ./*.h
g++ -std=c++03 -Wall -Werror -pedantic -o "$3" main.cpp
