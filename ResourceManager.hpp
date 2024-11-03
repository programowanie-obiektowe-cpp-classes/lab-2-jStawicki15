#pragma once
//#include<iostream>
#include "Resource.hpp"

class ResourceManager
{
    private:
    Resource* resource_ = nullptr;
    
    public:
    double get()
    {
        return resource_->get();
    }

    //Metody Specjalne
    //Konstruktor domyślny
    ResourceManager()
    {
        resource_ = new Resource();
    }
    //Konstruktor kopiujący???
    ResourceManager(const ResourceManager& oryginal) : resource_{oryginal.resource_} {}
    //{std::cout<<"Konstruktor kopiujacy wywolany";}
    //Destruktor
    ~ResourceManager()
    {
        delete resource_;
    }
    //Kopiowanie
    ResourceManager& operator=(const ResourceManager& oryginal)
    {
        this->resource_ = oryginal.resource_;
        //std::cout<<"Kopiowanie wywolane";
        return *this;
    }
    //Przenoszenie
};
