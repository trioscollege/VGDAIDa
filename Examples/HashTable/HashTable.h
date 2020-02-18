#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cstddef> // NULL
#include <iostream>
#include <string>

using namespace std;


//
// A hash table with fixed Key type (string).
// Value type is a template argument.
//

template <class Value>
class HashTable
{
	typedef string Key;

	struct Node
	{
		Key key;
		Value value;
		Node *next;
		Node *prev;

		Node(const Key& key, const Value& value)
		:	key(key), value(value), next(NULL), prev(NULL)
		{
		}

		~Node()
		{
		}

		// NB: no interface to get next and prev Nodes;
		// i.e., cannot iterate over Nodes "in public"
	};

	// an array of pointers to Nodes
	Node **table;

	// number of table slots (!= number of current entries)
	unsigned size;

	// the hash function
	unsigned hash(const Key& str)
	{
        unsigned hash = 5381;

		for (unsigned i=0; i<str.length(); i++)
            hash = hash * 33 + str[i];
        return hash % size;
	}

public:

	// An Entry object is returned as the result of a find operation
	class Entry
	{
		friend class HashTable;

		Node *node;

		Entry(Node *node)
		:	node(node)
		{
		}

	public:

		Entry()
		:	node(NULL)
		{
		}

		bool isValid() const              { return node != NULL; }
		const Key getKey() const          { return node->key; }
		const Value getValue() const      { return node->value; }
		void setValue(const Value& value) { node->value = value; }
	};


	HashTable(unsigned size=997)
	:	table(new Node*[size]()), size(size)
	{
		// all table slots are now initialized to NULL
	}

	~HashTable()
	{
		purge();
		delete [] table;
	}

	Entry insert(const Key& key, const Value& value)
	{
		unsigned index = hash(key);
		Node *iter = table[index];
		Node *prev_iter = NULL;

		if (!iter) {
			table[index] = new Node(key, value);
			return table[index];
		}

		for ( ; iter; iter=iter->next) {
			if (iter->key >= key) {
				if (key == iter->key) {
					// iter is the node with same key as new key;
					// just update the node's value
					iter->value = value;
					return iter;
				} else {
					// iter is the first node with key greater than new key;
					// insert new node before iter
					Node *tmp = new Node(key, value);
					tmp->next = iter;
					tmp->prev = iter->prev;
					// is iter the head?
					if (!iter->prev)
						table[index] = tmp;
					else
						iter->prev->next = tmp;
					iter->prev = tmp;
					return tmp;
				}
			}
			// keep track of last non-NULL node visited
			prev_iter = iter;
		}

		// if we get here, than all existing keys were smaller than new key;
		// insert new node at end of list
		Node *tmp = new Node(key, value);
		tmp->prev = prev_iter;
		prev_iter->next = tmp;
		return tmp;
	}

	Entry find(const Key& key)
	{
		unsigned index = hash(key);
		Node *iter;

		for (iter=table[index]; iter; iter=iter->next) {
			if (iter->key == key)
				return iter;
			else if (iter->key > key)
				return NULL;
		}
		return NULL;
	}

	void remove(const Key& key)
	{
		unsigned index = hash(key);
		Node *iter;

		// find the entry with this key
		for (iter=table[index]; iter; iter=iter->next) {
			if (iter->key == key)
				// key found
				break;
			else if (iter->key > key)
				// key not found
				return;
		}

		// is this iterator valid?
		if (!iter)
			return;

		// is this the head of the list?
		if (!iter->prev)
			table[index] = iter->next;
		else
			iter->prev->next = iter->next;

		// is this the tail of the list?
		if (!iter->next)
			table[index] = NULL;
		else
			iter->next->prev = iter->prev;

		delete iter;
	}

	void purge()
	{
		for (unsigned i=0; i<size; i++) {
			Node *iter = table[i];
			while (iter) {
				Node *tmp = iter;
				iter = iter->next;
				delete tmp;
			}
			table[i] = NULL;
		}
		size = 0;
	}

	// prints all entries
	void print() const
	{
		for (unsigned i=0; i<size; i++)
			for (Node *iter=table[i]; iter; iter=iter->next) {
				printEntry(iter);
				cout << endl;
			}
		cout << endl;
	}

	// prints a single entry
	void printEntry(const Node *entry) const
	{
		if (entry)
			cout << entry->key << ":" << entry->value;
	}

	// prints the table structure
	void printTable() const
	{
		for (unsigned i=0; i<size; i++) {
			cout << i << ":\t";
			Node *iter = table[i];
			printEntry(iter);
			if (iter) iter = iter->next;
			for ( ; iter; iter=iter->next) {
				cout << ", ";
				printEntry(iter);
			}
			cout << endl;
		}
		cout << endl;
	}

};

#endif // HASHTABLE_H
