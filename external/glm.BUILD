package(default_visibility = ["//visibility:public"])

cc_library(
  name= "glm",
  defines= ["GLM_ENABLE_EXPERIMENTAL", "GLM_FORCE_RADIANS", "GLM_FORCE_DEPTH_ZERO_TO_ONE"],
  srcs=glob(["glm/**/*.cpp"]) + ["glm/detail/_fixes.hpp"],
  hdrs=glob(["glm/**/*.hpp"])+glob(["glm/**/*.h"]),
  includes = [".", "glm"],
  textual_hdrs = glob(["glm/**/*.inl"]),
  visibility = ["//visibility:public"],
)
