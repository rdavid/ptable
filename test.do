# shellcheck shell=sh
# vi: lbr noet sw=2 ts=2 tw=79 wrap
# SPDX-FileCopyrightText: 2023-2026 David Rabkin
# SPDX-License-Identifier: 0BSD
#
# Builds the debug application and compares its standard error stream with
# the recorded golden output. std::bind2nd is deprecated in C++11 and
# removed in C++17, so the build sticks to `-std=c++03`.
redo-ifchange ./*.cpp ./*.h ./expected.log
g++ -std=c++03 -Wall -Werror -pedantic -o ./app ./main.cpp
./app 2>./app.log >/dev/null
if diff ./expected.log ./app.log >&2; then
	printf >&2 success\\n
else
	printf >&2 failure\\n
	exit 1
fi
