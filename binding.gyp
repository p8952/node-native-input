{
  "targets": [
    {
      "target_name": "nodeNativeInput",
      "sources": [
        "src/nodeNativeInput.cpp",
        "src/getOne/source.cpp",
        "src/getTwo/source.cpp",
        "src/getThree/source.cpp"
      ],
      "include_dirs": ["<!(node -e \"require('nan')\")"],
      "conditions": [
        ["OS == \"win\"", {
          "defines": ["Windows"],
          "link_settings": {
            "libraries": []
          }
        }],
        ["OS == \"mac\"", {
          "defines": ["MacOS"],
          "link_settings": {
            "libraries": []
          }
        }],
        ["OS == \"linux\"", {
          "defines": ["Linux"],
          "link_settings": {
            "libraries": []
          }
        }]
      ]
    }
  ]
}
