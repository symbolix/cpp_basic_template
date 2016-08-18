# targets/release #

The final application that is built without any debug symbols goes in here.

For example, an OSX application:

```
<targets/relese>
        └<PointCloudExample.app>
                    └<Contents>
                        ├<Frameworks>
                        |      ├libfmodex.dylib
                        |      └<GLUT.framework>
                        ├Info.plist
                        └<MacOS>
                                |
                                └<PointCloudExample>
```
