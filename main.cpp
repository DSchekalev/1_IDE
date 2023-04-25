#include <iostream>
#include <fstream>

int* create_array(int size) {
	return new int[size];
}

void fill_arrayIn(int* arr, int size, std::ifstream& fin) {
	for (int i = 0; i < size; ++i) {
		fin >> arr[i];
	}
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	int n, m;
	std::ifstream fin;
	fin.open("in.txt");
	if (!fin.is_open()) {
		std::cout << "Не получилось открыть файл!" << std::endl;
	}
	else {
		fin >> n;
		int* arrN = create_array(n);
		fill_arrayIn(arrN, n, fin);
		fin >> m;
		int* arrM = create_array(m);
		fill_arrayIn(arrM, m, fin);

		std::ofstream fout("out.txt");
		fout << m << std::endl;
		fout << arrM[m - 1] << " ";
		for (int i = 0; i < m - 1; ++i) {
			if (i == m-2) 
				fout << arrM[i];
			else
				fout << arrM[i] << " ";
		}
		fout << std::endl;
		fout << n << std::endl;
		for (int i = 1; i < n; ++i) {
			fout << arrN[i] << " ";
		}
		fout << arrN[0];
		delete[] arrN;
		delete[] arrM;
	}
	fin.close();
	return 0;
}
