#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class HuffmanCode {
public: 
    static unordered_map<char, string> make_codes(const string& s) {
        auto node = make_node(s); 
        unordered_map<char, string> ret;
        _make_codes(node, "", ret);
        return ret;
    }
    
private:
    class HuffmanNode {
    public:
        HuffmanNode(char data, unsigned int freq)
        :data(data), freq(freq), left(nullptr), right(nullptr) {} 
        HuffmanNode(char data, unsigned int freq, unique_ptr<HuffmanNode> left, 
            unique_ptr<HuffmanNode> right) 
        :data(data), freq(freq), left(move(left)), right(move(right)) {} 
        char data;
        unsigned int freq;
        unique_ptr<HuffmanNode> left, right;
    };

    static unique_ptr<HuffmanNode> make_node(const string& s) {
        unordered_map<char, unsigned int> mp;
        for (char s1 : s) mp[s1]++;

        vector<unique_ptr<HuffmanNode>> heap;
        for (auto& p : mp) {
            auto node = make_unique<HuffmanNode>(p.first, p.second);
            heap.push_back(move(node));
        }
        while (heap.size() > 1) {
            sort(heap.begin(), heap.end(), [](auto& l, auto& r){return l->freq > r->freq;});
            auto left = move(heap.back()); heap.pop_back();
            auto right = move(heap.back()); heap.pop_back();
            auto top = make_unique<HuffmanNode>('$', left->freq + right->freq,
                            move(left), move(right)); 
            heap.push_back(move(top));
        }
        return move(heap.front());
    };

    static void _make_codes(unique_ptr<HuffmanNode>& node, const string& str, unordered_map<char, string>& ret) {
        if (!node.get()) return;
        char d = node->data;
        if (d != '$') ret[d] = str;
        _make_codes(node->left, str + '0', ret);
        _make_codes(node->right, str + '1', ret);
    }
};

int main() {
    // https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
   char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
   int freq[] = { 5, 9, 12, 13, 16, 45 };
   string s = "";
   for (int i = 0; i < 6; ++i) {
       for (int j = 0; j < freq[i]; ++j) s += arr[i];
   }
   auto mp = HuffmanCode::make_codes(s);
   for(auto& p : mp) {
       cout << p.first << "," << p.second << endl;
   } 
   return 0;
}