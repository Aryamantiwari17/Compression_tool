#include <bits/stdc++.h>

using namespace std;
//TIME OF A COMUTATION COMPRESSED/DECOMPRESSED FILE CODE IS WRIITEN BY 211132-DEEP SHEKHAR
class ComputationTimer
{
public:
    chrono::high_resolution_clock::time_point start_time_;
    chrono::high_resolution_clock::time_point end_time_;
    chrono::milliseconds elapsed_time_;

    void start()
    {
        start_time_ = chrono::high_resolution_clock::now();
    }

    void stop()
    {
        end_time_ = chrono::high_resolution_clock::now();
        elapsed_time_ = chrono::duration_cast<chrono::milliseconds>(end_time_ - start_time_);
    }

    void printResult()
    {
        cout << "Computation took " << elapsed_time_.count() << " milliseconds." << endl;
    }

    double calculateCompressionRatio(int original_size, int compressed_size)
    {
        return static_cast<double>(compressed_size) / original_size;
    }

    double calculateCompressionSpeed(int original_size, int compressed_size, int elapsed_time)
    {
        int bytes_processed = original_size - compressed_size;
        double bytes_per_millisecond = static_cast<double>(bytes_processed) / elapsed_time;
        return bytes_per_millisecond;
    }

    int getFileSize(const char *filename)
    {
        ifstream file(filename, ios::binary | ios::ate);
        int size = file.tellg();
        file.close();
        return size;
    }
};

int main()
{
    ComputationTimer timer;
    timer.start();

    // Do some computation
    int sum = 0;

    for (int i = 0; i < 100000000; i++)
    {
        sum += i;
    }

    timer.stop();
    timer.printResult();

    // Get file sizes
    const char *original_filename = "original_file.txt";
    const char *compressed_filename = "compressed_file.txt";
    int original_file_size = timer.getFileSize(original_filename);
    int compressed_file_size = timer.getFileSize(compressed_filename);

    double compression_ratio = timer.calculateCompressionRatio(original_file_size, compressed_file_size);

    cout << "Compression ratio: " << compression_ratio << endl;

    cout << "Original file size: " << original_file_size << " bytes" << endl;
    cout << "Compressed file size: " << compressed_file_size << " bytes" << endl;

    // Calculate compression speed
    double compression_speed = timer.calculateCompressionSpeed(original_file_size, compressed_file_size, timer.elapsed_time_.count());
    cout << "Compression speed: " << compression_speed << " bytes per millisecond" << endl;

    return 0;
}
