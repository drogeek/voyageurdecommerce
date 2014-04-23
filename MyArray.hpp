#ifndef _MYARRAY_H
#define _MYARRAY_H

#include <iostream>
#include <cstdlib>

template<typename T>class MyArray {
	ssize_t len;
	T* content;

public:
	/* Constructeur avec une taille. */
	MyArray(ssize_t _len): len(_len), content(new T[len]) {}

	/* Constructeur vide */
	MyArray(): len(0), content(NULL) {}

	/* Constructeur de recopie */
	MyArray(const MyArray<T>& other): len(other.len) {
		content = new T[len];
		std::copy(other.begin(), other.end(), content);
	}

	/* Destructeur */
	~MyArray(){ if(content) delete[] content; }

	/* Opérateur d'affectation */
	MyArray& operator=(const MyArray& other){
		if(this != &other){
			if(content) delete[] content;
			len = other.len;
			content = new T[len];
			std::copy(other.begin(), other.end(), content);
		} return *this;
	}

	/* opérateur d'indicage */
	T& operator[](int i) const { return content[i]; }

	/* Accesseur de la taille */
	ssize_t size(void) const { return len; }

	/* Itérateurs */
	T* begin(void) const { return content; }
	T* end(void) const { return content+len; }

	/* Itérateurs constants */
	const T*cbegin(void) const { return content; }
	const T* cend(void) const { return content+len; }
};

#endif
