#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "assets.h"
Asset assets[MAX_ASSETS];
int assetCount=0;
void clearInputA(){int c;while((c=getchar())!='\n'&&c!=EOF);}
int isEmptyString(char *s){if(strlen(s)==0)return 1;for(int i=0;s[i];i++){if(!isspace((unsigned char)s[i]))return 0;}return 1;}
void assetMenu(){int ch;do{printf("\n--- ASSET MANAGEMENT (Student 4) ---\n1. Add Asset\n2. Display All\n3. Search Asset\n4. Asset Report\n5. Back\nChoice: ");scanf("%d",&ch);clearInputA();switch(ch){case 1:addAsset();break;case 2:displayAssets();break;case 3:searchAsset();break;case 4:assetReport();break;case 5:return;default:printf("Invalid!\n");}}while(ch!=5);}
void addAsset(){if(assetCount>=MAX_ASSETS){printf("Full!\n");return;}Asset n;printf("Asset ID: ");scanf("%d",&n.assetID);clearInputA();for(int i=0;i<assetCount;i++)if(assets[i].assetID==n.assetID){printf("Duplicate ID!\n");return;}printf("Name: ");fgets(n.assetName,50,stdin);n.assetName[strcspn(n.assetName,"\n")]=0;if(isEmptyString(n.assetName)){printf("Empty!\n");return;}printf("Type: ");fgets(n.assetType,30,stdin);n.assetType[strcspn(n.assetType,"\n")]=0;printf("Value: ");scanf("%f",&n.purchaseValue);clearInputA();if(n.purchaseValue<0){printf("Negative!\n");return;}printf("Dept: ");fgets(n.department,30,stdin);n.department[strcspn(n.department,"\n")]=0;printf("Condition: ");fgets(n.condition,20,stdin);n.condition[strcspn(n.condition,"\n")]=0;assets[assetCount++]=n;printf("Added! Total %d\n",assetCount);}
void displayAssets(){if(assetCount==0){printf("No assets\n");return;}printf("\n%-6s %-20s %-12s %-10s %-12s %-10s\n","ID","Name","Type","Value","Dept","Cond");for(int i=0;i<assetCount;i++)printf("%-6d %-20s %-12s %-10.2f %-12s %-10s\n",assets[i].assetID,assets[i].assetName,assets[i].assetType,assets[i].purchaseValue,assets[i].department,assets[i].condition);}
void searchAsset(){int o;printf("Search 1.ID 2.Dept 3.Type: ");scanf("%d",&o);clearInputA();if(o==1){int id;printf("ID: ");scanf("%d",&id);clearInputA();for(int i=0;i<assetCount;i++)if(assets[i].assetID==id){printf("Found %s %.2f\n",assets[i].assetName,assets[i].purchaseValue);return;}printf("Not found\n");}else if(o==2){char d[30];printf("Dept: ");fgets(d,30,stdin);d[strcspn(d,"\n")]=0;for(int i=0;i<assetCount;i++)if(strcmp(assets[i].department,d)==0)printf("%d %s %.2f\n",assets[i].assetID,assets[i].assetName,assets[i].purchaseValue);}else{char t[30];printf("Type: ");fgets(t,30,stdin);t[strcspn(t,"\n")]=0;for(int i=0;i<assetCount;i++)if(strcmp(assets[i].assetType,t)==0)printf("%d %s %.2f\n",assets[i].assetID,assets[i].assetName,assets[i].purchaseValue);}}
int getAssetCount(){return assetCount;}
float getTotalAssetValue(){float t=0;for(int i=0;i<assetCount;i++)t+=assets[i].purchaseValue;return t;}
Asset* getAssetsArray(){return assets;}
