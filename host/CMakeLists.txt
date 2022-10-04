# Copyright (c) Open Enclave SDK contributors.
# Licensed under the MIT License.
find_package(cppzmq REQUIRED)

add_custom_command(
  OUTPUT dcr_proxy_u.h dcr_proxy_u.c dcr_proxy_args.h
  DEPENDS ${CMAKE_SOURCE_DIR}/dcr_proxy.edl
  COMMAND
    openenclave::oeedger8r --untrusted ${CMAKE_SOURCE_DIR}/dcr_proxy.edl
    --search-path ${OE_INCLUDEDIR} --search-path
    ${OE_INCLUDEDIR}/openenclave/edl/sgx)

add_executable(dcr_proxy_host host.cc
                               ${CMAKE_CURRENT_BINARY_DIR}/dcr_proxy_u.c)

if (WIN32)
  copy_oedebugrt_target(dcr_proxy_host_oedebugrt)
  add_dependencies(dcr_proxy_host dcr_proxy_host_oedebugrt)
endif ()

target_include_directories(
  dcr_proxy_host PRIVATE # Needed for the generated file dcr_proxy_u.h
                          ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(dcr_proxy_host 
  openenclave::oehost 
  cppzmq
)
