# shellcheck shell=sh
# vi:et lbr noet sw=2 ts=2 tw=79 wrap
# Copyright 2023 David Rabkin
redo-ifchange ptable
if ./ptable 2>&1 >/dev/null | grep Done; then
	printf success\\n
	exit 0
else
	printf failure\\n
	exit 1
fi
