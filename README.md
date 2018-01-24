# Game Pencil Editor Updater


This is the updator module used to update the GPE project files.

This can be used to update development and release versions.  The update branch can be chosen via the configuration file.  
If no configuration file is present, then the default is to use release versions of everything.

By default, the updater will not make any modifications to files. It will only respond with a return code and/or display a dialog showing update information. To update files, pass in the update flag, detailed in the [Options](#Options) section.

## Options

| Flag | Description                               | 
|------|-------------------------------------------|
| -v   | Version info                              |
| -s   | Silent, No GUI. Just return a return code |
| -u   | Update files in the project               |
| --nb | No Backups                                |

## Build Requirements

Various libraries are needed for the project to be built correctly.  

These tools/utilities are needed to build this project from source:
 * CMake 2.6+
 * Compiler with C++ 11 support
 * CURL
   * libssl-1_1
   * libcrypto-1_1


These libraries should be included in your include paths:
 * CURL-devel

These tools are needed to further development and testing:
 * Catch2

## Build Instructions

1. conan install .
2. cmake .
3. make
4. GPE_Updater