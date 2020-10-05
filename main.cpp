#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
#include <vector>       // std::vector

int main(int argc, char *argv[], char *envp[])
{
    size_t size = 0;
    std::cout << "Choose the amount of ram to fill (in MB)" << std::endl;
    std::cin >> size;
    // Convert to MB
    size = size * 1000000;
    std::vector<char> &&fill = std::vector<char>(size, 0);

    // Remove scientific display (1e-15), set precision to 3 nbrs after comma, display RAM. 
    std::cout << "Choose to fill:" << std::fixed << std::setprecision(3) << sizeof(std::vector<char>) + (sizeof(char) * fill.size()) / 1000000.0f << "Mo" << std::endl;
    std::cout << "Press anykey to exit and free memory :)" << std::endl;
    std::cin.ignore();
    std::cin.get();
    
    // Remove all object
    fill.clear();
    // Free unused memory
    fill.shrink_to_fit();
    return 0;
} 
