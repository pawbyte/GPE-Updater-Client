# Game Pencil Editor Updater

This software is the updator module used to update both development and release versions of GPE project files.

The update branch is be chosen via the configuration file. If no configuration file is present, the release versions are used by default.

The updater will not modify any files by default, but will respond with a return code and/or display a dialog showing update information. To update files, pass in the update flag, detailed in the [Options](#Options) section.

## Options

| Flag | Description                               | 
|------|-------------------------------------------|
| -v   | Version info                              |
| -s   | Silent, No GUI. Just return a return code |
| -u   | Update files in the project               |
| --nb | No Backups                                |

## Build Requirements

This software requires extra libraries to be built correctly.

These tools and utilities are needed to build this project from source:
 * CMake 2.6+
 * Compiler with C++ 11 support
 * CURL
   * libssl-1_1
   * libcrypto-1_1

These libraries should be in the include paths:
 * CURL-devel

These tools are needed to further development and testing:
 * Catch2

## Build Instructions

1. conan install .
2. cmake .
3. make
4. GPE_Updater
