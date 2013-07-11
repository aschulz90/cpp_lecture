
set(SRCROOT ${PROJECT_SOURCE_DIR}/examples/sfmltest)

# all source files
set(SRC ${SRCROOT}/sfmltest.cpp
	${SRCROOT}/sfmltest.hpp)

# define the pong target
sfml_add_example(sfmltest GUI_APP
                 SOURCES ${SRC}
                 DEPENDS sfml-graphics sfml-window sfml-system)