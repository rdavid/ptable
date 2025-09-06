# shellcheck shell=sh
# vi:et lbr noet sw=2 ts=2 tw=79 wrap
# SPDX-FileCopyrightText: 2023-2025 David Rabkin
# SPDX-License-Identifier: 0BSD
redo-ifchange \
	./.github/workflows/*.yml \
	./.github/*.yml \
	./*.do \
	./Makefile

# shellcheck disable=SC2034 # Variable appears unused.
readonly \
	BASE_APP_VERSION=0.9.20250906 \
	BSH=/usr/local/bin/base.sh
[ -r "$BSH" ] || {
	printf >&2 Install\ Shellbase.\\n
	exit 1
}
set -- "$@" --quiet

# shellcheck disable=SC1090 # File not following.
. "$BSH"
cmd_exists actionlint && actionlint
cmd_exists checkmake && checkmake ./Makefile
cmd_exists shellcheck && shellcheck ./*.do
cmd_exists shfmt && shfmt -d ./*.do
cmd_exists typos && typos
cmd_exists yamllint &&
	yamllint \
		./.github/*.yml \
		./.github/workflows/*.yml

# Gracefully handle missing last tool without failing the script.
:
