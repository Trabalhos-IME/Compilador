#include "hash.h"

/* Codigo Retirado do Stack Overflow: http://stackoverflow.com/questions/6844739/c-implement-a-hash-table
	por se tratar apenas de uma estrutura de dados básica, que poderia estar contida em uma biblioteca padrao.
*/

/*int hash_fun(int key, int try, int max) {
    return (key + try) % max;
}


int hash_insert(char *data, struct hash_table *hash_table) {
    int try, hash;
    if(hash_table->number_of_elements >= hash_table->max) {
        return 0; // FULL
    }
    for(try = 0; true; try++) {
        hash = hash_fun(data->key, try, hash_table->max);
        if(hash_table->elements[hash] == 0) { // empty cell
            hash_table->elements[hash] = data;
            hash_table->number_of_elements++;
            return 1;
        }
    }
    return 0;
}

char *hash_retrieve(int key, struct hash_table *hash_table) {
    int try, hash;
    for(try = 0; true; try++) {
        hash = hash_fun(key, try, hash_table->max);
        if(hash_table->elements[hash] == 0) {
            return 0; // Nothing found
        }
        if(hash_table->elements[hash]->key == key) {
            return hash_table->elements[hash];
        }
    }
    return 0;
}

int hash_delete(int key, struct hash_table *hash_table) {
    int try, hash;
    for(try = 0; true; try++) {
        hash = hash_fun(key, try, hash_table->max);
        if(hash_table->elements[hash] == 0) {
            return 0; // Nothing found
        }
        if(hash_table->elements[hash]->key == key) {
            hash_table->number_of_elements--;
            hash_table->elements[hash] = 0;
            return 1; // Success
        }
    }
    return 0;
}*/
