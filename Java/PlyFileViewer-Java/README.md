# PlyFileViewer-Java

PlyFileViewer-Java is a JavaFX application that allows you to view PLY files. PLY files can be in ASCII or binary format. The application was developed using Java and the Ant framework for managing the build system.

## Main Classes

### `PlyFileViewerJava`

This is the main class of the application. It extends `Application` from JavaFX and manages the display of a PLY file. The choice to extend `Application` is due to the fact that it represents the entry point for all JavaFX applications.

The `PlyFileViewerJava` class contains methods for mouse management, camera position, and the calculation of the bounding box of a MeshView. These methods are essential to allow the user to interact with the 3D view of the PLY file.

The `start` method is the entry point of the application. Here the `Scene` and the `Group` that will contain the mesh are created. The type of PLY file (ASCII or binary) is then identified and the file is read. Finally, the mesh to be displayed is created and the camera is set.

The `setCameraPosition` method sets the position of the camera to correctly display the mesh. This is done by calculating the bounding box of the mesh and positioning the camera so that the mesh is centered in the view.

The `mouseHandler` method manages the mouse's interaction with the scene. It allows the user to rotate the view by dragging the mouse.

The `calculateBoundingBox` method calculates the bounding box of a MeshView. This is useful for determining the position of the camera.

### `PlyReader`

This is an abstract class that defines the basic structure for reading a PLY file. It has two child classes, `PlyReaderAscii` and `PlyReaderBin`, which implement the reading of PLY files in ASCII and binary format respectively.

The choice to create an abstract `PlyReader` class and two specific subclasses for ASCII and binary formats is due to the fact that the reading of PLY files varies depending on the format. However, there are some operations, such as storing vertices and faces, which are common to both formats. These common operations are implemented in the abstract `PlyReader` class, while format-specific operations are implemented in the subclasses.

### `PlyReaderAscii`

This class extends `PlyReader` and implements the reading of PLY files in ASCII format. It uses a `BufferedReader` to read the file. The `readPlyFile` method reads the file header, vertices, and faces.

### `PlyReaderBin` (NOT WORKING)

This class extends `PlyReader` and implements the reading of PLY files in binary format. It uses a `BufferedInputStream` to read the file. The `readPlyFile` method reads the file header, vertices, and faces. Unlike the `PlyReaderAscii` class, this class must handle the reading of numbers in binary format and the difference between little endian and big endian.

### `IdentifierPlyType`

This class contains a static method to identify the type of PLY file (ASCII or binary). This is useful for determining which subclass of `PlyReader` to use to read the file.

### `Vertex`

This class represents a vertex in a PLY file. It contains x, y, z coordinates. These coordinates are used to create the mesh to be displayed.

### `Face`

This class represents a face in a PLY file. It contains an array of vertex indices. These indices are used to create the mesh to be displayed.

### `Rect3D`

This class represents a 3D rectangle. It is used to calculate the bounding box of a MeshView. This is useful for determining the position of the camera.

## Usage

To use the application, run the `PlyFileViewerJava` class. The application will display the PLY file specified in the `filePath` field.

## Note

The application only supports PLY files with 3 vertices faces, files with a different number of vertices per face may not be displayed correctly. It supports ply files with no colors in it and the ply bin reader does not work for now. 
