set(target ${BENCHMARK})

file(GLOB srcs "*.cpp")
set_source_files_properties(${srcs} PROPERTIES
    LABELS "${MODULE};Benchmark")

add_executable(${target} ${srcs})
set_target_properties(${target} PROPERTIES
    OUTPUT_NAME Benchmark-${MODULE}
    LABELS "${MODULE};Benchmark")

target_link_libraries(${target} ${LIBRARY})
if (UNIX)
  target_link_libraries(${target} ${CMAKE_THREAD_LIBS_INIT})
endif (UNIX)
