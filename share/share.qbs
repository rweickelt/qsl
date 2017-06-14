import qbs

Product {
    name : "shared resources"
    type: ["copied qsl resources"]

    readonly property stringList qmlImportPaths : [
        sourceDirectory + "/qsl/imports",
    ]

    Group {
        name : "qsl imports"
        prefix : "qsl/imports/qsl/"

        files : [
            "QslApplication.qml",
            "qmldir",
        ]

        fileTags : ["qsl resources"]
        qbs.install : true
        qbs.installDir : "share/"
        qbs.installSourceBase : "."
    }
}
