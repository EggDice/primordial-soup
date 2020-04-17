_msvc_copts = ["/std:c++2a"]
_gcc_copts = ["-std=c++2a"]

load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "controls",
    hdrs = glob(["*.h"]),
    srcs = glob(["*.cpp"], ["*_test.cpp"]),
    linkopts = ["-lglut -lGL -lGLU"],
    deps = [
        "@glm//:glm",
        "@entt//:entt",
        "//event:event",
        "//component:component",
    ],
    copts = select({
      "@bazel_tools//src/conditions:windows": _msvc_copts,
      "@bazel_tools//src/conditions:windows_msvc": _msvc_copts,
      "@bazel_tools//src/conditions:windows_msys": _msvc_copts,
      "//conditions:default": _gcc_copts,
    }),)

cc_library(
    name = "controls_test",
    hdrs = glob(["*.h"]),
    srcs = glob(["*_test.cpp"]),
    visibility = ["//main:__pkg__"],
    deps = [
        "@gtest//:gtest",
        "@glm//:glm",
        "@entt//:entt",
        "//event:event",
        "//component:component",
    ],
    copts = select({
      "@bazel_tools//src/conditions:windows": _msvc_copts,
      "@bazel_tools//src/conditions:windows_msvc": _msvc_copts,
      "@bazel_tools//src/conditions:windows_msys": _msvc_copts,
      "//conditions:default": _gcc_copts,
    }),
)

exports_files([
    "CPPLINT.cfg",
])

cpplint()
