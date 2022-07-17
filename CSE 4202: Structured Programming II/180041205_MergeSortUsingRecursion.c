#include<stdio.h>
int a[100];//eitake globally declare dewa lagbe

int Min(int a, int b)
{
    return (a>b)?b:a;
}
void Merge(int a[], int left, int mid, int right)//Divide and Conquer tah eikhanei hoyxce jaitese
{
    int temporary[1000],i=left,j=mid+1,k=left;//k left dhora lagbe cuz main function eh chaile ami left change korte pari
    while(i<=mid && j<=right)//basically temporary[k]=min(a[i],a[j])
    {
        temporary[k]=Min(a[i],a[j]);
        k++;
        if(a[i]<a[j])//a[i] choto hoile i++
        {
            i++;
        }
        else
        {
            j++;//a[j] choto hoile j++
        }
    }
    while(i<=mid)//baki gula borabor boshay dibo
    {
        temporary[k]=a[i];
        k++;
        i++;
    }
    while(j<=right)//same
    {
        temporary[k]=a[j];
        k++;
        j++;
    }
    for(i=left; i<=right; i++)//ekhon just copy the temporary array to the main a[]
    {
        a[i]=temporary[i];
    }

}
void MergeSort(int left, int right)//ei function tah just left right same na howa porjontoh sub array gula ke divide and conquer marbe
{
    int mid;
    if(left!=right)
    {
        mid=(left+right)/2;
        MergeSort(left,mid);
        MergeSort(mid+1,right);
        Merge(a,left,mid,right);
    }
}
int main()
{
    int n,i;
    printf("What's the size of the array?\n");
    scanf("%d",&n);
    printf("\nEnter the elements:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    MergeSort(0,n-1);
    printf("\nThe Sorted Array is:\n");
    for(i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
