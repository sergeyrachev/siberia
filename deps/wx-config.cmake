
message(STATUS "You are able to set wxWidgets_ROOT_DIR variable to wxWidgets root folder")

find_package(wxWidgets REQUIRED net gl core base aui std stc)
include(${wxWidgets_USE_FILE})

