/*
	Boost Competency Test (Gsoc '19)
	Author : Mudit Agarwal
	Institute: IIIT Hyderabad
*/


#ifndef RANDON_POINTS_POINTS_HPP
#define RANDON_POINTS_POINTS_HPP


#include<iostream>
#include<algorithm>
#include<vector>

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>


template <class T>
class RandomPoint{
    
    typedef boost::geometry::model::d2::point_xy<T> point_xy;
    typedef boost::geometry::model::polygon<point_xy> polygon;

    private: 
    int number_of_vertex;
    std::vector<point_xy> polygon_coordinates;
    std::vector<point_xy> generated_points;

    public:
        RandomPoint(int n_o_v);
        void AddPolygonCoordinate(point_xy pt);
        void GenerateRandomPoint(int randon_points);
        void print();
};

template <class T>
RandomPoint<T>::RandomPoint(int n_o_v):number_of_vertex(n_o_v){}
template<class T>
void RandomPoint<T>::AddPolygonCoordinate(point_xy pt){
    polygon_coordinates.push_back(pt);
}

template<class T>
void RandomPoint<T>::GenerateRandomPoint(int random_points){
    point_xy p1,p2,p3;
    float alpha,beta,gyama,new_x,new_y;
    int rand_vertex;
    while(generated_points.size()!=random_points)
    {
        //  picking three continuous vertices of polygon to form a triangle
        rand_vertex = rand() % (number_of_vertex-1);
        p1=polygon_coordinates[rand_vertex%number_of_vertex];
        p2=polygon_coordinates[(rand_vertex+1)%number_of_vertex];
        p3=polygon_coordinates[(rand_vertex+2)%number_of_vertex];

        /*
        alpha+beta+gyama = 1 constraint on alpha beta and gyama in barycentric co-ordinate 
        alpha,beta,gyama should lie in the interval [0,1] for the point to lie on or inside the triangle
        */ 
        alpha = (rand()%100)/100.0;
        beta = (rand()%  ((int)((1-alpha)*100)) )/100.0;
        gyama=1-alpha-beta;

        // Now from direct apllication of barycentric co-ordinate

        new_x=alpha*p1.x() + beta*p2.x() + gyama*p3.x();
        new_y=alpha*p1.y() + beta*p2.y() + gyama*p3.y();
        generated_points.push_back(point_xy(new_x,new_y));
    }

}

template<class T>

void RandomPoint<T>::print(){

    // Printing the random generated points inside polygon 
    for(auto&& i : generated_points)
    {
       std::cout << (i).x() <<" "<< (i).y()<<std::endl;
    }
}


#endif //RANDON_POINTS_POINTS_HPP

