# core flags

set(CORE_FLAGS "-march=rv32imac -mabi=ilp32 -mcmodel=medany -fsigned-char -fno-builtin -nostartfiles" CACHE INTERNAL "CPU flags")
add_definitions(${CORE_FLAGS})
# link with linker file
target_link_libraries(${elf_file} PUBLIC -T ${CMAKE_CURRENT_SOURCE_DIR}/linkers/gd32vf103.ld)
target_link_libraries(${elf_file} PUBLIC -nostartfiles --specs=${CMAKE_CURRENT_SOURCE_DIR}/patch.specs)
