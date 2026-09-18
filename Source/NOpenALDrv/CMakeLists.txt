project(NOpenALDrv C CXX)

# Ported from the sibling UE1-64bit tree, which is where this driver comes
# from. Unlike that tree we do not build the vendored openal-soft and
# libxmp-lite: on Linux both are distribution packages (libopenal-dev,
# libxmp-dev), the cross image carries the arm64 builds, and the AppImage
# bundler collects whatever the binary actually links.
set(SRC_FILES "NOpenALDrv.cpp")

add_library(${PROJECT_NAME} ${LIB_TYPE} ${SRC_FILES})

target_include_directories(${PROJECT_NAME}
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/Inc
)

target_link_libraries(${PROJECT_NAME} openal xmp)
target_link_libraries(${PROJECT_NAME} Engine Core)

target_compile_definitions(${PROJECT_NAME} PRIVATE NOPENALDRV_EXPORTS UPACKAGE_NAME=${PROJECT_NAME})
