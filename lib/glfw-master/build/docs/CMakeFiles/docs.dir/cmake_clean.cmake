file(REMOVE_RECURSE
  "html/index.html"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/docs.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
