#include "BinTree.h"
#include "Bitmap.h"
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

struct HuffmanNode {
	char ch;          
	int freq;         
	HuffmanNode* left = nullptr;    
	HuffmanNode* right = nullptr;   
	HuffmanNode(char c, int f)
	: ch(c), freq(f) {}
};

struct CompareNodes {
	bool operator()(const HuffmanNode* a, const HuffmanNode* b) const {
		return a->freq > b->freq;
	}
};

HuffmanNode* buildHuffTree(const string& str) {
	unordered_map<char, int> freqMap;
	for (const char c : str) {
		++freqMap[c];
	}
	auto cmp = [](const HuffmanNode* a, const HuffmanNode* b) { return a->freq > b->freq; }; //lambda函数
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, decltype(cmp)> pq(cmp);
	for (const auto& p : freqMap) {
		pq.push(new HuffmanNode(p.first, p.second));
	}
	while (pq.size() > 1) {
		const HuffmanNode* left = pq.top();
		pq.pop();
		const HuffmanNode* right = pq.top();
		pq.pop();
		HuffmanNode* parentNode = new HuffmanNode('\0', left->freq + right->freq);
		parentNode->left = const_cast<HuffmanNode*>(left);
		parentNode->right = const_cast<HuffmanNode*>(right);
		pq.push(parentNode);
	}
	
	return pq.top();
}

void generateCodes(const HuffmanNode* root, const string& code, unordered_map<char, string>& codeMap) {
	if (root == nullptr) {
		return;
	}
	
	if (root->left == nullptr && root->right == nullptr) {
		codeMap[root->ch] = code;
		return;
	}
	
	generateCodes(root->left, code + "0", codeMap);
	generateCodes(root->right, code + "1", codeMap);
}


string huffmanEncode(const string& str, const unordered_map<char, string>& codeMap) 
	{
	string encodedString;
	encodedString.reserve(str.size() * 3);
	for (const char c : str) {
		encodedString += codeMap.at(c);
	}
	return encodedString;
}
int main() {

	string str = "I have a dream that We hold these truths to be self-evident, that all men are created equal.I have a dream that one day on the red hills of Georgia, the sons of former slaves and the sons of former slave owners will be able to sit down together at the table of brotherhood.I have a dream that one day even the state of Mississippi, a state sweltering with the heat of injustice, sweltering with the heat of oppression, will be transformed into an oasis of freedom and justice.I have a dream that my four little children will one day live in a nation where they will not be judged by the color of their skin but by the content of their character.";
	HuffmanNode* root = buildHuffTree(str);
	
	unordered_map<char, string> codeMap;
	generateCodes(root, "", codeMap);
	
	string dream = "dream";
	string dreamCode;
	for (char c : dream) {dreamCode += codeMap[c];}
	cout << "dream：" << dreamCode << endl;
	
	string freedom = "freedom";
	string freedomCode;
	for (char c : freedom) {freedomCode += codeMap[c];}
	cout << "freedom：" << freedomCode << endl;
	
	string encodedStr = huffmanEncode(str, codeMap);
	cout << "I have a dream：" << encodedStr << endl;
	
	return 0;
}
