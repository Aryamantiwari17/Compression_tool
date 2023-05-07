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
#include <stdlib.h>
#include "211132.h"
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//error handle by 211112-AAMYA CHAUHAN
const string ERROR_CODES_FILE = "errorCodes.txt"; // ERROR_CODES_FILE a file that contains error codes and their descriptions,
 a function load_error_codes() //that reads these error codes from the file and stores them in an unordered map.
unordered_map<int, string> load_error_codes()
 { // The load_error_codes() function initializes an empty unordered_map<int,string> called error_codes.
     unordered_map<int, string> error_codes;
     ifstream file(ERROR_CODES_FILE);
//error handling starts here
     if (!file.is_open())//file is open
     {
         cerr << "Error: Could not open error codes file: " << ERROR_CODES_FILE << endl;
         return error_codes;
     }
     string line;
     while (getline(file, line))
     {
         if (line[0] == '#' || line.empty())
         {
             continue;
         }

         size_t colon_pos = line.find(": ");
         if (colon_pos == string::npos)
         {
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Algo wriitten by 211130-Aryaman-Tiwari--------------------------------------------------------------------------------------
class CCCompressionAlgorithm//make 
{
    // we make a BASE CLASS named as CCompressionAlgorithm
 public:
     string name; // these are private data members
     with acurate naming convention float fratio;
     float speed;

CCompressionAlgorithm(string name, float ratio, float speed) //(constructed )
     {
         this->fratio = ratio;// the member variables of the instance
             this->fspeed = speed;//Speed of the compressed file

    string getName()
    {
        return strname;
    }
};

class CFileHandler : public CCCCompressionAlgorithm//MAKING A CLASS WHERE WE OPEN AND WRITING THE TEXT FILE INCLUDING ITS FILE PATH ALSO 
{
public:
    int fd1;//file descriptors
    int fd2;//file descriptors

    void openInputFile()
    {
        ifstream inputFile("C:\Users\ARYAMAN TIWARI\Dropbox\PC\Desktop\COMPRESSION TOOL\Sample.txt.txt");//text file
        if (!inputFile)
        {
            cerr << "Error: Cannot open input file (" << strerror(errno) << ")" << endl;
            exit(1);
        }

        // Use the input file stream object (inputFile) to read from the file.
    }

    void openOutputFile()
    {
        fd2 = open("C:\Users\ARYAMAN TIWARI\Dropbox\PC\Desktop\COMPRESSION TOOL\Sample.txt.zip");//compressed text file
        if (fd2 == -1)
        {
            cout<<"Error("<<ERROR_CODES.at(101)<<")"<<endl;
            exit(1);
        }
    }

    void closeInputFile()//close the output file
    {
        close(fd1);
    }

    void closeOutputFile()
    {
        close(fd2);//close the output file
    }
};

class CHuffmanCodingAlgorithm : public CCCompressionAlgorithm//Now the algo implementation
{ // making a derived class CHuffmanCodingAlgorithm to implement the algo
private:
    int isize;
    struct Node *MinHeap;

    void heapify(MinHeap &minHeap, int index)//First we implement a function to heapify the node which we intilliaze
    {
        int ismallest = index;//index which will be heapified
        int ileft = 2 * index + 1;//place of left least node place
        int iright = 2 * in // place of right least node place
    
        if (left < minHeap.size && minHeap.array[left]->freq < minHeap.array[smallest]->freq)
        {
            smallest = left;
        }

        if (right < minHeap.size && minHeap.array[right]->freq < minHeap.array[smallest]->freq)
        {
            smallest = right;
        }

        if (smallest != index)//main heapification take place by replacing minimum node into root node and
                              // heap from the tree 
        {
            // Swap the nodes at index and smallest
            Node *temp = minHeap.array[index];
            minHeap.array[index] = minHeap.array[smallest];
            minHeap.array[smallest] = temp;

            // Recursively heapify the affected subtree
            heapify(minHeap, smallest);
        }
    }
    struct Node
    {
        char ccharacter;
        int ifreq;
        Node *pleft, *pright;

        Node(char c, int f) : character(c), freq(f), left(nullptr), right(nullptr) {}
    }

    struct MinHeap
    {
        int isize;
        vector<Node *> array;

        MinHeap(int s) : size(s), array(s) {}
    }

    // Function to create min heap
    MinHeap *createAndBuildMinHeap(char arr[], int freq[], int unique_size)
    {
        int i;

        // Initializing heap
        MinHeap *minHeap = new MinHeap(unique_size);

        // Initializing the array of pointers in min heap.
        // Pointers pointing to new nodes of character
        // and their frequency
        for (i = 0; i < unique_size; ++i)
        {
            minHeap->array[i] = new Node(arr[i], freq[i]);
        }

        int n = minHeap->size - 1;
        for (i = (n - 1) / 2; i >= 0; --i)
        {
            // Standard function for Heap creation
            heapify(*minHeap, i);
        }

        return minHeap;
    }

    struct Node *buildHuffmanTree(char arr[], int freq[], int unique_size)
    {
        struct Node *pleft, *pright, *ptop;

        // Create a min heap of capacity equal to size. Initially, there are modes equal to size.
        MinHeap *minHeap = createAndBuildMin;

        if (minHeap == nullptr)
        {
            cout<<"Error("<<ERROR_CODES.at(102)<<")"<<endl;
            exit(1);
        }

        // Construct Huffman tree
        while (minHeap->isize != 1)
        {
            // Extract the two minimum frequency items from min heap
            left = extractMin(minHeap);
            right = extractMin(minHeap);

            // Create a new internal node with frequency equal to the
            // sum of the two nodes' frequencies. Make the two extracted
            // node as left and right children of this new node. Add
            // this node to the min heap
            top = new Node('$', left->freq + right->freq);
            top->left = left;
            top->right = right;
            insertMinHeap(minHeap, top);
        }

        // The remaining node is the root node and the tree is complete.
        return extractMin(minHeap);
    }

public:
    // Function to compress the file
    void compress(int fd1, int fd2)
    {
        char cn;
        int ih = 0, i, a = 0;
       
        struct Node *ifront, *irear;

        *pirear,

            while (read(fd1, &n, sizeof(char)) == sizeof(char))//reads the input file specified by fd1 character by character, compresses it using the algorithm.
            
        {
            int iirear = iifront;
            while (irear != NULL && irear->k != n)//encoding each character in the input file
            {
                irear = irear->p;
            }
            if (irear != NULL && irear->k == n)
            {
                for (i = 0; i < irear->l; i++)
                {
                    if (h < 7)
                    {
                        if (irear->code_arr[i] == 1)
                        {
                            a++; // a variable a to store the compressed bits temporarily and
                                 // writes them into the output file once it reaches a full byte
                            a = a << 1;
                            h++;
                        }
                        else if (irear->code_arr[i] == 0)
                        {
                            a = a << 1;
                            h++;
                        }
                    }
                    else if (h == 7)
                    {
                        if (irear->code_arr[i] == 1)
                        {
                            a++;
                            h = 0;
                        }
                        else
                        {
                            h = 0;
                        }
                        if (fd2 != -1) // doesn't write the compressed output to a file. Instead, 
                        //it just compresses the input file and discards the output.
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
            write(fd2, &a, sizeof(char)); // The compressed output is written into a new file specified by fd2.
        }
        cout << "file become compressed" << endl;//print that file been compressed
    } // end compress function

        struct Tree
        {
        char cg; // the value at a given node
        int ilen; // the length of the code for the given character
        int idec; // decimal value of the code for the given character
        struct Tree *pf;//pointer_left child
        struct Tree *pr;//pointer_right child
        } Tree;

        // Function to extract Huffman codes
        // from a compressed file
        void ExtractCodesFromFile(int fd1) // It takes an integer fd1 as input, 
                                          //which is a file descriptor representing the file being read.
        {
            read(fd1, &t->g, sizeof(char));
            read(fd1, &t->len, sizeof(int));
            read(fd1, &t->dec, sizeof(int));
        }

        // Function to rebuild the Huffman tree
        void ReBuildHuffmanTree(int fd1, int size)
        { // function starts by allocating memory for the Huffman tree using malloc. 
        //It then sets the f and r pointers for the root node of the tree to NULL.
        // It also initializes a new Tree node t using malloc, and sets its f and r pointers to NULL.
            int i = 0, j, k;
            tree = (Tree *)malloc(sizeof(Tree));
            tree_temp = tree;
            tree->f = NULL;
            tree->r = NULL;
            t = (Tree *)malloc(sizeof(Tree));
            t->f = NULL;
            t->r = NULL;
            for (k = 0; k < isize; k++)
            {
                tree_temp = tree;
                ExtractCodesFromFile(fd1); // read the Huffman code for a given character from the compressed file.
                int bin[MAX], bin_con[MAX];
                for (i = 0; i < MAX; i++)
                {
                    bin[i] = bin_con[i] = 0;
                }
                convertDecimalToBinary(bin, t->dec, t->len); // initializes two integer arrays bin and bin_con of size MAX to 0 using a loop. 
                //It then calls a helper function called convertDecimalToBinary, which takes the bin array, the decimal value of the code (t->dec), and the length of the code (t->len) as arguments. 
                //This function converts the decimal value of the code to its binary representation and stores it in the bin array.
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
                tree_temp->g = t->g; // tree_temp back to the root of the Huffman tree, 
                //and continues the loop to process the codes for the remaining characters in the compressed file.
                tree_temp->len = t->len;
                tree_temp->dec = t->dec;
                tree_temp->f = NULL;
                tree_temp->r = NULL;
                tree_temp = tree;
            }
        }
        // Implementation omitted for brevity
        // ...
    }

    // Function to decompress the file
    void decompress(int fd1, int fd2)
    {
            int ccount, i; // encode the character, length of the encoded value
            char c;        // the number of bits
            int isize = 0;

            struct Node *data, *ifront, *irear;
            read(fd1, &isize, sizeof(int));
            cout << "\nSize of data read from file :" << isize; // store the size of the compressed data read from the input file.

            if (size <= 0) // checks if the size is less than or equal to 0. If the size is less than or equal to 0,
            // it prints an error message using the ERROR_CODES map and exits the program with an error code of 1.
            {
                cout << "Error(" << ERROR_CODES.at(103) << ")" << endl;
                exit(1);
        }
        data = (*code)malloc(sizeof(code));

        if (data == nullptr)
        {
            throw std::runtime_error("Failed to allocate memory.");
        }

        ifront = irear; // pointers are used to keep track of the front and rear of a queue-like structure of Node structs.
        irear = NULL;
        while (isize)
        { // compressed data has been read from the input file and added to the queue, the function enters a loop to decode the data.
            data->l = data->k = data->code_arr[0] = data->code_arr[1] = data->code_arr[2] = data->code_arr[3] = data->code_arr[4] = data->code_arr[5] = data->code_arr[6] read(fd1, &c, sizeof(char));
            read(fd1, &count, sizeof(int));
            read(fd1, &data->dec, sizeof(int)); //encoded value
            data->p = NULL;
            for (i = count - 1; i >= 0; i--)
            {
                data->code_arr[i] = data->dec % 2;
                data->dec /= 2;
            }
            data->k = c;
            data->l = count;
            // traverses the Huffman tree using the 0 and 1 bits in the code_arr array of the ifront Node struct. 
            //updates the p pointer by following the left branch if the current bit is 0 and the right branch if the current bit is 1
            if (ifront == NULL)
            {
                ifront = irear = data;
            }
            else
            {
                irear->p = data;
                irear = irear->p;
            }
            size -= (sizeof(char) + sizeof(int) + sizeof(int));
        }
        i = 0;
        while (size != originalSize)
        {
            // the length of the encoded value l in the ifront Node struct is decremented.
            //  the length of l reaches 0, the ifront pointer is moved to the next Node struct in the queue, and i is reset to 0.
            p = root;
            while (p != NULL)
            {
                if (i == ifront->l)
                {
                    break;
                }
                if (ifront->code_arr[i] == 0)
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
            ifront->l--;
            // he output file until the size of the output file matches the original size of the uncompressed data.
            if (ifront->l == 0)
            {
                ifront = ifront->p;
                i = 0;
            }
            size += sizeof(char);
        }
        cout << "File has been decompressed successfully" << endl; // prints a success message to the console.
    }
};
//----------------------------------------------------------------------------------------------------------------------------------
int main()
{
   // Building the main function-Written By 211130-AryamanTiwari
    string strname;
    cout << "Enter name of the compression string:";
    cin >> strname;
    timer.start();//.................CALCULATING THE TIME-211132.(DEEP SHEKHAR)..............
    CCCompressionAlgorithm *algo = new CCCompressionAlgorithm(strname);
    algo->getName();
    timer.stop();
    timer.getTime();
    const char *original_filename = "C:\Users\ARYAMAN TIWARI\Dropbox\PC\Desktop\COMPRESSION TOOL\Sample.txt.txt";
    const char *compressed_filename = "C :\Users\ARYAMAN TIWARI\Dropbox\PC\Desktop\COMPRESSION TOOL\Sample.txt.zip ";
    int original_file_size = timer.getFileSize(original_filename);
    int compressed_file_size = timer.getFileSize(compressed_filename);

    double compression_ratio = timer.calculateCompressionRatio(original_file_size, compressed_file_size);

    cout << "Compression ratio: " << compression_ratio << endl;

    cout << "Original file size: " << original_file_size << " bytes" << endl;
    cout << "Compressed file size: " << compressed_file_size << " bytes" << endl;

    // Calculate compression speed
    double compression_speed = timer.calculateCompressionSpeed(original_file_size, compressed_file_size, timer.elapsed_time_.count());
    cout << "Compression speed: " << compression_speed << " bytes per millisecond" << endl;
    //-----------------------------------------------------------------------------------------------------------------------------------------
    // Code to error handling the compress file-Wriiten By 211112-AAMYA CHAUHAN----------------------------------------------
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

    // Save original file size
    int originalSize = fileStat.st_size;

    // Compress the file using the chosen algorithm
    try
    {
        algo->compress(fd1, fd2, originalSize);
    }
    catch(const char* msg)
    {
        cerr << msg << endl;
        return 1;
    }

    // Decompress the file using the chosen algorithm
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
    //-------------------------------------------------------------------------------------------------------------------------------------------------------
}
