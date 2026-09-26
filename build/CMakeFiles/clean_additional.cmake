# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "CMakeFiles/UsersGroups_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/UsersGroups_autogen.dir/ParseCache.txt"
  "UsersGroups_autogen"
  )
endif()
