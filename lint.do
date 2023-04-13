# shellcheck shell=sh
# vi:et lbr noet sw=2 ts=2 tw=79 wrap
# Copyright 2023 David Rabkin
redo-ifchange ./*.md .github/*.yml .github/workflows/*.yml Makefile

# shellcheck disable=SC1091 # File not following.
. base.sh
validate_cmd \
	checkmake \
	markdownlint \
	shellcheck \
	shfmt \
	yamllint
checkmake Makefile
markdownlint ./*.md
shellcheck ./*.do
shfmt -d ./*.do
yamllint .github/*.yml .github/workflows/*.yml
