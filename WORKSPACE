workspace(name = "soup")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "google_styleguide",
    url = "https://pypi.python.org/packages/source/c/cpplint/cpplint-1.4.5.tar.gz",
    sha256 = "08b384606136146ac1d32a2ffb60623a5dc1b20434588eaa0fa12a6e24eb3bf5",
    build_file = "cpplint.BUILD",
    strip_prefix = "cpplint-1.4.5"
)
