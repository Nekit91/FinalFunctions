#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
void type_off(int num) {std::cout << "INT\n";}
void type_off(double num) { std::cout << "DOUBLE\n"; }
void type_off(char sym) { std::cout << "CHAR\n"; }
//прототип функции  sum_AB
int sum_AB(int A, int B);

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
template<typename T>
void middle_sort(T arr[], const int length);

//заполнения массива случайными числами 
template<typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
		for (int i = 0; i < length; i++)
			arr[i] = rand() % (right - left) + left;
}

//вывод массива в консоль
template <typename T >
void print_arr(T arr[], const int length) {
	std::cout << " { ";
	for(int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";

}

template<typename T>
void move_arr(T arr[], const int length, int steps);


int main() {
	setlocale(LC_ALL, "RU");
	int n,m;

	//задача 1. число и тип данных
	/*
	std::cout << "Задача 1.\n";
	std::cout << "77 - "; type_off(77);
	std::cout << "5.1 - "; type_off(5.1);
	std::cout << "'A' - "; type_off('A');
	std::cout << std::endl;
	*/

	//задача 2. рекурсивная сумма
	/*
	std::cout << "Задача 2 \nВведите 2 числа -> ";
	std::cin >> n >> m;
	std::cout << "сумма чисел от " << n << " до " << m << " = " << sum_AB(n, m) << "\n\n";
	*/

	//задача 3. сортировка середины
	/*
	std::cout << "задача 3. \nИзначальный массив:\n";
	const int size3 = 10;
	int arr3[size3];
	fill_arr(arr3, size3, -10, 11);
	print_arr(arr3, size3);

	middle_sort(arr3, size3);
	std::cout << "Итоговый массив: \n";
	print_arr(arr3, size3);
	*/

	//Задача 4. сдвиг по кругу
	std::cout << "задача 4\nИзначальный массив:\n";
	const int size4 = 10;
	int arr4[size4]{ 1,2,3,4,5,6,7,8,9,10 };
	print_arr(arr4, size4);
	std::cout << "введите число->";
	std::cin >> n;
	move_arr(arr4, size4, n);
	std::cout << "Итоговый массив: \n";
	print_arr(arr4, size4);





	return 0;
}


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
template<typename T>
void middle_sort(T arr[], const int length) {
	int first_index, last_index;
	//индекс первого отрицательного числа
	for (int i = 0; i < length; i++)
		if (arr[i] < 0) {
			first_index = i;
			break;
		}
	//индекс последнего отрицательного числа
	for(int i=length-1;i>=first_index;i--)
		if (arr[i] < 0) {
			last_index = i;
			break;
		}
	//пузырьковая сортировка 
	/*for (int i = last_index - 1; i > first_index + 1; i--)
		for (int j = first_index+1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
				*/

	//Быстрая сортировка
	std::sort(arr+first_index+1, arr + last_index);
}

//реализация функции sum_AB
int sum_AB(int A, int B) {
	if (A == B)
		return A;
	return sum_AB(A, B - 1)+B;
}

template<typename T>
void move_arr(T arr[], const int length, int steps) {
	if(steps>0)
	for (int i = 0; i < steps; i++) {
		T tmp = arr[length - 1];
		for (int i = length - 1; i >= 1; i--)
			arr[i] = arr[i - 1];
		arr[0] = tmp;
	}

	else {
		for (int i = 0; i > steps; i--) {
			for (int i = 0; i < length - 1; i++) {
				std::swap(arr[i], arr[i + 1]);
			}
		}
	}
		
			



}
