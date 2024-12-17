#include "sequence.h"
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>

std::vector<int> generate_random_sequence(int length) {
    std::vector<int> sequence(length);
    for (int i = 0; i < length; ++i) {
        sequence[i] = rand() % 2;
    }
    return sequence;
}

void write_sequence_to_file(const std::string& filename, const std::vector<int>& sequence) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (size_t i = 0; i < sequence.size(); ++i) {
            file << sequence[i];
            if (i != sequence.size() - 1) file << " ";
        }
        file << "\n";
    } else {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
    }
}

std::vector<int> read_sequence_from_file(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<int> sequence;

    if (file.is_open()) {
        std::string line;
        std::getline(file, line);
        std::istringstream stream(line);

        int bit;
        while (stream >> bit) {
            sequence.push_back(bit);
        }
    } else {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
    }

    return sequence;
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    int length1 = 1000;
    int length2 = 1000;

    std::vector<int> seq1 = generate_random_sequence(length1);
    std::vector<int> seq2 = generate_random_sequence(length2);

    std::string file1 = "sample1.txt";
    std::string file2 = "sample2.txt";

    write_sequence_to_file(file1, seq1);
    write_sequence_to_file(file2, seq2);

    std::cout << "Две выборки успешно сгенерированы и сохранены в файлы:" << std::endl;
    std::cout << "Файл 1: " << file1 << " (длина: " << length1 << ")" << std::endl;
    std::cout << "Файл 2: " << file2 << " (длина: " << length2 << ")" << std::endl;

    return 0;
}
