#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <typeinfo>
#include <array>
#include <iostream>
#include <tuple>
#include <algorithm>

namespace cs540{
    template <typename T, size_t I, size_t... Js>
    class Array{
    public:
        typedef T ValueType;
        using Nested = typename Array<T, Js...>::type;
        using type = std::array<Nested, I>;
        type arr;

        Array(){}

        Array(const Array& o){
            if (typeid(arr) == typeid(o.arr)){
                arr = o.arr;
            }
        }

/*
        template <typename U, size_t... Dims>
        Array(const Array<U, Dims...> &){
            std::cout << "???" << std::endl;
            if (std::make_tuple(Dims...) == std::tuple_cat(std::make_tuple(I), std::make_tuple(Js...))){
                std::cout << "same dimensionality\n";
            }
        }
*/

        decltype(arr[0])& operator[](int index){
            return arr[index];
        }

        const decltype(arr[0])& operator[](int index) const{
            return arr[index];
        }

    };

    template<typename T, size_t I>
    class Array<T, I>{
    public:
        typedef T ValueType;
        using type = std::array<T, I>;
        type arr;

        Array(){}


        Array(const Array& o){
            if (typeid(arr) == typeid(o.arr)){
                arr = o.arr;
            }
        }

        /*
        template <typename U, size_t... Dims>
        Array(const Array<U, Dims...> &o){
            std::cout << "U version" << std::endl;
            if (std::make_tuple(Dims...) == std::make_tuple(I)){
            }
        }
        */

        int& operator[](int index){
            return arr[index];
        }

        const int& operator[](int index) const{
            return arr[index];
        }

    };

    /*
    Array<int, 3, 4, 5>
        Nested = typename Array<int, 4, 5>::type; //array<array<int,5>, 4>
        type = std::array<Nested, 3>  //array<array<array<int,5>, 4>, 3>
    Array<int, 4, 5>
        Nested = typename Array<int, 5>::type;  //array<int, 5>
        type = std::array<Nested, 4>            //array<array<int,5>, 4>
    Array<int, 5>
        type = std::array<int, 5>
    */






    class OutOfRange{

    };
}

#endif
