cmake_minimum_required(VERSION 3.25)

project(bare_hrtime C)

include(bare)

add_bare_module(bare_hrtime)

target_sources(
  ${bare_hrtime}
  PRIVATE
    binding.c
)
