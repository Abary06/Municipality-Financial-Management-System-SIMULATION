#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100

// Asset structure
typedef struct
{
    int id;
    char name[100];
    char type[100];
    float purchaseValue;
    char department[100];
    char condition[100];
} Asset;

// Asset data
extern Asset assets[MAX_ASSETS];
extern int assetCount;

// Asset functions
void assetMenu(void);
void addAsset(void);
void displayAssets(void);
void searchAsset(void);
int assetIDExists(int id);

// Input functions from main.c
int readInt(void);
float readFloat(void);
void readNonEmptyString(char text[], int size);

#endif