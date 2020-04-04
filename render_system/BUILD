_msvc_copts = ["/std:c++17"]
_gcc_copts = ["-std=c++17"]

load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "render_system",
    hdrs = glob(["*.h"]),
    srcs = glob(["*.cpp"], ["*_test.cpp"]),
    linkopts = ["-lglut -lGL -lGLU"],
    visibility = ["//main:__pkg__"],
    deps = [
        "@entt//:entt",
        "//component:component",
    ],
    copts = select({
      "@bazel_tools//src/conditions:windows": _msvc_copts,
      "@bazel_tools//src/conditions:windows_msvc": _msvc_copts,
      "@bazel_tools//src/conditions:windows_msys": _msvc_copts,
      "//conditions:default": _gcc_copts,
    }),
)

cc_library(
    name = "render_system_test",
    hdrs = glob(["*.h"]),
    srcs = glob(["*_test.cpp"]),
    linkopts = ["-lgtest -lgmock -lpthread"],
    visibility = ["//main:__pkg__"],
    deps = [
        "@entt//:entt",
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
