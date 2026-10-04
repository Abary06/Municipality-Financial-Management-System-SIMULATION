#include <stdio.h>
#include "assets.h"

// Asset data
Asset assets[MAX_ASSETS];
int assetCount = 0;


// Check if Asset ID already exists
int assetIDExists(int id)
{
    int i;

    for (i = 0; i < assetCount; i++)
    {
        if (assets[i].id == id)
        {
            return 1;
        }
    }

    return 0;
}


// Asset Menu
void assetMenu(void)
{
    int choice;

    do
    {
        printf("\n========== ASSET MANAGEMENT ==========\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("0. Back\n");
        printf("Enter your choice: ");

        choice = readInt();

        switch (choice)
        {
            case 1:
                addAsset();
                break;

            case 2:
                displayAssets();
                break;

            case 3:
                searchAsset();
                break;

            case 0:
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);
}


// Add Asset
void addAsset(void)
{
    if (assetCount >= MAX_ASSETS)
    {
        printf("Asset limit reached.\n");
        return;
    }

    do
    {
        printf("Enter Asset ID: ");
        assets[assetCount].id = readInt();

        if (assets[assetCount].id <= 0)
        {
            printf("Asset ID must be greater than 0.\n");
        }
        else if (assetIDExists(assets[assetCount].id))
        {
            printf("Asset ID already exists. Enter a different ID.\n");
        }

    } while (assets[assetCount].id <= 0 ||
             assetIDExists(assets[assetCount].id));

    printf("Enter Asset Name: ");
    readNonEmptyString(assets[assetCount].name,
                       sizeof(assets[assetCount].name));

    printf("Enter Asset Type: ");
    readNonEmptyString(assets[assetCount].type,
                       sizeof(assets[assetCount].type));

    do
    {
        printf("Enter Purchase Value: ");
        assets[assetCount].purchaseValue = readFloat();

        if (assets[assetCount].purchaseValue < 0)
        {
            printf("Purchase value cannot be negative.\n");
        }

    } while (assets[assetCount].purchaseValue < 0);

    printf("Enter Department: ");
    readNonEmptyString(assets[assetCount].department,
                       sizeof(assets[assetCount].department));

    printf("Enter Condition: ");
    readNonEmptyString(assets[assetCount].condition,
                       sizeof(assets[assetCount].condition));

    assetCount++;

    printf("Asset added successfully.\n");
}


// Display Assets
void displayAssets(void)
{
    int i;

    if (assetCount == 0)
    {
        printf("No assets available.\n");
        return;
    }

    printf("\n========== ASSETS ==========\n");

    for (i = 0; i < assetCount; i++)
    {
        printf("\nAsset ID: %d\n", assets[i].id);
        printf("Name: %s\n", assets[i].name);
        printf("Type: %s\n", assets[i].type);
        printf("Purchase Value: %.2f\n",
               assets[i].purchaseValue);
        printf("Department: %s\n", assets[i].department);
        printf("Condition: %s\n", assets[i].condition);
    }
}


// Search Asset
void searchAsset(void)
{
    int id;
    int i;

    printf("Enter Asset ID to search: ");
    id = readInt();

    for (i = 0; i < assetCount; i++)
    {
        if (assets[i].id == id)
        {
            printf("\nAsset Found\n");
            printf("ID: %d\n", assets[i].id);
            printf("Name: %s\n", assets[i].name);
            printf("Type: %s\n", assets[i].type);
            printf("Purchase Value: %.2f\n",
                   assets[i].purchaseValue);
            printf("Department: %s\n", assets[i].department);
            printf("Condition: %s\n", assets[i].condition);
            return;
        }
    }

    printf("Asset not found.\n");
}