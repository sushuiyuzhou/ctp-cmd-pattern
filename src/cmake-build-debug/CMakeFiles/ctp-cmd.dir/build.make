# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/sushuiyuzhou/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/182.4892.24/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/sushuiyuzhou/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/182.4892.24/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sushuiyuzhou/temp/ctp-cmd-pattern/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sushuiyuzhou/temp/ctp-cmd-pattern/src/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ctp-cmd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ctp-cmd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ctp-cmd.dir/flags.make

CMakeFiles/ctp-cmd.dir/main.cpp.o: CMakeFiles/ctp-cmd.dir/flags.make
CMakeFiles/ctp-cmd.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sushuiyuzhou/temp/ctp-cmd-pattern/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ctp-cmd.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ctp-cmd.dir/main.cpp.o -c /home/sushuiyuzhou/temp/ctp-cmd-pattern/src/main.cpp

CMakeFiles/ctp-cmd.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ctp-cmd.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sushuiyuzhou/temp/ctp-cmd-pattern/src/main.cpp > CMakeFiles/ctp-cmd.dir/main.cpp.i

CMakeFiles/ctp-cmd.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ctp-cmd.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sushuiyuzhou/temp/ctp-cmd-pattern/src/main.cpp -o CMakeFiles/ctp-cmd.dir/main.cpp.s

CMakeFiles/ctp-cmd.dir/trade/TradeSpi.cpp.o: CMakeFiles/ctp-cmd.dir/flags.make
CMakeFiles/ctp-cmd.dir/trade/TradeSpi.cpp.o: ../trade/TradeSpi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sushuiyuzhou/temp/ctp-cmd-pattern/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ctp-cmd.dir/trade/TradeSpi.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ctp-cmd.dir/trade/TradeSpi.cpp.o -c /home/sushuiyuzhou/temp/ctp-cmd-pattern/src/trade/TradeSpi.cpp

CMakeFiles/ctp-cmd.dir/trade/TradeSpi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ctp-cmd.dir/trade/TradeSpi.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sushuiyuzhou/temp/ctp-cmd-pattern/src/trade/TradeSpi.cpp > CMakeFiles/ctp-cmd.dir/trade/TradeSpi.cpp.i

CMakeFiles/ctp-cmd.dir/trade/TradeSpi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ctp-cmd.dir/trade/TradeSpi.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sushuiyuzhou/temp/ctp-cmd-pattern/src/trade/TradeSpi.cpp -o CMakeFiles/ctp-cmd.dir/trade/TradeSpi.cpp.s

# Object files for target ctp-cmd
ctp__cmd_OBJECTS = \
"CMakeFiles/ctp-cmd.dir/main.cpp.o" \
"CMakeFiles/ctp-cmd.dir/trade/TradeSpi.cpp.o"

# External object files for target ctp-cmd
ctp__cmd_EXTERNAL_OBJECTS =

ctp-cmd: CMakeFiles/ctp-cmd.dir/main.cpp.o
ctp-cmd: CMakeFiles/ctp-cmd.dir/trade/TradeSpi.cpp.o
ctp-cmd: CMakeFiles/ctp-cmd.dir/build.make
ctp-cmd: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
ctp-cmd: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
ctp-cmd: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
ctp-cmd: /usr/lib/x86_64-linux-gnu/libboost_system.so
ctp-cmd: CMakeFiles/ctp-cmd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sushuiyuzhou/temp/ctp-cmd-pattern/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ctp-cmd"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ctp-cmd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ctp-cmd.dir/build: ctp-cmd

.PHONY : CMakeFiles/ctp-cmd.dir/build

CMakeFiles/ctp-cmd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ctp-cmd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ctp-cmd.dir/clean

CMakeFiles/ctp-cmd.dir/depend:
	cd /home/sushuiyuzhou/temp/ctp-cmd-pattern/src/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sushuiyuzhou/temp/ctp-cmd-pattern/src /home/sushuiyuzhou/temp/ctp-cmd-pattern/src /home/sushuiyuzhou/temp/ctp-cmd-pattern/src/cmake-build-debug /home/sushuiyuzhou/temp/ctp-cmd-pattern/src/cmake-build-debug /home/sushuiyuzhou/temp/ctp-cmd-pattern/src/cmake-build-debug/CMakeFiles/ctp-cmd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ctp-cmd.dir/depend
