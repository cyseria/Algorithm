#include<stdlib.h>
#include<stdio.h>

int total = 0;
int length = 0;
void Merge(int sourceArr[],int tempArr[],int startIndex,int midIndex,int endIndex)
{
    int i = startIndex, j = midIndex + 1, k = startIndex;
    while (i != midIndex + 1 && j != endIndex + 1) {
        if (sourceArr[i] <= sourceArr[j]) {
            tempArr[k++] = sourceArr[i++];
        }
        else {
            total += midIndex - i + 1; //统计逆序对
            tempArr[k++] = sourceArr[j++];
        }
    }
    while (i != midIndex + 1)
        tempArr[k++] = sourceArr[i++];
    while (j != endIndex+1)
        tempArr[k++] = sourceArr[j++];
    for (i = startIndex; i <= endIndex; i++)
        sourceArr[i] = tempArr[i];


}

//内部使用递归
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
    int midIndex;
    if (startIndex < endIndex)
    {
        midIndex = (startIndex + endIndex) / 2;
        MergeSort(sourceArr, tempArr, startIndex, midIndex);
        MergeSort(sourceArr, tempArr, midIndex+1, endIndex);
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}

int main(int argc,char * argv[])
{

    scanf("%d\n", &length);
    int numArr[length],tempArr[length];
    for (int i = 0; i < length; i++) {
        scanf("%d",&numArr[i]);
    }
    MergeSort(numArr,tempArr,0,length - 1);
    printf("%d ",total);
    return 0;
}
