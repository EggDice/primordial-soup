load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "component",
    hdrs = glob(["*.h"]),
    srcs = glob(["*.cpp"], ["*_test.cpp"]),
    linkopts = ["-lglut -lGL -lGLU"],
    deps = [
        "//geometry:geometry",
        "//event:event",
    ],
)

cc_library(
    name = "component_test",
    hdrs = glob(["*.h"]),
    srcs = glob(["*_test.cpp"]),
    deps = [
        "//event:event",
        "@gtest//:gtest",
    ],
)

exports_files([
    "CPPLINT.cfg",
])

cpplint()
