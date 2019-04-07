## **Random Points Generation** 
### (Implemented the following as the competency test for **Boost.Geometry** Gsoc '19)


It uses **C++** features:
 * Expression Templates
 * Move Constructor and Move assignment operators (C++ 11 onwards)

 Highlights:
  * **Algorithm**: The algorithm generate random points only for convex polygon. 
  * **Expression Templates**: Reduce the run time substantially by creating expression templates and avoiding temporary memory allocation and virtual function calls
   
### How to use this header: 
  1. Clone/Download this directory (or the file)
  1. Include the header in your code by specifying the absolute or relative path **( #include"/file_path/barycentric_random_points.hpp")**
