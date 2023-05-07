//HUFFMAN CODING
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// Node for the Huffman tree
struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }

    ~Node() {
        delete left;
        delete right;
    }
};

// Comparison function for priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Build Huffman tree and return root
Node* buildHuffmanTree(string input) {
    unordered_map<char, int> freq;
    for (char c : input) {
        freq[c]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto p : freq) {
        pq.push(new Node(p.first, p.second));
    }

    while (pq.size() != 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    return pq.top();
}

// Traverse Huffman tree and assign codes to characters
void assignCodes(Node* node, string code, unordered_map<char, string>& codes) {
    if (!node) {
        return;
    }

    if (node->data != '$') {
        codes[node->data] = code;
    }

    assignCodes(node->left, code + "0", codes);
    assignCodes(node->right, code + "1", codes);
}

// Compress input using Huffman coding
string compress(string input) {
    string compressed = "";

    // Build Huffman tree
    Node* root = buildHuffmanTree(input);

    // Assign codes to characters
    unordered_map<char, string> codes;
    assignCodes(root, "", codes);

    // Compress input
    for (char c : input) {
        compressed += codes[c];
    }

    return compressed;
}

int main() {
    string input = "Hello, world!";
    string compressed = compress(input);

    cout << "Original: " << input << endl;
    cout << "Compressed: " << compressed << endl;

    return 0;
}