cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Search_engine_cmake")

set(JSON_BuildTests OFF CACHE INTERNAL "")

include(FetchContent)

FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip DOWNLOAD_EXTRACT_TIMESTAMP TRUE)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} googletest/include)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(nlohmann_json googletest) 

add_subdirectory(src tests)

add_test(NAME testt_Search_engine_cmake COMMAND Search_engine_cmake WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Search_engine_cmake PROPERTY CXX_STANDARD 20)
endif()
