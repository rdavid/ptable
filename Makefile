# SPDX-FileCopyrightText: 2023-2026 David Rabkin
# SPDX-License-Identifier: 0BSD
REDO ?= redo
.DEFAULT_GOAL := all
.PHONY: all clean test

warning:
	@echo WARNING: Proxying commands to redo.

all: warning
	$(REDO) $@

clean: warning
	$(REDO) $@

test: warning
	$(REDO) $@
