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
include CMakeFiles/epoll_server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/epoll_server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/epoll_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/epoll_server.dir/flags.make

CMakeFiles/epoll_server.dir/learn/src/io_function/epoll_server.cpp.o: CMakeFiles/epoll_server.dir/flags.make
CMakeFiles/epoll_server.dir/learn/src/io_function/epoll_server.cpp.o: ../learn/src/io_function/epoll_server.cpp
CMakeFiles/epoll_server.dir/learn/src/io_function/epoll_server.cpp.o: CMakeFiles/epoll_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lsl/Desktop/c+_projects/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/epoll_server.dir/learn/src/io_function/epoll_server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/epoll_server.dir/learn/src/io_function/epoll_server.cpp.o -MF CMakeFiles/epoll_server.dir/learn/src/io_function/epoll_server.cpp.o.d -o CMakeFiles/epoll_server.dir/learn/src/io_function/epoll_server.cpp.o -c /home/lsl/Desktop/c+_projects/webserver/learn/src/io_function/epoll_server.cpp

CMakeFiles/epoll_server.dir/learn/src/io_function/epoll_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/epoll_server.dir/learn/src/io_function/epoll_server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lsl/Desktop/c+_projects/webserver/learn/src/io_function/epoll_server.cpp > CMakeFiles/epoll_server.dir/learn/src/io_function/epoll_server.cpp.i

CMakeFiles/epoll_server.dir/learn/src/io_function/epoll_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/epoll_server.dir/learn/src/io_function/epoll_server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lsl/Desktop/c+_projects/webserver/learn/src/io_function/epoll_server.cpp -o CMakeFiles/epoll_server.dir/learn/src/io_function/epoll_server.cpp.s

# Object files for target epoll_server
epoll_server_OBJECTS = \
"CMakeFiles/epoll_server.dir/learn/src/io_function/epoll_server.cpp.o"

# External object files for target epoll_server
epoll_server_EXTERNAL_OBJECTS =

epoll_server: CMakeFiles/epoll_server.dir/learn/src/io_function/epoll_server.cpp.o
epoll_server: CMakeFiles/epoll_server.dir/build.make
epoll_server: CMakeFiles/epoll_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lsl/Desktop/c+_projects/webserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable epoll_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/epoll_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/epoll_server.dir/build: epoll_server
.PHONY : CMakeFiles/epoll_server.dir/build

CMakeFiles/epoll_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/epoll_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/epoll_server.dir/clean

CMakeFiles/epoll_server.dir/depend:
	cd /home/lsl/Desktop/c+_projects/webserver/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lsl/Desktop/c+_projects/webserver /home/lsl/Desktop/c+_projects/webserver /home/lsl/Desktop/c+_projects/webserver/build /home/lsl/Desktop/c+_projects/webserver/build /home/lsl/Desktop/c+_projects/webserver/build/CMakeFiles/epoll_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/epoll_server.dir/depend

