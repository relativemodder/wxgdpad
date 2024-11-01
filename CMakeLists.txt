cmake_minimum_required (VERSION 3.8)

add_compile_definitions(APP_NAME="wxGDPad")

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set(CMAKE_CXX_STANDARD 20) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project ("wxgdpad")

if (WIN32)
	include(./vcpkg/scripts/buildsystems/vcpkg.cmake) # install dependencies from vcpkg for static linking on FuckWindows
endif()

find_package(fmt CONFIG REQUIRED)
find_package(wxWidgets CONFIG REQUIRED)


file(GLOB_RECURSE PROJ_SRC src/*.c*)
file(GLOB_RECURSE PROJ_H src/*.h*)


if (WIN32)
	add_executable (wxgdpad WIN32 ${PROJ_SRC} ${PROJ_H})
else()
	add_executable (wxgdpad ${PROJ_SRC} ${PROJ_H})
endif()


if (CMAKE_VERSION VERSION_GREATER 3.7)
  set_property(TARGET wxgdpad PROPERTY CXX_STANDARD 20)
endif()

target_compile_features(wxgdpad PUBLIC cxx_std_20)

link_libraries(${OPENGL_LIBRARIES})
target_link_libraries(wxgdpad PRIVATE fmt::fmt wx::core wx::base)
target_include_directories(wxgdpad PUBLIC include)
