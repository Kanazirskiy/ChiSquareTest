#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <vector>
#include <string>

std::vector<int> generate_random_sequence(int length);
void write_sequence_to_file(const std::string& filename, const std::vector<int>& sequence);
std::vector<int> read_sequence_from_file(const std::string& filename);

#endif // SEQUENCE_H
