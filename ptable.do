# shellcheck shell=sh
# vi:et lbr noet sw=2 ts=2 tw=79 wrap
# SPDX-FileCopyrightText: 2023-2025 David Rabkin
# SPDX-License-Identifier: 0BSD
redo-ifchange ./*.cpp ./*.h
g++ -Wall -Werror -pedantic -o "$3" main.cpp
