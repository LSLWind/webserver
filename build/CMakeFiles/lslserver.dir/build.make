# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lsl/Desktop/c+_projects/webserver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lsl/Desktop/c+_projects/webserver/build

# Include any dependencies generated for this target.
include CMakeFiles/lslserver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lslserver.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lslserver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lslserver.dir/flags.make

CMakeFiles/lslserver.dir/main.cpp.o: CMakeFiles/lslserver.dir/flags.make
CMakeFiles/lslserver.dir/main.cpp.o: ../main.cpp
CMakeFiles/lslserver.dir/main.cpp.o: CMakeFiles/lslserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lsl/Desktop/c+_projects/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lslserver.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lslserver.dir/main.cpp.o -MF CMakeFiles/lslserver.dir/main.cpp.o.d -o CMakeFiles/lslserver.dir/main.cpp.o -c /home/lsl/Desktop/c+_projects/webserver/main.cpp

CMakeFiles/lslserver.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lslserver.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lsl/Desktop/c+_projects/webserver/main.cpp > CMakeFiles/lslserver.dir/main.cpp.i

CMakeFiles/lslserver.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lslserver.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lsl/Desktop/c+_projects/webserver/main.cpp -o CMakeFiles/lslserver.dir/main.cpp.s

# Object files for target lslserver
lslserver_OBJECTS = \
"CMakeFiles/lslserver.dir/main.cpp.o"

# External object files for target lslserver
lslserver_EXTERNAL_OBJECTS =

lslserver: CMakeFiles/lslserver.dir/main.cpp.o
lslserver: CMakeFiles/lslserver.dir/build.make
lslserver: CMakeFiles/lslserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lsl/Desktop/c+_projects/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lslserver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lslserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lslserver.dir/build: lslserver
.PHONY : CMakeFiles/lslserver.dir/build

CMakeFiles/lslserver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lslserver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lslserver.dir/clean

CMakeFiles/lslserver.dir/depend:
	cd /home/lsl/Desktop/c+_projects/webserver/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lsl/Desktop/c+_projects/webserver /home/lsl/Desktop/c+_projects/webserver /home/lsl/Desktop/c+_projects/webserver/build /home/lsl/Desktop/c+_projects/webserver/build /home/lsl/Desktop/c+_projects/webserver/build/CMakeFiles/lslserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lslserver.dir/depend

