#ifndef INTERSECTIONS_H
#define INTERSECTIONS_H
#include <vector>
#include <iostream>
#include "Intersection.h"


class Intersections
{


    public:
        std::vector <Intersection> tab;
        Intersections();
        virtual ~Intersections();

        // Method that adds new intersection to tab
        void AddIntersection(int newX, int newY, bool newNOK, bool newSOK, bool newEOK, bool newWOK);

        // Method that returns amount of intersections in tab
        int GetTabSize();

        // Method that takes id and return Intersection from tab
        Intersection GetIntersectionById(int id);

        // Method that draws all intersections for Tab
        void DrawAllIntersections(sf::RenderWindow &appWindow);
    protected:

    private:
};

#endif // INTERSECTIONS_H
