#include <stdio.h>
#include <stdlib.h>

typedef struct Entry{
    int key;
    char* value;
}entry;

typedef struct HashTable{
    int len;
    entry** entries;
}ht;

entry* create_entry(int key, char* value){
    entry* tmp = (entry*)malloc(sizeof(entry));
    tmp->key = key;
    tmp->value = value;
    return tmp;
}

ht* create_ht(int len){
    ht* tmp = (ht*)malloc(sizeof(ht));
    tmp->len = len;
    tmp->entries = (entry**)malloc(len * sizeof(entry));
    return tmp;
}

int hashing(int key, int max_value){
    return key % max_value;
}

int re_hashing(int key, int max_value, int i){
    return (key + i) % max_value;
}

void insert(ht* hash_table, int key, char* value){
    int index = hashing(key, hash_table->len);
    
    int i = 1;
    while (hash_table->entries[index] != NULL && hash_table->entries[index]->key != key){
        if (i > hash_table->len){
            printf("tabela cheia!");
            break;
        }
        index = re_hashing(key, hash_table->len, i);
        i++;
    }
    hash_table->entries[index] = create_entry(key, value);
}

entry* get(ht* hash_table, int key){
    int index = hashing(key, hash_table->len);
    
    if (hash_table->entries[index] == NULL){
        printf("chave %d não existe na tabela hash!", key);
    }
    
    int i = 1;
    while (hash_table->entries[index]->key != key){
        if (i > hash_table->len){
            printf("chave %d não existe na tabela hash!", key);
            break;
        }
        index = re_hashing(key, hash_table->len, i);
        i++;
    }
    return hash_table->entries[index];
}

void print_entries(ht* hash_table){
    for (int i = 0; i < hash_table->len; i++){
        printf("[%d] (%d) %s\n", i, hash_table->entries[i]->key, hash_table->entries[i]->value);
    }
}

int main() {
   
    ht* ddds = create_ht(9);
    
    insert(ddds, 61, "Brasilia");
    insert(ddds, 71, "Salvador");
    insert(ddds, 11, "Sao Paulo");
    insert(ddds, 21, "Rio de Janeiro");
    insert(ddds, 32, "Juiz de Fora");
    insert(ddds, 19, "Campinas");
    insert(ddds, 27, "Vitoria");
    insert(ddds, 31, "Belo Horizonte");
    insert(ddds, 83, "João Pessoa");
    
    while (1){
        int ddd;
        
        print_entries(ddds);
        
        printf("\n# Digite um ddd --> ");
        scanf("%d", &ddd);
        printf("%s\n\n", get(ddds, ddd)->value);
    }
    
    return 0;
}
