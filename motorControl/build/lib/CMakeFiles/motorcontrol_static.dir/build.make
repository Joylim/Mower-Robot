# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/lab511/Mower-Robot/motorControl2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/lab511/Mower-Robot/motorControl2/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/motorcontrol_static.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/motorcontrol_static.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/motorcontrol_static.dir/flags.make

lib/CMakeFiles/motorcontrol_static.dir/motorcontrol.o: lib/CMakeFiles/motorcontrol_static.dir/flags.make
lib/CMakeFiles/motorcontrol_static.dir/motorcontrol.o: ../lib/motorcontrol.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/lab511/Mower-Robot/motorControl2/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object lib/CMakeFiles/motorcontrol_static.dir/motorcontrol.o"
	cd /home/pi/lab511/Mower-Robot/motorControl2/build/lib && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/motorcontrol_static.dir/motorcontrol.o -c /home/pi/lab511/Mower-Robot/motorControl2/lib/motorcontrol.cpp

lib/CMakeFiles/motorcontrol_static.dir/motorcontrol.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motorcontrol_static.dir/motorcontrol.i"
	cd /home/pi/lab511/Mower-Robot/motorControl2/build/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/lab511/Mower-Robot/motorControl2/lib/motorcontrol.cpp > CMakeFiles/motorcontrol_static.dir/motorcontrol.i

lib/CMakeFiles/motorcontrol_static.dir/motorcontrol.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motorcontrol_static.dir/motorcontrol.s"
	cd /home/pi/lab511/Mower-Robot/motorControl2/build/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/lab511/Mower-Robot/motorControl2/lib/motorcontrol.cpp -o CMakeFiles/motorcontrol_static.dir/motorcontrol.s

lib/CMakeFiles/motorcontrol_static.dir/motorcontrol.o.requires:
.PHONY : lib/CMakeFiles/motorcontrol_static.dir/motorcontrol.o.requires

lib/CMakeFiles/motorcontrol_static.dir/motorcontrol.o.provides: lib/CMakeFiles/motorcontrol_static.dir/motorcontrol.o.requires
	$(MAKE) -f lib/CMakeFiles/motorcontrol_static.dir/build.make lib/CMakeFiles/motorcontrol_static.dir/motorcontrol.o.provides.build
.PHONY : lib/CMakeFiles/motorcontrol_static.dir/motorcontrol.o.provides

lib/CMakeFiles/motorcontrol_static.dir/motorcontrol.o.provides.build: lib/CMakeFiles/motorcontrol_static.dir/motorcontrol.o

# Object files for target motorcontrol_static
motorcontrol_static_OBJECTS = \
"CMakeFiles/motorcontrol_static.dir/motorcontrol.o"

# External object files for target motorcontrol_static
motorcontrol_static_EXTERNAL_OBJECTS =

lib/libmotorcontrol.a: lib/CMakeFiles/motorcontrol_static.dir/motorcontrol.o
lib/libmotorcontrol.a: lib/CMakeFiles/motorcontrol_static.dir/build.make
lib/libmotorcontrol.a: lib/CMakeFiles/motorcontrol_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libmotorcontrol.a"
	cd /home/pi/lab511/Mower-Robot/motorControl2/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/motorcontrol_static.dir/cmake_clean_target.cmake
	cd /home/pi/lab511/Mower-Robot/motorControl2/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/motorcontrol_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/motorcontrol_static.dir/build: lib/libmotorcontrol.a
.PHONY : lib/CMakeFiles/motorcontrol_static.dir/build

lib/CMakeFiles/motorcontrol_static.dir/requires: lib/CMakeFiles/motorcontrol_static.dir/motorcontrol.o.requires
.PHONY : lib/CMakeFiles/motorcontrol_static.dir/requires

lib/CMakeFiles/motorcontrol_static.dir/clean:
	cd /home/pi/lab511/Mower-Robot/motorControl2/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/motorcontrol_static.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/motorcontrol_static.dir/clean

lib/CMakeFiles/motorcontrol_static.dir/depend:
	cd /home/pi/lab511/Mower-Robot/motorControl2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/lab511/Mower-Robot/motorControl2 /home/pi/lab511/Mower-Robot/motorControl2/lib /home/pi/lab511/Mower-Robot/motorControl2/build /home/pi/lab511/Mower-Robot/motorControl2/build/lib /home/pi/lab511/Mower-Robot/motorControl2/build/lib/CMakeFiles/motorcontrol_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/motorcontrol_static.dir/depend

