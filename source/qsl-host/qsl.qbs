import qbs 1.0

QtApplication {
    name : "qsl-host"

    Depends { name : "Qt.core" }
    Depends { name : "Qt.quick" }
    Depends { name : "Qt.script" }
    Depends { name : "Qt.serialport" }
    Depends { name : "cpp" }
    Depends { name : "Qt.qml-private" }
    Depends { name : "shared-types" }

    cpp.cxxLanguageVersion : "c++11"

    consoleApplication : true
    targetName : "qsl"

    files : [
        "main.cpp",
        "mpihost.cpp",
        "mpihost.h",
        "mpihostmessage.cpp",
        "mpihostmessage.h",
        "mpihostobject.cpp",
        "mpihostobject.h",
        "pin.cpp",
        "pin.h",
        "serialinterface.cpp",
        "serialinterface.h",
    ]

    Group {
        fileTagsFilter: product.type
        qbs.install: true
        qbs.installDir : "bin"
    }
}
