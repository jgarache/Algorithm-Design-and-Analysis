#include <bits/stdc++.h>
using namespace std;

string a,b,c,d,e,f;		//global variables that are edited for printing purposes
 
// A Huffman tree node
struct MinHeapNode
{
    char data;                // One of the input characters
    unsigned freq;             // Frequency of the character
    MinHeapNode *left, *right; // Left and right child
 
    MinHeapNode(char data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};
 
// For comparison of two heap nodes (needed in min heap)
struct compare
{
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};
 
// Prints huffman codes from the root of Huffman Tree.
void printCodes(struct MinHeapNode* root, string str)
{
    if (!root)
        return;

    // When the data of the node matches the character, add it to the variable string
 
    if (root->data == 'A')
         a += "A:" + str;

    if (root->data == 'B')
        b += "B:" + str;

    if (root->data == 'C')
        c += "C:" + str;

    if (root->data == 'D')
        d += "D:" + str;

    if (root->data == 'E')
        e += "E:" + str;

    if (root->data == 'F')
        f += "F:" + str;

 
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}
 
// Builds a Huffman Tree and print codes by traversing the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;
 
    // Create a min heap & inserts all characters of data[]
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));
 
    // Iterate while tree exists
    while (minHeap.size() != 1)
    {
        // Extract the two minimum freq items from min heap
        left = minHeap.top();
        minHeap.pop();
 
        right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with frequency equal to the sum of the two nodes
        top = new MinHeapNode(' ', left->freq + right->freq);
        
        // Make the two extracted node as left and right children of this new node. 
        top->left = left;
        top->right = right;
        
        // Add this node to the min heap
        minHeap.push(top);
    }
 
    // Print Huffman codes using the Huffman tree built above
    printCodes(minHeap.top(), "");
}
 
int main()
{
    char arr[] = { 'A', 'B', 'C', 'D', 'E', 'F' };

    int freq[6];

    int size = sizeof(arr) / sizeof(arr[0]);

    for(int i =0; i< 6; i++){
        cin >> freq[i];
    }
 
    HuffmanCodes(arr, freq, size);

    //Prints the value of the nodes and their strings in alphabetical order

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << f << endl;

    return 0;
}