cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Search_engine_cmake")

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json) 

add_subdirectory(src) 

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Search_engine_cmake PROPERTY CXX_STANDARD 20)
endif()
