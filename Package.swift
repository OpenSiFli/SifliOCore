
// swift-tools-version: 6.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "SifliOCore",
    platforms: [
        .iOS(.v12),
        .macOS(.v10_15)
    ],
    products: [
        .library(
            name: "SifliOCore",
            targets: ["SifliOCore"]),
    ],
    targets: [
        .binaryTarget(
            name: "SifliOCore",
            path: "Sources/SifliOCore/SifliOCore.xcframework"
        ),
        .testTarget(
            name: "SifliOCoreTests",
            dependencies: ["SifliOCore"]
        ),
    ]
)
