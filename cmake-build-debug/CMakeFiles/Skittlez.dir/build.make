# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sean.eigle143/Desktop/SkittlezLab/Skittlez

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sean.eigle143/Desktop/SkittlezLab/Skittlez/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Skittlez.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Skittlez.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Skittlez.dir/flags.make

CMakeFiles/Skittlez.dir/main.c.o: CMakeFiles/Skittlez.dir/flags.make
CMakeFiles/Skittlez.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sean.eigle143/Desktop/SkittlezLab/Skittlez/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Skittlez.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Skittlez.dir/main.c.o   -c /Users/sean.eigle143/Desktop/SkittlezLab/Skittlez/main.c

CMakeFiles/Skittlez.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Skittlez.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sean.eigle143/Desktop/SkittlezLab/Skittlez/main.c > CMakeFiles/Skittlez.dir/main.c.i

CMakeFiles/Skittlez.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Skittlez.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sean.eigle143/Desktop/SkittlezLab/Skittlez/main.c -o CMakeFiles/Skittlez.dir/main.c.s

CMakeFiles/Skittlez.dir/Skittlesbag.c.o: CMakeFiles/Skittlez.dir/flags.make
CMakeFiles/Skittlez.dir/Skittlesbag.c.o: ../Skittlesbag.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sean.eigle143/Desktop/SkittlezLab/Skittlez/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Skittlez.dir/Skittlesbag.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Skittlez.dir/Skittlesbag.c.o   -c /Users/sean.eigle143/Desktop/SkittlezLab/Skittlez/Skittlesbag.c

CMakeFiles/Skittlez.dir/Skittlesbag.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Skittlez.dir/Skittlesbag.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sean.eigle143/Desktop/SkittlezLab/Skittlez/Skittlesbag.c > CMakeFiles/Skittlez.dir/Skittlesbag.c.i

CMakeFiles/Skittlez.dir/Skittlesbag.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Skittlez.dir/Skittlesbag.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sean.eigle143/Desktop/SkittlezLab/Skittlez/Skittlesbag.c -o CMakeFiles/Skittlez.dir/Skittlesbag.c.s

# Object files for target Skittlez
Skittlez_OBJECTS = \
"CMakeFiles/Skittlez.dir/main.c.o" \
"CMakeFiles/Skittlez.dir/Skittlesbag.c.o"

# External object files for target Skittlez
Skittlez_EXTERNAL_OBJECTS =

Skittlez: CMakeFiles/Skittlez.dir/main.c.o
Skittlez: CMakeFiles/Skittlez.dir/Skittlesbag.c.o
Skittlez: CMakeFiles/Skittlez.dir/build.make
Skittlez: CMakeFiles/Skittlez.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sean.eigle143/Desktop/SkittlezLab/Skittlez/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Skittlez"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Skittlez.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Skittlez.dir/build: Skittlez

.PHONY : CMakeFiles/Skittlez.dir/build

CMakeFiles/Skittlez.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Skittlez.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Skittlez.dir/clean

CMakeFiles/Skittlez.dir/depend:
	cd /Users/sean.eigle143/Desktop/SkittlezLab/Skittlez/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sean.eigle143/Desktop/SkittlezLab/Skittlez /Users/sean.eigle143/Desktop/SkittlezLab/Skittlez /Users/sean.eigle143/Desktop/SkittlezLab/Skittlez/cmake-build-debug /Users/sean.eigle143/Desktop/SkittlezLab/Skittlez/cmake-build-debug /Users/sean.eigle143/Desktop/SkittlezLab/Skittlez/cmake-build-debug/CMakeFiles/Skittlez.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Skittlez.dir/depend
