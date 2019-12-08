#include <stdio.h>
#include <stdlib.h>

// ----------- Guide ----------- : //
//Hash table is a Data Structure which we can put elements in a table ( Key -> Value )
//can We find elements in O(1) with the Hash Table?! Yes, we can. Because the elements are indexed.

//We have the following ADT:
//put() -> put an element in table
//get() -> get an element of the table
//remove_element() -> remove an element of the table
//contains_key() -> check if the table constains a key
//print_hash_table() -> print the hash table

#define maxN 11

typedef struct Element
{
  int key, value;
}Element;

//Pointers array (Type : element)
typedef struct HashTable
{
  Element *table[maxN];
}HashTable;

HashTable* create_hash_table()
{
  HashTable *new_hash_table = (HashTable *) malloc(sizeof(HashTable));
  int i;
  for(i = 0; i < maxN; i++)
    new_hash_table -> table[i] = NULL;
  return new_hash_table;
}

void put(HashTable *ht, int key, int value)
{
  int h = key % maxN; //hash function
  while(ht->table[h] != NULL)
  {
    if(ht -> table[h] -> key == key)
    {
      ht -> table[h] -> value = value;
      break;
    }
    h = (h + 1) % maxN;
  }
  if(ht -> table[h] == NULL)
  {
    Element *new_element = (Element *) malloc(sizeof(Element));
    new_element -> key = key;
    new_element -> value = value;
    ht -> table[h] = new_element;
  }
}

int get(HashTable *ht, int key, int value)
{
  int h = key % maxN;
  while(ht -> table[h] != NULL)
  {
    if(ht -> table[h] -> key == key)
      return ht -> table[h] -> value;
    h = (h + 1) % maxN;
  }
  return -100; //Element not found
}

void remove_element(HashTable *ht, int key)
{
  int h = key % maxN;
  while(ht -> table[h] != NULL)
  {
    if(ht -> table[h] -> key == key)
      ht -> table[h] -> value = -1;
    h = (h + 1) % maxN;
  }
}

void print_hash(HashTable *ht)
{
  for(int i = 0; i < maxN; i++)
  {
    if(ht -> table[i] != NULL && ht -> table[i] -> value != -1)
      printf("KEY = %d <---> Value = %d\n", ht -> table[i] -> key, ht -> table[i] -> value);
  }
}

int main()
{  
  HashTable *ht = create_hash_table(); 
 
  put(ht, 3, 1000);
  put(ht, 14, 1500);
  put(ht, 15, 1600);
  put(ht, 92, 1700);

  print_hash(ht);
  remove_element(ht, 14);
  remove_element(ht, 92);
  print_hash(ht);

  return 0;
}
