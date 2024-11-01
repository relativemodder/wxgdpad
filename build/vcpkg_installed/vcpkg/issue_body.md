Package: pango:x64-linux@1.54.0

**Host Environment**

- Host: x64-linux
- Compiler: GNU 14.2.1
-    vcpkg-tool version: 2024-10-18-e392d7347fe72dff56e7857f7571c22301237ae6
    vcpkg-scripts version: e3497b6ae 2024-10-31 (2 hours ago)

**To Reproduce**

`vcpkg install `

**Failure logs**

```
-- Found Python version '3.12.7 at /usr/bin/python3'
-- Using meson: /home/relative/Coding/wxgdpad/vcpkg/downloads/tools/meson-1.6.0-ac58a9/meson.py
-- Downloading https://gitlab.gnome.org//GNOME/pango/-/archive/1.54.0/pango-1.54.0.tar.gz -> GNOME-pango-1.54.0.tar.gz...
[DEBUG] To include the environment variables in debug output, pass --debug-env
[DEBUG] Trying to load bundleconfig from /home/relative/Coding/wxgdpad/vcpkg/vcpkg-bundle.json
[DEBUG] Failed to open: /home/relative/Coding/wxgdpad/vcpkg/vcpkg-bundle.json
[DEBUG] Bundle config: readonly=false, usegitregistry=false, embeddedsha=nullopt, deployment=Git, vsversion=nullopt
[DEBUG] Metrics enabled.
[DEBUG] Feature flag 'binarycaching' unset
[DEBUG] Feature flag 'compilertracking' unset
[DEBUG] Feature flag 'registries' unset
[DEBUG] Feature flag 'versions' unset
[DEBUG] Feature flag 'dependencygraph' unset
[DEBUG] 1000: execute_process(curl --fail -L https://gitlab.gnome.org//GNOME/pango/-/archive/1.54.0/pango-1.54.0.tar.gz --create-dirs --output /home/relative/Coding/wxgdpad/vcpkg/downloads/GNOME-pango-1.54.0.tar.gz.1126622.part)
[DEBUG] 1000: cmd_execute_and_stream_data() returned 22 after   444549 us
error: Missing GNOME-pango-1.54.0.tar.gz and downloads are blocked by x-block-origin.
error: https://gitlab.gnome.org//GNOME/pango/-/archive/1.54.0/pango-1.54.0.tar.gz: curl failed to download with exit code 22
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed

curl: (22) The requested URL returned error: 503

[DEBUG] /source/src/vcpkg/base/downloads.cpp(1030): 
[DEBUG] Time in subprocesses: 444549us
[DEBUG] Time in parsing JSON: 2us
[DEBUG] Time in JSON reader: 0us
[DEBUG] Time in filesystem: 173us
[DEBUG] Time in loading ports: 0us
[DEBUG] Exiting after 446 ms (445791us)

CMake Error at scripts/cmake/vcpkg_download_distfile.cmake:32 (message):
      
      Failed to download file with error: 1
      If you are using a proxy, please check your proxy setting. Possible causes are:
      
      1. You are actually using an HTTP proxy, but setting HTTPS_PROXY variable
         to `https://address:port`. This is not correct, because `https://` prefix
         claims the proxy is an HTTPS proxy, while your proxy (v2ray, shadowsocksr
         , etc..) is an HTTP proxy. Try setting `http://address:port` to both
         HTTP_PROXY and HTTPS_PROXY instead.
      
      2. If you are using Windows, vcpkg will automatically use your Windows IE Proxy Settings
         set by your proxy software. See https://github.com/microsoft/vcpkg-tool/pull/77
         The value set by your proxy might be wrong, or have same `https://` prefix issue.
      
      3. Your proxy's remote server is out of service.
      
      If you've tried directly download the link, and believe this is not a temporary
      download server failure, please submit an issue at https://github.com/Microsoft/vcpkg/issues
      to report this upstream download server failure.
      

Call Stack (most recent call first):
  scripts/cmake/vcpkg_download_distfile.cmake:270 (z_vcpkg_download_distfile_show_proxy_and_fail)
  scripts/cmake/vcpkg_from_gitlab.cmake:113 (vcpkg_download_distfile)
  ports/pango/portfile.cmake:2 (vcpkg_from_gitlab)
  scripts/ports.cmake:192 (include)



```

**Additional context**

<details><summary>vcpkg.json</summary>

```
{
  "$schema": "https://raw.githubusercontent.com/microsoft/vcpkg-tool/main/docs/vcpkg.schema.json",
  "name": "wxgdpad",
  "dependencies": [
    "fmt",
    "wxwidgets"
  ]
}

```
</details>
