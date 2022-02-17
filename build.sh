#!/bin/bash

# Must be executed from the main repository folder

meson build
ninja -C build
