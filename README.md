## **Random Points Generation** 
### (Implemented the following as the competency test for **Boost.Geometry** Gsoc '19)


It uses **C++** features:
 * Expression Templates
 * Move Constructor and Move assignment operators (C++ 11 onwards)

 Highlights:
  * **Algorithm**: The algorithm gererate random points for all types of polygon. 
  * **Expression Templates**: Reduce the run time substantially by creating expression templates and avoiding temporary memory allocation and virtual function calls
   
### How to use this run: 
```
g++ barycentric_random_points.cpp 
```
