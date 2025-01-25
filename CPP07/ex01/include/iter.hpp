#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T* arr, std::size_t len, void (*f)(const T&)){
	for (size_t i = 0; i < len; i++){
		f(arr[i]);
	}
}

template <typename T, typename F>
void iter(T* arr, std::size_t len, void (*f)(const F&)){
	for (size_t i = 0; i < len; i++){
		f(arr[i]);
	}
}

template <typename T>
void func(const T& x){
	std::cout << x << std::endl;
}

#endif
