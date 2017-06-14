import qbs

Project {
    minimumQbsVersion: "1.6"

    references: [
        "source/qsl-host/qsl.qbs",
        "source/shared-types/shared-types.qbs",
        "share/share.qbs",
        "examples/examples.qbs"
    ]
}
