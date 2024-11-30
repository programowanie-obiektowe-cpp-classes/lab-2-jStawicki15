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

    //Metody Specjalne!!!
    //Konstruktor domyślny
    ResourceManager()
    {
        resource_ = new Resource{};
    }
    //Konstruktor kopiujący???
    ResourceManager(const ResourceManager& oryginal) : resource_{new Resource{*oryginal.resource_}} {}
    //{std::cout<<"Konstruktor kopiujacy wywolany";}
    //Destruktor
    ~ResourceManager()
    {
        delete resource_;
    }
    //Kopiowanie
    ResourceManager& operator=(const ResourceManager& oryginal)
    {
        if(this == &oryginal)
            return *this;
        
        delete resource_;
        resource_ = new Resource{*oryginal.resource_};
        //std::cout<<"Kopiowanie wywolane";
        return *this;
    }
    //Konstruktor przenoszacy
    ResourceManager(ResourceManager&& oryginal) noexcept
    : resource_{oryginal.resource_}
    {
        oryginal.resource_ = nullptr;
    }
    //Przenoszenie
    ResourceManager& operator=(ResourceManager&& oryginal) noexcept
    {
        if(this != &oryginal)
        {
            delete resource_;
            resource_ = oryginal.resource_;
            oryginal.resource_ = nullptr;
        }
        return *this;
    }
};
