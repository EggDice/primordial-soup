load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "render_system",
    hdrs = glob(["*.h"]),
    srcs = glob(["*.cpp"], ["*_test.cpp"]),
    linkopts = ["-lglut -lGL -lGLU"],
    visibility = ["//main:__pkg__"],
)

cc_library(
    name = "render_system_test",
    hdrs = glob(["*.h"]),
    srcs = glob(["*_test.cpp"]),
    linkopts = ["-lgtest -lpthread"],
    visibility = ["//main:__pkg__"],
)

exports_files([
    "CPPLINT.cfg",
])

cpplint()
