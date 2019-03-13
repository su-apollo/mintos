#!/usr/bin/env bash

qemu-system-x86_64 -L . -m 64 -fda ./disk.img -rtc base=localtime -M pc