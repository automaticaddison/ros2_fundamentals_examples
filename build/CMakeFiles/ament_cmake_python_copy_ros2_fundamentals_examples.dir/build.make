# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/ubuntu/ros2_ws/src/ros2_fundamentals_examples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/ros2_ws/src/ros2_fundamentals_examples/build

# Utility rule file for ament_cmake_python_copy_ros2_fundamentals_examples.

# Include any custom commands dependencies for this target.
include CMakeFiles/ament_cmake_python_copy_ros2_fundamentals_examples.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ament_cmake_python_copy_ros2_fundamentals_examples.dir/progress.make

CMakeFiles/ament_cmake_python_copy_ros2_fundamentals_examples:
	/usr/bin/cmake -E copy_directory /home/ubuntu/ros2_ws/src/ros2_fundamentals_examples/ros2_fundamentals_examples /home/ubuntu/ros2_ws/src/ros2_fundamentals_examples/build/ament_cmake_python/ros2_fundamentals_examples/ros2_fundamentals_examples

ament_cmake_python_copy_ros2_fundamentals_examples: CMakeFiles/ament_cmake_python_copy_ros2_fundamentals_examples
ament_cmake_python_copy_ros2_fundamentals_examples: CMakeFiles/ament_cmake_python_copy_ros2_fundamentals_examples.dir/build.make
.PHONY : ament_cmake_python_copy_ros2_fundamentals_examples

# Rule to build all files generated by this target.
CMakeFiles/ament_cmake_python_copy_ros2_fundamentals_examples.dir/build: ament_cmake_python_copy_ros2_fundamentals_examples
.PHONY : CMakeFiles/ament_cmake_python_copy_ros2_fundamentals_examples.dir/build

CMakeFiles/ament_cmake_python_copy_ros2_fundamentals_examples.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ament_cmake_python_copy_ros2_fundamentals_examples.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ament_cmake_python_copy_ros2_fundamentals_examples.dir/clean

CMakeFiles/ament_cmake_python_copy_ros2_fundamentals_examples.dir/depend:
	cd /home/ubuntu/ros2_ws/src/ros2_fundamentals_examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/ros2_ws/src/ros2_fundamentals_examples /home/ubuntu/ros2_ws/src/ros2_fundamentals_examples /home/ubuntu/ros2_ws/src/ros2_fundamentals_examples/build /home/ubuntu/ros2_ws/src/ros2_fundamentals_examples/build /home/ubuntu/ros2_ws/src/ros2_fundamentals_examples/build/CMakeFiles/ament_cmake_python_copy_ros2_fundamentals_examples.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ament_cmake_python_copy_ros2_fundamentals_examples.dir/depend

