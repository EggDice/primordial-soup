_msvc_copts = ["/std:c++17"]
_gcc_copts = ["-std=c++17"]

cc_binary(
    name = "soup",
    srcs = ["main.cpp"],
    linkopts = ["-lglut -lGL -lGLU"],
    deps = [
        "@glm//:glm",
        "//program:program",
        "//rendering:rendering",

    ],
    copts = select({
      "@bazel_tools//src/conditions:windows": _msvc_copts,
      "@bazel_tools//src/conditions:windows_msvc": _msvc_copts,
      "@bazel_tools//src/conditions:windows_msys": _msvc_copts,
      "//conditions:default": _gcc_copts,
    }),
)

cc_test(
    name = "test",
    srcs = ["test-main.cpp"],
    deps = [
        "@glm//:glm",
        "@gtest//:gtest",
        "//rendering:rendering",
        "//rendering:rendering_test",
        "//geometry:geometry_test",
        "//component:component_test",
        "//program:program_test",
    ],
    copts = select({
      "@bazel_tools//src/conditions:windows": _msvc_copts,
      "@bazel_tools//src/conditions:windows_msvc": _msvc_copts,
      "@bazel_tools//src/conditions:windows_msys": _msvc_copts,
      "//conditions:default": _gcc_copts,
    }),
)
