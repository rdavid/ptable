# shellcheck shell=sh
# vi:et lbr noet sw=2 ts=2 tw=79 wrap
# Copyright 2023 David Rabkin
redo-ifchange .github/workflows/*.yml .github/*.yml ./Makefile

# shellcheck disable=SC1091 # File not following.
. base.sh
validate_cmd \
	checkmake \
	shellcheck \
	shfmt \
	typos \
	yamllint
checkmake Makefile
shellcheck ./*.do
shfmt -d ./*.do
typos
yamllint .github/*.yml .github/workflows/*.yml
