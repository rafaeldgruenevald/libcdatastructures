################################################################################
### Selecting CMake minimum version

CMAKE_MINIMUM_REQUIRED (VERSION 3.4.0)

################################################################################
### Setting Global Parameters

SET(PROJECT_NAME "Test Singly Linked List")
SET(BINARY_NAME "test")

PROJECT("${PROJECT_NAME}")

SET(APP_VERSION_STRING 1.0)

INCLUDE(GNUInstallDirs)

SET(APP_BASE_PATH "${PROJECT_SOURCE_DIR}/code")

SET(THREADS_PREFER_PTHREAD_FLAG ON)
FIND_PACKAGE(Threads REQUIRED)

################################################################################
### Check Dependencies

INCLUDE(CheckIncludeFile)

################################################################################
### Project definition

INCLUDE_DIRECTORIES (
	"${APP_BASE_PATH}/"
	)
	
FILE(
	GLOB SOURCES
	"${APP_BASE_PATH}/*.c"
	)
	
LINK_DIRECTORIES(
	"/usr/local/lib/"
)

ADD_DEFINITIONS("-g")

ADD_EXECUTABLE (
	${BINARY_NAME} ${SOURCES}
)
	
TARGET_LINK_LIBRARIES(${BINARY_NAME} PUBLIC "cdatastructures")

################################################################################