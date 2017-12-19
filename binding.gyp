{
  "targets": [
    {
      "target_name": "windows_runas",
      "sources": [
        "src/runas.cc"
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
