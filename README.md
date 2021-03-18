# finds
Finds is a command line utility to find strings across files or directories.

# Usage
The first command line parameter is the string to find. It may be mutliple words if enclosed in "". The rest
of the command line arguments are paths to search.
***finds "string" path1 path2 ***

The output will be the line numbers in which the string occurs and in which file it occurs, along with the total
occurances. 
Sample run:
```
finds "hello world" ~/Android/
Found "hello world" at /home/lucas/Android/Sdk/system-images/android-30/google_apis_playstore/x86/system.img line 4605800
Found "hello world" at /home/lucas/Android/Sdk/system-images/android-30/google_apis_playstore/x86/system.img line 4685069
Found "hello world" at /home/lucas/Android/Sdk/system-images/android-30/google_apis/x86/system.img line 4667637
Found "hello world" at /home/lucas/Android/Sdk/system-images/android-30/google_apis/x86/system.img line 4746906
Found "hello world" at /home/lucas/Android/Sdk/platform-tools/systrace/catapult/common/py_vulcanize/py_vulcanize/style_sheet_unittest.py line 24
Found "hello world" at /home/lucas/Android/Sdk/platform-tools/systrace/catapult/common/py_vulcanize/py_vulcanize/style_sheet_unittest.py line 41
Found "hello world" at /home/lucas/Android/Sdk/platform-tools/systrace/catapult/third_party/polymer/components/paper-toast/test/basic.html line 119
Found "hello world" at /home/lucas/Android/Sdk/platform-tools/systrace/catapult/third_party/polymer/components/paper-toast/test/basic.html line 121
Found "hello world" at /home/lucas/Android/Sdk/platform-tools/systrace/catapult/third_party/polymer/components/paper-toast/test/basic.html line 142
Found "hello world" at /home/lucas/Android/Sdk/platform-tools/systrace/catapult/third_party/polymer/components/paper-toast/test/basic.html line 143
Found "hello world" at /home/lucas/Android/Sdk/platform-tools/systrace/catapult/third_party/polymer/components/iron-ajax/test/iron-request.html line 293
Found "hello world" at /home/lucas/Android/Sdk/platform-tools/systrace/catapult/devil/devil/utils/cmd_helper_test.py line 24
Found "hello world" at /home/lucas/Android/Sdk/platform-tools/systrace/catapult/devil/devil/utils/cmd_helper_test.py line 42
Found "hello world" at /home/lucas/Android/Sdk/platform-tools/systrace/catapult/devil/devil/utils/cmd_helper_test.py line 51
Found "hello world" at /home/lucas/Android/Sdk/platform-tools/systrace/catapult/devil/devil/android/device_utils_test.py line 1359
Found "hello world" at /home/lucas/Android/Sdk/platform-tools/systrace/catapult/devil/devil/android/device_utils_test.py line 1360
Found "hello world" at /home/lucas/Android/Sdk/platform-tools/systrace/catapult/devil/devil/android/device_utils_test.py line 3865
Found "hello world" at /home/lucas/Android/Sdk/platform-tools/systrace/catapult/devil/devil/android/crash_handler_devicetest.py line 37
Found "hello world" at /home/lucas/Android/Sdk/sources/android-30/java/net/URL.java line 128
Found "hello world" at /home/lucas/Android/Sdk/sources/android-30/com/android/setupwizardlib/template/IconMixinTest.java line 129
Found "hello world" at /home/lucas/Android/Sdk/sources/android-30/com/android/setupwizardlib/template/IconMixinTest.java line 130
Found 21 occurances.
```

## Notes
Non-regular files are skipped, such a block devices, pipes, etc. Executable files are not skipped, as scripts may need to be parsed. This may lead to false positives in some file types like imagaes or binary executables. 
