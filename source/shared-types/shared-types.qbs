import qbs

Product {
    name : "shared-types"

    files : [
        "rpc/mpimessageheader.h",
        "rpc/serialheader.cpp",
        "rpc/serialheader.h",
        "ti/drivers/Pin.h",
    ]

    Export {
        Depends { name : "cpp" }
        cpp.includePaths : path
    }
}
