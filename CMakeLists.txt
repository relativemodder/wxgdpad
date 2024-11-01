# CMakeList.txt : CMake project for wxgdpad, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set(CMAKE_CXX_STANDARD 20) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project ("wxgdpad")

include(./vcpkg/scripts/buildsystems/vcpkg.cmake)

find_package(fmt CONFIG REQUIRED)
find_package(wxWidgets CONFIG REQUIRED)


# Add source to this project's executable.
add_executable (wxgdpad WIN32 "wxgdpad.cpp" "wxgdpad.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET wxgdpad PROPERTY CXX_STANDARD 20)
endif()

link_libraries(${OPENGL_LIBRARIES})

# TODO: Add tests and install targets if needed.
target_link_libraries(wxgdpad PRIVATE fmt::fmt wx::core wx::base)