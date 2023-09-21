# shellcheck shell=sh
# vi:et lbr noet sw=2 ts=2 tw=79 wrap
# Copyright 2023 David Rabkin
redo-ifchange \
	./*.do \
	.github/workflows/*.yml \
	.github/*.yml \
	./Makefile

# shellcheck disable=SC1091 # File not following.
. base.sh
cmd_exists checkmake && checkmake Makefile
cmd_exists shellcheck && shellcheck ./*.do
cmd_exists shfmt && shfmt -d ./*.do
cmd_exists typos && typos
cmd_exists yamllint && yamllint .github/*.yml .github/workflows/*.yml
