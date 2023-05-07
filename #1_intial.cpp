#include <iostream>
#include <string>
using namespace std; 
class CompressionAlgorithm { 
    private: string name; 
    float ratio; 
    float speed; 
    public: CompressionAlgorithm(string name, float ratio, float speed) 
    { this->name = name; 
    this->ratio = ratio; 
    this->speed = speed; } 
    string getName() {
        return name; 
        
    }
    float getCompressionRatio() { 
        return ratio;
        } 
        float getCompressionSpeed() { 
            return speed;
            } 
    
}; 
int main()
{ 
    CompressionAlgorithm gzip("gzip", 0.7, 1000.0);
    cout << "Name: " << gzip.getName() << endl;
    cout << "Compression Ratio: " << gzip.getCompressionRatio() << endl; 
    cout << "Compression Speed: " << gzip.getCompressionSpeed() << " bytes/s" << endl;
    return 0;
}