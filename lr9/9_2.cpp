#include <iostream>
#include <cstring>

template <class T>
T getmax(T t1, T t2) {
	return t1 > t2 ? t1 : t2;
}

template <class T>
T getmax(T t[], size_t size) {
	T retval = t[0];
	int i;
	for (i = 0; i < size; i++)
		if (t[i] > retval) retval = t[i];
	return retval;
}

template <>
const char* getmax<const char*>(const char* a, const char* b) {
    return std::strcmp(a, b) > 0 ? a : b;
}

int main() {
	int i1 = 3, i2 = 5;
	int mas[] = { 3, 9, 5, 8 };
	std::cout << "max int = " << getmax(i1, i2) << std::endl;
	std::cout << "max int_array = " << getmax(mas, sizeof(mas) / sizeof(mas[0])) << std::endl;;
	
    const char* s1 = "str_A";
    const char* s2 = "str_B";
    std::cout << "max str=" << getmax(s1, s2) << '\n';

    return 0;
}