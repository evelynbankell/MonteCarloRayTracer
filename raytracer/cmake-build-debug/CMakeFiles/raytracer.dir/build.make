# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
<<<<<<< HEAD
CMAKE_SOURCE_DIR = /Users/evelynbankell/Documents/TNCG15/raytracer/raytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/evelynbankell/Documents/TNCG15/raytracer/raytracer/cmake-build-debug
=======
CMAKE_SOURCE_DIR = /Users/hannahbergenroth/Desktop/TNCG15/ray-tracer/raytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hannahbergenroth/Desktop/TNCG15/ray-tracer/raytracer/cmake-build-debug
>>>>>>> 9974ababca4b50ae33b8f683f072b47a87fa167d

# Include any dependencies generated for this target.
include CMakeFiles/raytracer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/raytracer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/raytracer.dir/flags.make

CMakeFiles/raytracer.dir/src/main.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/src/main.cpp.o: ../src/main.cpp
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evelynbankell/Documents/TNCG15/raytracer/raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/raytracer.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracer.dir/src/main.cpp.o -c /Users/evelynbankell/Documents/TNCG15/raytracer/raytracer/src/main.cpp

CMakeFiles/raytracer.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evelynbankell/Documents/TNCG15/raytracer/raytracer/src/main.cpp > CMakeFiles/raytracer.dir/src/main.cpp.i

CMakeFiles/raytracer.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evelynbankell/Documents/TNCG15/raytracer/raytracer/src/main.cpp -o CMakeFiles/raytracer.dir/src/main.cpp.s

CMakeFiles/raytracer.dir/src/Camera.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/src/Camera.cpp.o: ../src/Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evelynbankell/Documents/TNCG15/raytracer/raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/raytracer.dir/src/Camera.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracer.dir/src/Camera.cpp.o -c /Users/evelynbankell/Documents/TNCG15/raytracer/raytracer/src/Camera.cpp

CMakeFiles/raytracer.dir/src/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/src/Camera.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evelynbankell/Documents/TNCG15/raytracer/raytracer/src/Camera.cpp > CMakeFiles/raytracer.dir/src/Camera.cpp.i

CMakeFiles/raytracer.dir/src/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/src/Camera.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evelynbankell/Documents/TNCG15/raytracer/raytracer/src/Camera.cpp -o CMakeFiles/raytracer.dir/src/Camera.cpp.s
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hannahbergenroth/Desktop/TNCG15/ray-tracer/raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/raytracer.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracer.dir/src/main.cpp.o -c /Users/hannahbergenroth/Desktop/TNCG15/ray-tracer/raytracer/src/main.cpp

CMakeFiles/raytracer.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hannahbergenroth/Desktop/TNCG15/ray-tracer/raytracer/src/main.cpp > CMakeFiles/raytracer.dir/src/main.cpp.i

CMakeFiles/raytracer.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hannahbergenroth/Desktop/TNCG15/ray-tracer/raytracer/src/main.cpp -o CMakeFiles/raytracer.dir/src/main.cpp.s

CMakeFiles/raytracer.dir/src/Camera.cpp.o: CMakeFiles/raytracer.dir/flags.make
CMakeFiles/raytracer.dir/src/Camera.cpp.o: ../src/Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hannahbergenroth/Desktop/TNCG15/ray-tracer/raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/raytracer.dir/src/Camera.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raytracer.dir/src/Camera.cpp.o -c /Users/hannahbergenroth/Desktop/TNCG15/ray-tracer/raytracer/src/Camera.cpp

CMakeFiles/raytracer.dir/src/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raytracer.dir/src/Camera.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hannahbergenroth/Desktop/TNCG15/ray-tracer/raytracer/src/Camera.cpp > CMakeFiles/raytracer.dir/src/Camera.cpp.i

CMakeFiles/raytracer.dir/src/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raytracer.dir/src/Camera.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hannahbergenroth/Desktop/TNCG15/ray-tracer/raytracer/src/Camera.cpp -o CMakeFiles/raytracer.dir/src/Camera.cpp.s
>>>>>>> 9974ababca4b50ae33b8f683f072b47a87fa167d

# Object files for target raytracer
raytracer_OBJECTS = \
"CMakeFiles/raytracer.dir/src/main.cpp.o" \
"CMakeFiles/raytracer.dir/src/Camera.cpp.o"

# External object files for target raytracer
raytracer_EXTERNAL_OBJECTS =

raytracer: CMakeFiles/raytracer.dir/src/main.cpp.o
raytracer: CMakeFiles/raytracer.dir/src/Camera.cpp.o
raytracer: CMakeFiles/raytracer.dir/build.make
raytracer: CMakeFiles/raytracer.dir/link.txt
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/evelynbankell/Documents/TNCG15/raytracer/raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable raytracer"
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hannahbergenroth/Desktop/TNCG15/ray-tracer/raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable raytracer"
>>>>>>> 9974ababca4b50ae33b8f683f072b47a87fa167d
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raytracer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/raytracer.dir/build: raytracer

.PHONY : CMakeFiles/raytracer.dir/build

CMakeFiles/raytracer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/raytracer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/raytracer.dir/clean

CMakeFiles/raytracer.dir/depend:
<<<<<<< HEAD
	cd /Users/evelynbankell/Documents/TNCG15/raytracer/raytracer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/evelynbankell/Documents/TNCG15/raytracer/raytracer /Users/evelynbankell/Documents/TNCG15/raytracer/raytracer /Users/evelynbankell/Documents/TNCG15/raytracer/raytracer/cmake-build-debug /Users/evelynbankell/Documents/TNCG15/raytracer/raytracer/cmake-build-debug /Users/evelynbankell/Documents/TNCG15/raytracer/raytracer/cmake-build-debug/CMakeFiles/raytracer.dir/DependInfo.cmake --color=$(COLOR)
=======
	cd /Users/hannahbergenroth/Desktop/TNCG15/ray-tracer/raytracer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hannahbergenroth/Desktop/TNCG15/ray-tracer/raytracer /Users/hannahbergenroth/Desktop/TNCG15/ray-tracer/raytracer /Users/hannahbergenroth/Desktop/TNCG15/ray-tracer/raytracer/cmake-build-debug /Users/hannahbergenroth/Desktop/TNCG15/ray-tracer/raytracer/cmake-build-debug /Users/hannahbergenroth/Desktop/TNCG15/ray-tracer/raytracer/cmake-build-debug/CMakeFiles/raytracer.dir/DependInfo.cmake --color=$(COLOR)
>>>>>>> 9974ababca4b50ae33b8f683f072b47a87fa167d
.PHONY : CMakeFiles/raytracer.dir/depend
