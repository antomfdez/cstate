project("cstate")
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY "build/" )


file(GLOB SRC_files
	src/*.cc
	src/*.hpp
)
file(GLOB INCL_files
	include/*.h
	include/*.hpp
	include/*.hxx
)

add_executable(${PROJECT_NAME} ${SRC_files} ${INCL_files})
install(TARGETS cstate DESTINATION /usr/bin)
