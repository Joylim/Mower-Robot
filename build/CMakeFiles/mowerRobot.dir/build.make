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
CMAKE_SOURCE_DIR = /home/pi/lab511/Mower-Robot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/lab511/Mower-Robot/build

# Include any dependencies generated for this target.
include CMakeFiles/mowerRobot.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mowerRobot.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mowerRobot.dir/flags.make

CMakeFiles/mowerRobot.dir/src/board_detect.o: CMakeFiles/mowerRobot.dir/flags.make
CMakeFiles/mowerRobot.dir/src/board_detect.o: ../src/board_detect.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/lab511/Mower-Robot/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/mowerRobot.dir/src/board_detect.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/mowerRobot.dir/src/board_detect.o -c /home/pi/lab511/Mower-Robot/src/board_detect.cpp

CMakeFiles/mowerRobot.dir/src/board_detect.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mowerRobot.dir/src/board_detect.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/lab511/Mower-Robot/src/board_detect.cpp > CMakeFiles/mowerRobot.dir/src/board_detect.i

CMakeFiles/mowerRobot.dir/src/board_detect.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mowerRobot.dir/src/board_detect.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/lab511/Mower-Robot/src/board_detect.cpp -o CMakeFiles/mowerRobot.dir/src/board_detect.s

CMakeFiles/mowerRobot.dir/src/board_detect.o.requires:
.PHONY : CMakeFiles/mowerRobot.dir/src/board_detect.o.requires

CMakeFiles/mowerRobot.dir/src/board_detect.o.provides: CMakeFiles/mowerRobot.dir/src/board_detect.o.requires
	$(MAKE) -f CMakeFiles/mowerRobot.dir/build.make CMakeFiles/mowerRobot.dir/src/board_detect.o.provides.build
.PHONY : CMakeFiles/mowerRobot.dir/src/board_detect.o.provides

CMakeFiles/mowerRobot.dir/src/board_detect.o.provides.build: CMakeFiles/mowerRobot.dir/src/board_detect.o

CMakeFiles/mowerRobot.dir/src/EdgeDetect.o: CMakeFiles/mowerRobot.dir/flags.make
CMakeFiles/mowerRobot.dir/src/EdgeDetect.o: ../src/EdgeDetect.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/lab511/Mower-Robot/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/mowerRobot.dir/src/EdgeDetect.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/mowerRobot.dir/src/EdgeDetect.o -c /home/pi/lab511/Mower-Robot/src/EdgeDetect.cpp

CMakeFiles/mowerRobot.dir/src/EdgeDetect.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mowerRobot.dir/src/EdgeDetect.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/lab511/Mower-Robot/src/EdgeDetect.cpp > CMakeFiles/mowerRobot.dir/src/EdgeDetect.i

CMakeFiles/mowerRobot.dir/src/EdgeDetect.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mowerRobot.dir/src/EdgeDetect.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/lab511/Mower-Robot/src/EdgeDetect.cpp -o CMakeFiles/mowerRobot.dir/src/EdgeDetect.s

CMakeFiles/mowerRobot.dir/src/EdgeDetect.o.requires:
.PHONY : CMakeFiles/mowerRobot.dir/src/EdgeDetect.o.requires

CMakeFiles/mowerRobot.dir/src/EdgeDetect.o.provides: CMakeFiles/mowerRobot.dir/src/EdgeDetect.o.requires
	$(MAKE) -f CMakeFiles/mowerRobot.dir/build.make CMakeFiles/mowerRobot.dir/src/EdgeDetect.o.provides.build
.PHONY : CMakeFiles/mowerRobot.dir/src/EdgeDetect.o.provides

CMakeFiles/mowerRobot.dir/src/EdgeDetect.o.provides.build: CMakeFiles/mowerRobot.dir/src/EdgeDetect.o

# Object files for target mowerRobot
mowerRobot_OBJECTS = \
"CMakeFiles/mowerRobot.dir/src/board_detect.o" \
"CMakeFiles/mowerRobot.dir/src/EdgeDetect.o"

# External object files for target mowerRobot
mowerRobot_EXTERNAL_OBJECTS =

../bin/mowerRobot: CMakeFiles/mowerRobot.dir/src/board_detect.o
../bin/mowerRobot: CMakeFiles/mowerRobot.dir/src/EdgeDetect.o
../bin/mowerRobot: CMakeFiles/mowerRobot.dir/build.make
../bin/mowerRobot: /usr/local/lib/libopencv_videostab.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_video.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_ts.a
../bin/mowerRobot: /usr/local/lib/libopencv_superres.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_stitching.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_photo.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_ocl.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_objdetect.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_nonfree.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_ml.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_legacy.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_imgproc.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_highgui.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_gpu.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_flann.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_features2d.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_core.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_contrib.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_calib3d.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_nonfree.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_ocl.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_gpu.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_photo.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_objdetect.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_legacy.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_video.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_ml.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_calib3d.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_features2d.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_highgui.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_imgproc.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_flann.so.2.4.9
../bin/mowerRobot: /usr/local/lib/libopencv_core.so.2.4.9
../bin/mowerRobot: CMakeFiles/mowerRobot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/mowerRobot"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mowerRobot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mowerRobot.dir/build: ../bin/mowerRobot
.PHONY : CMakeFiles/mowerRobot.dir/build

CMakeFiles/mowerRobot.dir/requires: CMakeFiles/mowerRobot.dir/src/board_detect.o.requires
CMakeFiles/mowerRobot.dir/requires: CMakeFiles/mowerRobot.dir/src/EdgeDetect.o.requires
.PHONY : CMakeFiles/mowerRobot.dir/requires

CMakeFiles/mowerRobot.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mowerRobot.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mowerRobot.dir/clean

CMakeFiles/mowerRobot.dir/depend:
	cd /home/pi/lab511/Mower-Robot/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/lab511/Mower-Robot /home/pi/lab511/Mower-Robot /home/pi/lab511/Mower-Robot/build /home/pi/lab511/Mower-Robot/build /home/pi/lab511/Mower-Robot/build/CMakeFiles/mowerRobot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mowerRobot.dir/depend

