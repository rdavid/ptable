# shellcheck shell=sh
# vi:et lbr noet sw=2 ts=2 tw=79 wrap
# SPDX-FileCopyrightText: 2023-2025 David Rabkin
# SPDX-License-Identifier: 0BSD
redo-ifchange ./*.cpp ./*.h

# std::bind2nd is deprecated in C++11 and removed in C++17. Use -std=c++03.
g++ -std=c++03 -Wall -Werror -pedantic -o app main.cpp
if ./app 2>&1 >/dev/null | grep Done; then
	printf success\\n
	exit 0
else
	printf failure\\n
	exit 1
fi
