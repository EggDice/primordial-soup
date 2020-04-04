cc_binary(
    name = "soup",
    srcs = ["main.cpp"],
    linkopts = ["-lglut -lGL -lGLU"],
    deps = [
        "//render_system:render_system",
    ],
)

cc_test(
    name = "test",
    srcs = ["test-main.cpp"],
    linkopts = ["-lgtest -lgmock -lpthread"],
    deps = [
        "//render_system:render_system",
        "//render_system:render_system_test",
    ],
)
