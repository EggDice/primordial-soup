cc_binary(
    name = "soup",
    srcs = ["main.cpp"],
    linkopts = ["-lglut -lGL -lGLU"],
    deps = [
        "@glm//:glm",
        "//render_system:render_system",
    ],
)

cc_test(
    name = "test",
    srcs = ["test-main.cpp"],
    deps = [
        "@glm//:glm",
        "@gtest//:gtest",
        "//render_system:render_system",
        "//render_system:render_system_test",
    ],
)
