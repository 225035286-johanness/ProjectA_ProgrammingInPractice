#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100

typedef struct {
    int assetID;
    char assetName[50];
    char assetType[30];
    float purchaseValue;
    char department[30];
    char condition[20];
} Asset;

extern Asset assets[MAX_ASSETS];
extern int assetCount;

void assetMenu(void);
void addAsset(void);
void displayAssets(void);
void searchAsset(void);
void assetReport(void);

int getAssetCount(void);
float getTotalAssetValue(void);
Asset* getAssetsArray(void);

#endif