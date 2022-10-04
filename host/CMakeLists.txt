# Copyright (c) Open Enclave SDK contributors.
# Licensed under the MIT License.
# Protobuf
find_package(Protobuf REQUIRED)
# ZMQ
find_package(cppzmq REQUIRED)

# Protobuf
set(protobuf_files
    ${CMAKE_SOURCE_DIR}/proto/capsule.proto
)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${protobuf_files})

add_custom_command(
  OUTPUT dcr_proxy_u.h dcr_proxy_u.c dcr_proxy_args.h
  DEPENDS ${CMAKE_SOURCE_DIR}/dcr_proxy.edl
  COMMAND
    openenclave::oeedger8r --untrusted ${CMAKE_SOURCE_DIR}/dcr_proxy.edl
    --search-path ${OE_INCLUDEDIR} --search-path
    ${OE_INCLUDEDIR}/openenclave/edl/sgx
)

include_directories(${CMAKE_SOURCE_DIR}/include)
set(host_source_files
  host.cc
  comm.cc
  ${CMAKE_SOURCE_DIR}/util/logging.cc
)

add_executable(dcr_proxy_host ${host_source_files}
                               ${CMAKE_CURRENT_BINARY_DIR}/dcr_proxy_u.c
                               ${PROTO_SRCS} ${PROTO_HDRS})

target_include_directories(
  dcr_proxy_host PRIVATE # Needed for the generated file dcr_proxy_u.h
                          ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(dcr_proxy_host 
  openenclave::oehost 
  cppzmq
  protobuf::libprotobuf
)
