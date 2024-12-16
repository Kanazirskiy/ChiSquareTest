#include "chi_square.h"
#include <iostream>
#include <cstdlib>
#include <map>
#include <fstream>

using namespace std;
// Функция для получения порогового значения хи-квадрат
double get_chi_square_threshold(double alpha) {
    std::map<double, double> chi_square_thresholds = {
        {0.01, 6.635}, // Порог для уровня значимости 0.01
        {0.05, 3.841}, // Порог для уровня значимости 0.05
        {0.1, 2.706}   // Порог для уровня значимости 0.1
    };

    if (chi_square_thresholds.find(alpha) != chi_square_thresholds.end()) {
        return chi_square_thresholds[alpha];
    } else {
        cerr << "Неподдерживаемый уровень значимости: " << alpha << '\n';
        exit(1); // Завершить выполнение программы
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3 && argc != 4) {
        cerr << "Использование: ./stattest file1.txt [file2.txt] alpha\n";
        return 1;
    }

    string file1 = argv[1];
    string file2;
    double alpha;
    vector<int> seq1, seq2;

    // Если переданы 3 аргумента — одна выборка и уровень значимости
    if (argc == 3) {
        alpha = atof(argv[2]);

        fstream input_file1(file1, ios::in);
        if (!input_file1.is_open()) {
            cerr << "Не удалось открыть файл: " << file1 << '\n';
            return 1;
        }

        int value;
        while (input_file1 >> value) seq1.push_back(value);
        input_file1.close();

        // Проверка выборки с равномерным распределением
        double threshold = get_chi_square_threshold(alpha);
        double chi2_one_sample = chi_square(seq1);

        cout << "Хи-квадрат для одной выборки: " << chi2_one_sample << endl;
        if (chi2_one_sample <= threshold)
            cout << "Гипотеза об однородности выборки принимается\n";
        else
            cout << "Гипотеза об однородности выборки не принимается\n";
    }
    // Если переданы 4 аргумента — две выборки и уровень значимости
    else if (argc == 4) {
        file2 = argv[2];
        alpha = atof(argv[3]);

        fstream input_file1(file1, ios::in), input_file2(file2, ios::in);
        if (!input_file1.is_open() || !input_file2.is_open()) {
            cerr << "Не удалось открыть один из файлов: " << file1 << ", " << file2 << '\n';
            return 1;
        }

        int value;
        while (input_file1 >> value) seq1.push_back(value);
        while (input_file2 >> value) seq2.push_back(value);
        input_file1.close();
        input_file2.close();

        double threshold = get_chi_square_threshold(alpha);
        double chi2_two_samples = chi_square(seq1, seq2);
        cout << "Хи-квадрат для двух выборок: " << chi2_two_samples << endl;
        if (chi2_two_samples <= threshold)
            cout << "Гипотеза об однородности выборок принимается\n";
        else
            cout << "Гипотеза об однородности выборок не принимается\n";
    }

    return 0;
}
