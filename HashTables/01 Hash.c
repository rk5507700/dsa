// Understanding the hash tables and hash functions
#include<stdlib.h>
#include<stdio.h>

typedef struct
{
    int value;
    int index;
} HashItem;

int hashFunction(int value, int size){
    return abs(value)%size;
}

int min(int a, int b){
    if( a < b)
        return a;
    return b;
}

void insert(HashItem* HashTable[], int HashTableSize, int value, int index){
    int HashTableIndex = hashFunction(value, HashTableSize);
    while(HashTable[HashTableIndex] != NULL){
        HashTableIndex = (HashTableIndex + 1) % HashTableSize;
    }
    HashTable[HashTableIndex] = (HashItem*)malloc(sizeof(HashItem));
    HashTable[HashTableIndex] -> index = index;
    HashTable[HashTableIndex] -> value = value;
}


int Search(int key, HashItem* HashTable[], int HashTableSize){
    int HashIndex = hashFunction(key, HashTableSize);
    while(HashTable[HashIndex] != NULL){
        if(HashTable[HashIndex]->value == key){
            return HashTable[HashIndex]->index;
        }
        HashIndex = (HashIndex + 1)%HashTableSize;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main(int argc, char const *argv[])
{
    int nums[] = {1, 4, 7, 9, 10, 58};
    int * retSize = (int*)malloc(sizeof(int));
    int* result = twoSum(nums, 6, 19, retSize);
    if(result[0] != '\0'){
        printf("\n %d %d\n", result[0], result[1]);
    }
    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    HashItem* HashTable[2 * numsSize];
    for (int i = 0; i < (2*numsSize); i++)
    {
        HashTable[i] = NULL;
    }
    int* result = malloc(2*sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        int complement = target - nums[i];
        int complementIndex = Search(complement, HashTable, 2*numsSize);
        if(complementIndex != -1){
            result[0] = ;
            result[1] = complementIndex;
            *returnSize = 2;
            return result;
        }
        insert(HashTable, 2*numsSize, nums[i], i);
    }
    *returnSize = 0;
    return NULL;
    
}