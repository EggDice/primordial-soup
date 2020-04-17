_msvc_copts = ["/std:c++2a"]
_gcc_copts = ["-std=c++2a"]

load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "event",
    hdrs = glob(["*.h"]),
    srcs = glob(["*.cpp"], ["*_test.cpp"]),
    linkopts = ["-lglut -lGL -lGLU"],
    deps = [
    ],
    copts = select({
      "@bazel_tools//src/conditions:windows": _msvc_copts,
      "@bazel_tools//src/conditions:windows_msvc": _msvc_copts,
      "@bazel_tools//src/conditions:windows_msys": _msvc_copts,
      "//conditions:default": _gcc_copts,
    }),
)

cc_library(
    name = "event_test",
    hdrs = glob(["*.h"]),
    srcs = glob(["*_test.cpp"]),
    deps = [
        "@gtest//:gtest",
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
