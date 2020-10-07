if(NOT TARGET fmt)

  # Module library
  file(GLOB SOURCE_FILES "fmt/src/*.cc")
  add_library(fmt ${SOURCE_FILES})
  target_include_directories(fmt PUBLIC "fmt/include")
  target_link_libraries(fmt)

  # Module folder
  set_target_properties(fmt PROPERTIES FOLDER "modules/fmt")

endif()
