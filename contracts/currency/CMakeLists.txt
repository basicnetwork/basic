file(GLOB SOURCE_FILES "*.cpp")
file(GLOB ABI_FILES "*.abi")
add_wast_target(currency "${SOURCE_FILES}" "${CMAKE_SOURCE_DIR}/contracts" ${CMAKE_CURRENT_BINARY_DIR})
configure_file("${ABI_FILES}" "${CMAKE_CURRENT_BINARY_DIR}" COPYONLY)
