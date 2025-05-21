# SPDX-License-Identifier: Apache-2.0

set(mcuboot_APPLICATION_CONFIG_DIR
    "${CMAKE_CURRENT_LIST_DIR}/../images/mcuboot"
    CACHE INTERNAL "Application configuration dir controlled by sysbuild"
)

find_package(Sysbuild REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(sysbuild LANGUAGES)


