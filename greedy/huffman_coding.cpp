#include <bits/stdc++.h>
using namespace std;

struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;
    HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) { return a->freq > b->freq; }
};

void generateCodes(HuffmanNode* root, const string& code, unordered_map<char, string>& codes) {
    if (!root) return;
    if (!root->left && !root->right) codes[root->ch] = code;
    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

unordered_map<char, string> huffmanCoding(const string& text) {
    unordered_map<char, int> freq;
    for (char c : text) freq[c]++;
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
    for (auto& kv : freq) pq.push(new HuffmanNode(kv.first, kv.second));
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();
        HuffmanNode* parent = new HuffmanNode('\0', left->freq + right->freq);
        parent->left = left; parent->right = right;
        pq.push(parent);
    }
    unordered_map<char, string> codes;
    generateCodes(pq.top(), "", codes);
    return codes;
}

int main() {
    string text = "abracadabra";
    auto codes = huffmanCoding(text);
    for (const auto& kv : codes) cout << kv.first << ": " << kv.second << "\n";
    return 0;
}