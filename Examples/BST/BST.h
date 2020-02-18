#ifndef BINARYTREE_H
#define BINARYTREE_H

template <class Key, class Value>
class BinaryTree
{
public:
	class Node
	{
		friend class BinaryTree;

		Key key;
		Value value;
		Node *left, *right;

		Node(const Key& key, const Value& value)
		: key(key), value(value), left(NULL), right(NULL)
		{
		}

		~Node()
		{
			// delete children recursively
			if (left)
				delete left;
			if (right)
				delete right;
		}

	public:

		const Key& getKey() const
		{
			return key;
		}

		const Value& getValue() const
		{
			return value;
		}

		Value& getValue()
		{
			return value;
		}
	};

private:

	Node *root;

public:

	BinaryTree()
	: root(NULL)
	{
	}

	~BinaryTree()
	{
		clear();
	}

	void clear()
	{
		delete root;
		root = NULL;
	}

	void insert(const Key& key, const Value& value)
	{
		insert(root, new Node(key, value));
	}

	Node *find(const Key& key)
	{
		find(key, root);
	}

	void remove(const Key& key) {
		Node *node = find(key);
		if (node)
			remove(node);
	}

	typedef void (*VisitFunction)(Value&);

	void traverse(VisitFunction f)
	{
		visit(root, f);
	}

private:

	void insert(Node *& treeNode, Node *newNode)
	{
		if (treeNode == NULL)
			treeNode = newNode;
		else if (newNode->key < treeNode->key)
			insert(treeNode->left, newNode);
		else
			insert(treeNode->right, newNode);
	}

	Node *find(const Key& key, Node *node)
	{
		if (node == NULL)
			return NULL;
		else if (node->key < key)
			return find(key, node->left);
		else if (node->key > key)
			return find(key, node->right);
		else
			return node;
	}

	void remove(Node *& node) {
		if (node->left == NULL) { 
			Node *temp = node;
			node = node->right;
			delete temp;
		} else if (node->right == NULL) {
			Node *temp = node;
			node = node->left;
			delete temp;
		} else {
			// In-order predecessor (rightmost child of left subtree) 
			// Node has two children - get max of left subtree
			Node **temp = &node->left; // get left node of the original node

			// find the rightmost child of the subtree of the left node
			while ((*temp)->right != NULL) {
				temp = &(*temp)->right;
			}

			// copy the contents from the in-order predecessor to the original node
			node->key = (*temp)->key;
			node->value = (*temp)->value;

			// then delete the predecessor
			remove(*temp);
		}
	}

	void visit(Node *node, VisitFunction f)
	{
		if (node == NULL)
			return;

		visit(node->left, f);

		f(node->value);

		visit(node->right, f);
	}
};

#endif
