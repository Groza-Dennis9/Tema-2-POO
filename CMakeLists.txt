cmake_minimum_required(VERSION 4.1)
project(Tema_2_POO)

set(CMAKE_CXX_STANDARD 14)

add_executable(Tema_2_POO
        Tema_2.cpp
        Ingredients.cpp
        Ingredients.h
        Customer.cpp
        Customer.h
        Product.cpp
        Product.h
        ShopManager.cpp
        ShopManager.h
        MenuSystem.cpp
        MenuSystem.h)
