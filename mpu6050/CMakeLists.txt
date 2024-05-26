cmake_minimum_required(VERSION 3.22)

# https://github.com/MaJerle/stm32-cube-cmake-vscode
set(CMAKE_SKIP_INSTALL_RULES TRUE)

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)
set(PROJ_PATH ${CMAKE_CURRENT_SOURCE_DIR})
message("Build type: " ${CMAKE_BUILD_TYPE})

set(EXECUTABLE                      ${CMAKE_PROJECT_NAME})


#
# Core project settings
#
project(MPU6050)
enable_language(C ASM)

# #####################################
# target
# #####################################
set(TARGET MPU6050)

# #####################################
# building variables
# #####################################
# debug build?
set(DEBUG 1)

# optimization
set(OPT -Og)

# ######################################
# CFLAGS
# ######################################
# cpu
set(CPU -mcpu=cortex-m4)

# fpu
set(FPU -mfpu=fpv4-sp-d16)

# float-abi
set(FLOAT-ABI -mfloat-abi=hard)

# mcu
set(MCU
    ${CPU}
    -mthumb
    ${FPU}
    ${FLOAT-ABI}
)

# macros for gcc
# AS defines
set(AS_DEFS)
# AS includes
set(AS_INCLUDES)

# C defines
set(C_DEFS
    "USE_HAL_DRIVER"
    "STM32L432xx"
)

# compile gcc flags
set(ASFLAGS = ${MCU} ${AS_DEFS} ${AS_INCLUDES} ${OPT} -Wall -fdata-sections -ffunction-sections)

set(CFLAGS
    ${MCU}
    #${C_DEFS} #target_compile_options
    #${C_INCLUDES} # inlucde dirs
    ${OPT}
    -std=c11
    -Wall
    -fdata-sections
    -ffunction-sections
)

if(DEBUG)
    set(CFLAGS
        ${CFLAGS}
        -g
        -gdwarf-2
    )
endif()

set(CFLAGS
    ${CFLAGS}
    -MMD
    -MP
)

# ######################################
# LDFLAGS
# ######################################
# link script
set(LDSCRIPT ${PROJ_PATH}/STM32L432KCUx_FLASH.ld)

# libraries
set(LIBS
    -lc
    -lm
    -lnosys
)

set(LIBDIR)

set(LDFLAGS
    ${MCU}
    -specs=nano.specs
    -T${LDSCRIPT}
    ${LIBDIR}
    ${LIBS}
    -Wl,-Map=${TARGET}.map,--cref
    -Wl,--gc-sections
)

include("${PROJ_PATH}/Core/CMakeLists.txt")
include("${PROJ_PATH}/CMakeListsFw.txt")
include("${PROJ_PATH}/../lib/CMakeLists.txt")


#
# List of source files to compile
#

set(StartupFile "startup_stm32l432xx.s")

set(Src
    ${StartupFile}
    ${CoreSrc}
    ${FwSrc}
    ${LibSrc}
)

#
# Include directories
#

set(Inc
    ${CoreInc}
    ${FwInc}
    ${LibInc}
)
# Executable files
set(EXECUTABLE ${CMAKE_PROJECT_NAME})
add_executable(${EXECUTABLE} ${Src})

# Include paths
target_include_directories(${EXECUTABLE} PRIVATE ${Inc})

# Project symbols
target_compile_definitions(${EXECUTABLE} PRIVATE ${C_DEFS})

# Compiler options
target_compile_options(${EXECUTABLE} PRIVATE
    ${CFLAGS}
    -fdata-sections 
    -ffunction-sections
)

# Linker options
target_link_options(${EXECUTABLE} PRIVATE
    ${LDFLAGS}
    -Wl,--start-group
    -Wl,--end-group
    -Wl,--print-memory-usage
)

# Execute post-build to print size
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${EXECUTABLE}>
)

# Convert output to hex and binary
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${EXECUTABLE}> ${EXECUTABLE}.hex
)

# Convert to bin file -> add conditional check?
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${EXECUTABLE}> ${EXECUTABLE}.bin
)