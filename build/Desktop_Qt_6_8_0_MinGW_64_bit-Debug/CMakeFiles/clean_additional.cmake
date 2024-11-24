# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\rushe_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\rushe_autogen.dir\\ParseCache.txt"
  "rushe_autogen"
  )
endif()
