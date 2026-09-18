Copied from the sibling UE1-64bit checkout.

UT99-64bit's CMake refers to `../Thirdparty/glad_es/glad.c` and to `glm`, but
the repository ships no Thirdparty directory - it is carried in emileb's older
UE1-64bit tree, which the UT99 port was derived from. Only the header-only and
loader bits are copied here; SDL2 comes from the distribution on Linux
(`-lSDL2`), so its vendored copy is deliberately not used.
