#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict : public Dict<V>{
	private:
    		BSTree<TableEntry<V>>* tree;

	public:
    		BSTreeDict(){
        		tree = new BSTree<TableEntry<V>>();
    		}

    		~BSTreeDict(){
        		delete tree;
    		}

    		int entries(){
        		return tree->size();
    		}

    		void insert(std::string key, V value){
        		tree->insert(TableEntry<V>(key, value));
    		}

    		V search(std::string key){
        		TableEntry<V> te = tree->search(TableEntry<V>(key));
        		return te.value;
    		}

    		V remove(std::string key){
        		TableEntry<V> te = tree->search(TableEntry<V>(key));
        		tree->remove(TableEntry<V>(key));
        		return te.value;
    		}

    		V operator[](std::string key){
        		return search(key);
    		}

    		friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bd){
        		out << *(bd.tree);
        		return out;
    		}
};

#endif
