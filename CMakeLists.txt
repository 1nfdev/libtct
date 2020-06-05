cmake_minimum_required(VERSION 3.10)
project(libtct)

if(WIN32)
	# required to set SUBSYSTEM linker flag to WINDOWS
	# because we don't want it to be CONSOLE
	set(EXE_SUBSYSTEM WIN32)
endif()

set(SOURCES
	src/libtct.c
)

set(HEADERS
	src/libtct.h
)

add_executable(libtct ${EXE_SUBSYSTEM} ${SOURCES} ${HEADERS})

set_target_properties(libtct PROPERTIES
	C_STANDARD 99
	C_STANDARD_REQUIRED TRUE
	C_EXTENSIONS ON)

target_compile_options(libtct PRIVATE
	$<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
	$<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -pedantic -Werror>
)