{
  "targets": [
    {
      "target_name": "nodeNativeInput",
      "include_dirs": ["<!(node -e \"require('nan')\")"],
      "sources": [
        "src/nodeNativeInput.cpp",
        "src/getOne/getOne.cpp",
        "src/getTwo/getTwo.cpp",
        "src/getThree/getThree.cpp",
        "src/getScreenDimensions/getScreenDimensions.cpp"
      ],
      "cflags": [
        "-Wall",
        "-Wextra",
        "-Wpedantic",
        "-Werror",
        "-Wfatal-errors"
      ],
      "conditions": [
        [
          "OS == \"win\"",
          {
            "defines": ["Windows"],
            "link_settings": {
              "libraries": []
            }
          }
        ],
        [
          "OS == \"mac\"",
          {
            "defines": ["MacOS"],
            "link_settings": {
              "libraries": []
            }
          }
        ],
        [
          "OS == \"linux\"",
          {
            "defines": ["Linux"],
            "link_settings": {
              "libraries": ["-lX11"]
            }
          }
        ]
      ]
    }
  ]
}
