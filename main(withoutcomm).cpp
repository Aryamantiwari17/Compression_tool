#include <iostream>
#include<bits/stdc++.h>
#include <string>
#include <queue>
#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <unistd.h>
#include <stdexcept>
#include <windows.h>
#include <chrono>
#include <stdlib.h>
using namespace std;
const string ERROR_CODES_FILE = "errorCodes.txt";
unordered_map<int, string> load_error_codes() {
    unordered_map<int,string> error_codes;
    ifstream file(ERROR_CODES_FILE);
    
    if (!file.is_open()) {
        cerr << "Error: Could not open error codes file: " << ERROR_CODES_FILE << endl;
        return error_codes;
    }
    string line;
    while (getline(file, line)) {
        if (line[0] == '#' || line.empty()) {
            continue;
        }

        size_t colon_pos = line.find(": ");
        if (colon_pos == string::npos) {
            continue;
        }

        int code = stoi(line.substr(0, colon_pos));
        string description = line.substr(colon_pos + 2);
        error_codes[code] = description;
    }
    file.close();
    return error_codes;
}
const unordered_map<int, string> ERROR_CODES = load_error_codes();


class CompressionAlgorithm
{
   protected:
    string name; 
    float ratio;
    float speed;
public:
    CompressionAlgorithm(string name, float ratio, float speed)
    {
        this->name = name;
        this->ratio = ratio;
        this->speed = speed;
    }

    string getName()
    {
        return name;
    }

    float getCompressionRatio(float originalSize, float compressedSize)
    {
      
        float compressionRatio = originalSize / compressedSize;
   cout << "Compression Ratio: " << compressionRatio << ":1" << endl;
 return compressionRatio;
    }

    float getCompressionSpeed(float fileSize, float duration)
    {
      
        float compressionSpeed = fileSize / (duration / 1000.0); // in MB/s

      
        cout << "Compression Speed: " << compressionSpeed << " MB/s" << endl;

        return compressionSpeed;
    }
};

class FileHandler : public CompressionAlgorithm
{
public:
    int fd1;
    int fd2;

    void openInputFile()
    {
        ifstream inputFile("sample.txt");
        if (!inputFile)
        {
            cerr << "Error: Cannot open input file (" << strerror(errno) << ")" << endl;
            exit(1);
        }

        
    }

    void openOutputFile()
    {
        fd2 = open("sample-compressed.txt");
        if (fd2 == -1)
        {
            cout<<"Error("<<ERROR_CODES.at(101)<<")"<<endl;
            exit(1);
        }
    }

    void closeInputFile()
    {
        close(fd1);
    }

    void closeOutputFile()
    {
        close(fd2);
    }
};

class HuffmanCodingAlgorithm : public CompressionAlgorithm
{
private:
    int size;
    struct Node *MinHeap;

    void heapify(MinHeap &minHeap, int index)
    {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < minHeap.size && minHeap.array[left]->freq < minHeap.array[smallest]->freq)
        {
            smallest = left;
        }

        if (right < minHeap.size && minHeap.array[right]->freq < minHeap.array[smallest]->freq)
        {
            smallest = right;
        }

        if (smallest != index)
        {
           
            Node *temp = minHeap.array[index];
            minHeap.array[index] = minHeap.array[smallest];
            minHeap.array[smallest] = temp;

           
            heapify(minHeap, smallest);
        }
        }
    struct Node
    {
        char character;
        int freq;
        Node *left, *right;

        Node(char c, int f) : character(c), freq(f), left(nullptr), right(nullptr) {}
    }

    struct MinHeap
    {
        int size;
        vector<Node *> array;

        MinHeap(int s) : size(s), array(s) {}
    }

  
    MinHeap *createAndBuildMinHeap(char arr[], int freq[], int unique_size)
    {
        int i;

      
        MinHeap *minHeap = new MinHeap(unique_size);

        
        for (i = 0; i < unique_size; ++i)
        {
            minHeap->array[i] = new Node(arr[i], freq[i]);
        }

        int n = minHeap->size - 1;
        for (i = (n - 1) / 2; i >= 0; --i)
        {
           
            heapify(*minHeap, i);
        }

        return minHeap;
    }

    struct Node *buildHuffmanTree(char arr[], int freq[], int unique_size)
    {
        struct Node *left, *right, *top;

      
        MinHeap *minHeap = createAndBuildMin;

        if (minHeap == nullptr)
        {
            cout<<"Error("<<ERROR_CODES.at(102)<<")"<<endl;
            exit(1);
        }

      
        while (minHeap->size != 1)
        {
            
            left = extractMin(minHeap);
            right = extractMin(minHeap);
            top = new Node('$', left->freq + right->freq);
            top->left = left;
            top->right = right;
            insertMinHeap(minHeap, top);
        }

        return extractMin(minHeap);
    }

public:
 
    void compress(int fd1, int fd2)
    {
        char n;
        int h = 0, i, a = 0;
       
        struct Node *front, *rear,

           
            while (read(fd1, &n, sizeof(char)) == sizeof(char))
        {
            int rear = front;
            while (rear != NULL && rear->k != n)
            {
                rear = rear->p;
            }
            if (rear != NULL && rear->k == n)
            {
                for (i = 0; i < rear->l; i++)
                {
                    if (h < 7)
                    {
                        if (rear->code_arr[i] == 1)
                        {
                            a++;
                            a = a << 1;
                            h++;
                        }
                        else if (rear->code_arr[i] == 0)
                        {
                            a = a << 1;
                            h++;
                        }
                    }
                    else if (h == 7)
                    {
                        if (rear->code_arr[i] == 1)
                        {
                            a++;
                            h = 0;
                        }
                        else
                        {
                            h = 0;
                        }
                        if (fd2 != -1)
                        {
                            write(fd2, &a, sizeof(char));
                        }
                        a = 0;
                    }
                }
            }
        }
        for (i = 0; i < 7 - h; i++)
        {
            a = a << 1;
        }
        if (fd2 != -1)
        {
            write(fd2, &a, sizeof(char));
        }
        cout << "file become compressed" << endl;
    } 

        struct Tree
        {
            char g;
            int len;
            int dec;
            struct Tree *f;
            struct Tree *r;
        } Tree;

      
        void ExtractCodesFromFile(int fd1)
        {
            read(fd1, &t->g, sizeof(char));
            read(fd1, &t->len, sizeof(int));
            read(fd1, &t->dec, sizeof(int));
        }

     
        void ReBuildHuffmanTree(int fd1, int size)
        {
            int i = 0, j, k;
            tree = (Tree *)malloc(sizeof(Tree));
            tree_temp = tree;
            tree->f = NULL;
            tree->r = NULL;
            t = (Tree *)malloc(sizeof(Tree));
            t->f = NULL;
            t->r = NULL;
            for (k = 0; k < size; k++)
            {
                tree_temp = tree;
                ExtractCodesFromFile(fd1);
                int bin[MAX], bin_con[MAX];
                for (i = 0; i < MAX; i++)
                {
                    bin[i] = bin_con[i] = 0;
                }
                convertDecimalToBinary(bin, t->dec, t->len);
                for (i = 0; i < t->len; i++)
                {
                    bin_con[i] = bin[i];
                }

                for (j = 0; j < t->len; j++)
                {
                    if (bin_con[j] == 0)
                    {
                        if (tree_temp->f == NULL)
                        {
                            tree_temp->f = (Tree *)malloc(sizeof(Tree));
                        }
                        tree_temp = tree_temp->f;
                    }
                    else if (bin_con[j] == 1)
                    {
                        if (tree_temp->r == NULL)
                        {
                            tree_temp->r = (Tree *)malloc(sizeof(Tree));
                        }
                        tree_temp = tree_temp->r;
                    }
                }
                tree_temp->g = t->g;
                tree_temp->len = t->len;
                tree_temp->dec = t->dec;
                tree_temp->f = NULL;
                tree_temp->r = NULL;
                tree_temp = tree;
            }
        }
      
    }
void decompress(int fd1, int fd2)
    {
        int count, i;
        char c;
        int size = 0;
        
        struct Node *data,*front, *rear;
         read(fd1, &size, sizeof(int));
        cout<<"\nSize of data read from file :"<<size;

        if (size <= 0)
        {
            cout<<"Error("<<ERROR_CODES.at(103)<<")"<<endl;
            exit(1);
        }
        data = (*code)malloc(sizeof(code));

        if (data == nullptr)
        {
            throw std::runtime_error("Failed to allocate memory.");
        }

        front = rear;
        rear = NULL;
        while (size)
        {
            data->l = data->k = data->code_arr[0] = data->code_arr[1] = data->code_arr[2] = data->code_arr[3] = data->code_arr[4] = data->code_arr[5] = data->code_arr[6] read(fd1, &c, sizeof(char));
            read(fd1, &count, sizeof(int));
            read(fd1, &data->dec, sizeof(int));
            data->p = NULL;
            for (i = count - 1; i >= 0; i--)
            {
                data->code_arr[i] = data->dec % 2;
                data->dec /= 2;
            }
            data->k = c;
            data->l = count;
            if (front == NULL)
            {
                front = rear = data;
            }
            else
            {
                rear->p = data;
                rear = rear->p;
            }
            size -= (sizeof(char) + sizeof(int) + sizeof(int));
        }
        i = 0;
        while (size != originalSize)
        {
            p = root;
            while (p != NULL)
            {
                if (i == front->l)
                {
                    break;
                }
                if (front->code_arr[i] == 0)
                {
                    p = p->l;
                }
                else
                {
                    p = p->r;
                }
                i++;
            }
            write(fd2, &p->c, sizeof(char));
            front->l--;
            if (front->l == 0)
            {
                front = front->p;
                i = 0;
            }
            size += sizeof(char);
        }
        cout<<"File has been decompressed successfully"<<endl;
    }
};
int main()
{
    string name;
    float ratio, speed;
    cout << "Enter name of the compression algorithm: ";
    cin >> name;
    cout << "Enter compression ratio: ";
    cin >> ratio;
    cout << "Enter compression speed: ";
    cin >> speed;
    CompressionAlgorithm *algo = new CompressionAlgorithm(name, ratio, speed);
    algo->getName();
    algo->getCompressionRatio();
    algo->getCompressionSpeed();

  
    int fd1, fd2;
    openfile obj;
    try
    {
        obj.read();
        obj.write();
        fd1 = obj.fd1;
        fd2 = obj.fd2;
    }
    catch(const char* msg)
    {
        cerr << msg << endl;
        return 1;
    }

    struct stat fileStat;
    if (fstat(fd1, &fileStat) < 0)
    {
        cerr << "Failed to get file size" << endl;
        return 1;
    }

   
    int originalSize = fileStat.st_size;

   
    try
    {
        algo->compress(fd1, fd2, originalSize);
    }
    catch(const char* msg)
    {
        cerr << msg << endl;
        return 1;
    }
    try
    {
        obj.read();
        obj.write();
        obj.decompress(fd1, fd2);
    }
    catch(const char* msg)
    {
        cerr << msg << endl;
        return 1;
    }

    return 0;
}
