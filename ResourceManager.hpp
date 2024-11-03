#pragma once

#include "Resource.hpp"

class ResourceManager
{
    private:
    Resource* resource_;
    
    public:
    double get()
    {
        return resource_->get();
    }

    //Metody Specjalne
    //Konstruktor
    ResourceManager()
    {
        resource_ = new Resource();
    }
    //Destruktor
    ~ResourceManager()
    {
        delete resource_;
    }
    //Kopiowanie
    ResourceManager& operator=(ResourceManager& oryginal)
    {
        this->resource_ = oryginal.resource_;
    }
    //Przenoszenie
};
