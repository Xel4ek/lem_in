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
CMAKE_COMMAND = /opt/clion-2019.3.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.3.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xel/projects/lem_in

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xel/projects/lem_in/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/test_str_len.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_str_len.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_str_len.dir/flags.make

CMakeFiles/test_str_len.dir/test_str_len.c.o: CMakeFiles/test_str_len.dir/flags.make
CMakeFiles/test_str_len.dir/test_str_len.c.o: ../test_str_len.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xel/projects/lem_in/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_str_len.dir/test_str_len.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_str_len.dir/test_str_len.c.o   -c /home/xel/projects/lem_in/test_str_len.c

CMakeFiles/test_str_len.dir/test_str_len.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_str_len.dir/test_str_len.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/xel/projects/lem_in/test_str_len.c > CMakeFiles/test_str_len.dir/test_str_len.c.i

CMakeFiles/test_str_len.dir/test_str_len.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_str_len.dir/test_str_len.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/xel/projects/lem_in/test_str_len.c -o CMakeFiles/test_str_len.dir/test_str_len.c.s

# Object files for target test_str_len
test_str_len_OBJECTS = \
"CMakeFiles/test_str_len.dir/test_str_len.c.o"

# External object files for target test_str_len
test_str_len_EXTERNAL_OBJECTS =

test_str_len: CMakeFiles/test_str_len.dir/test_str_len.c.o
test_str_len: CMakeFiles/test_str_len.dir/build.make
test_str_len: lib/libft/liblibft.a
test_str_len: CMakeFiles/test_str_len.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xel/projects/lem_in/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test_str_len"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_str_len.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_str_len.dir/build: test_str_len

.PHONY : CMakeFiles/test_str_len.dir/build

CMakeFiles/test_str_len.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_str_len.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_str_len.dir/clean

CMakeFiles/test_str_len.dir/depend:
	cd /home/xel/projects/lem_in/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xel/projects/lem_in /home/xel/projects/lem_in /home/xel/projects/lem_in/cmake-build-release /home/xel/projects/lem_in/cmake-build-release /home/xel/projects/lem_in/cmake-build-release/CMakeFiles/test_str_len.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_str_len.dir/depend

