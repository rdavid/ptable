# SPDX-FileCopyrightText: 2023-2025 David Rabkin
# SPDX-License-Identifier: 0BSD
REDO ?= redo
.DEFAULT_GOAL := all
.PHONY: all clean test

warning:
	@echo WARNING: Just proxying commands to redo command.

all: warning
	$(REDO) $@

clean: warning
	$(REDO) $@

test: warning
	$(REDO) $@
