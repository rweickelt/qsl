import qbs 1.0

Product {
    name : "examples"

    qbs.install : true
    qbs.installDir : "examples/"
    qbs.installSourceBase : "."

    files : [
        "EasyLink.qml",
        "mockup.qml",
        "pintestapplication.qml",
    ]
}
