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
#include<set>

using namespace std;

template <class T>
class RandomPoint{
    
    private: 
    int number_of_vertex;
    vector< pair<T,T> > polygon_coordinates;
    set< pair<T,T> > generated_points;

    public:
        RandomPoint(int n_o_v);
        void AddPolygonCoordinate(pair<T,T> pt);
        void GenerateRandomPoint(int randon_points);
        void print();
};

template <class T>
RandomPoint<T>::RandomPoint(int n_o_v):number_of_vertex(n_o_v){}

template<class T>
void RandomPoint<T>::AddPolygonCoordinate(pair<T,T> pt){
    polygon_coordinates.push_back(pt);
}

template<class T>
void RandomPoint<T>::GenerateRandomPoint(int random_points){
    pair<T,T> p1,p2,p3,new_pt;
    float alpha,beta,gyama;
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

        new_pt.first=alpha*p1.first + beta*p2.first + gyama*p3.first;
        new_pt.second=alpha*p1.second + beta*p2.second + gyama*p3.second;
        generated_points.insert(new_pt);
    }

}

template<class T>

void RandomPoint<T>::print(){

    // Printing the random generated points inside polygon 
    for(auto&& i : generated_points)
    {
        cout << (i).first <<" "<< (i).second<<endl;
    }
}


#endif //RANDON_POINTS_POINTS_HPP

