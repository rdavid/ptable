# shellcheck shell=sh
# vi:et lbr noet sw=2 ts=2 tw=79 wrap
# SPDX-FileCopyrightText: 2023-2025 David Rabkin
# SPDX-License-Identifier: 0BSD
redo-ifchange ptable
if ./ptable 2>&1 >/dev/null | grep Done; then
	printf success\\n
	exit 0
else
	printf failure\\n
	exit 1
fi
