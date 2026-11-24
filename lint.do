# vi: lbr noet sw=2 ts=2 tw=79 wrap
# SPDX-FileCopyrightText: 2023-2026 David Rabkin
# SPDX-License-Identifier: 0BSD
#
# Lints the project with whichever linters are installed, skipping the
# missing ones. Command output streams to the console through the shellbase
# loggers, while the script itself prints only OK to stdout, which redo
# captures as the target. Dash and mksh check syntax one file per
# invocation: a POSIX shell reads only its first operand as the script and
# hands any further operands to it as positional parameters, so files after
# the first would be silently skipped rather than checked.
#
# Sets the shellcheck dialect, since the file has no shebang, and silences
# warnings about unused variables and sourced files:
#  shellcheck shell=sh disable=SC2034,SC1091
redo-ifchange \
	./.github/*.yml \
	./.github/pages/README-docinfo.html \
	./.github/workflows/*.yml \
	./*.do \
	./Makefile \
	./README.adoc
readonly \
	BASE_APP_VERSION=0.9.20261124 \
	BASE_MIN_VERSION=0.9.20260707
. base.sh
cmd_runif actionlint
cmd_runif checkmake ./Makefile
for FLE in ./*.do; do
	cmd_runif dash -n "$FLE"
	cmd_runif mksh -n "$FLE"
done
cmd_runif lychee \
	--no-progress \
	--offline \
	./.github/pages/README-docinfo.html \
	./README.adoc
cmd_runif reuse lint
cmd_runif shellcheck ./*.do
cmd_runif shfmt -d ./*.do
cmd_runif typos
cmd_runif yamllint \
	./.github/*.yml \
	./.github/workflows/*.yml
cmd_runif zizmor --offline ./.github/
printf OK
