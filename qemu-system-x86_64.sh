#!/usr/bin/env bash

qemu-system-x86_64 -L . -m 64 -fda ./out/disk.img -rtc base=localtime -M pc