# shellcheck shell=sh
# vi:et lbr noet sw=2 ts=2 tw=79 wrap
# SPDX-FileCopyrightText: 2023-2025 David Rabkin
# SPDX-License-Identifier: 0BSD
redo-ifchange \
	./*.do \
	.github/workflows/*.yml \
	.github/*.yml \
	./Makefile
set -- "$@" --quiet

# shellcheck disable=SC1091 # File not following.
. base.sh
cmd_exists checkmake && checkmake Makefile
cmd_exists shellcheck && shellcheck ./*.do
cmd_exists shfmt && shfmt -d ./*.do
cmd_exists typos && typos

# Gracefully handle missing tools without failing the script.
# shellcheck disable=SC2015 # A && B || C is not if-then-else.
cmd_exists yamllint && yamllint .github/*.yml .github/workflows/*.yml || :
