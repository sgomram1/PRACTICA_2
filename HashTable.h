#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include <string>
#include "Dict.h"
#include "TableEntry.h"

#include "../PRACTICA_1/ListLinked.h"

template <typename V>
class HashTable : public Dict<V>{
	private:
    		int n;
    		int max;
    		ListLinked<TableEntry<V>>* table;

    		int h(std::string key){
        		int sum = 0;
        		for(int i = 0; i < (int)key.size(); i++){
            			sum += int(key.at(i));
        		}
        		return sum % max;
    		}

	public:
    		HashTable(int size) : n(0), max(size){
        		table = new ListLinked<TableEntry<V>>[max];
    		}

    		~HashTable(){
        		delete[] table;
    		}

    		void insert(std::string key, V value){
        		int pos = h(key);
        		TableEntry<V> te(key, value);
        		if(table[pos].search(TableEntry<V>(key))){
            			throw std::runtime_error("key exists");
        		}
        		table[pos].insert(te);
        		n++;
    		}

    		V search(std::string key){
        		int pos = h(key);
        		TableEntry<V> te = table[pos].search(TableEntry<V>(key));
        		return te.value;
    		}

    		V remove(std::string key){
        		int pos = h(key);
        		TableEntry<V> te = table[pos].remove(TableEntry<V>(key));
        		n--;
        		return te.value;
    		}

    		int entries(){
        		return n;
    		}

    		int capacity(){
        		return max;
    		}

    		V operator[](std::string key){
        		return search(key);
    		}

    		friend std::ostream& operator<<(std::ostream& out, const HashTable<V>& ht){
        		for(int i = 0; i < ht.max; i++){
            			out << i << ": ";
            			ht.table[i].print();
            			out << std::endl;
        		}
        		return out;
    		}
};

#endif
