#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>

template <typename T>
class BinTree {
public:
	struct TreeNode {
		T data;
		TreeNode* left;
		TreeNode* right;
		TreeNode(T d) : data(d), left(nullptr), right(nullptr) {}
	};
	
	BinTree() : root(nullptr) {}
	~BinTree() { clear(root); }
	void clear() { clear(root); root = nullptr; }
	bool empty() const { return root == nullptr; }
	void insert(const T& data) { insert(root, data); }
	
	template <typename Func>
	void traverse(Func visit) const { traverse(root, visit); }
	
protected:
	TreeNode* root;
	
	void clear(TreeNode* node) {
		if (node == nullptr) {
			return;
		}
		clear(node->left);
		clear(node->right);
		delete node;
	}
	
	void insert(TreeNode*& node, const T& data) {
		if (node == nullptr) {
			node = new TreeNode(data);
			return;
		}
		if (data < node->data) {
			insert(node->left, data);
		}
		else {
			insert(node->right, data);
		}
	}
	
	template <typename Func>
	void traverse(TreeNode* node, Func visit) const {
		if (node == nullptr) {
			return;
		}
		visit(node->data);
		traverse(node->left, visit);
		traverse(node->right, visit);
	}
};

#endif
