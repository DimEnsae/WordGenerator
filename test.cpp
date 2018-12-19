#include <iostream>
#include <vector>


int main() {
    
    
    std::vector<int> T1;
    for (int i=0; i<3; i++) {T1.push_back(i); }
    for (int i=0; i<3; i++) {std::cout << T1[i] << std::endl;}
    std::vector<int> T2;
    for (int i=1; i<4; i++) {T2.push_back(i); }
    std::cout << (T1==T2) << std::endl;
    
    
    
    return 0;
}

