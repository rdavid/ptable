# vi: lbr noet sw=2 ts=2 tw=79 wrap
# SPDX-FileCopyrightText: 2023-2026 David Rabkin
# SPDX-License-Identifier: 0BSD
#
# Sets the shell dialect for shellcheck, since the file has no shebang:
#  shellcheck shell=sh
redo-ifchange ./lint ./test
