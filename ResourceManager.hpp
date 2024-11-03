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
    //Konstruktor domyślny
    ResourceManager()
    {
        resource_ = new Resource();
    }
    //Konstruktor kopiujący???
    ResourceManager(const ResourceManager& oryginal)
    {
        resource_ = oryginal.resource_;
    }
    //Destruktor
    ~ResourceManager()
    {
        delete resource_;
    }
    //Kopiowanie
    ResourceManager operator=(const ResourceManager& oryginal)
    {
        this->resource_ = oryginal.resource_;
    }
    //Przenoszenie
};
