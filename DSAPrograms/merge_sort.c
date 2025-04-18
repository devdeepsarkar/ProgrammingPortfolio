#include <stdio.h>
#define max 8
void merge(int, int, int);
int arr[max];
void merge_sort(int left, int right)
{
    if (left != right)
    {
        int mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge(left, mid, right);
    }
}

void merge(int left, int mid, int right)
{
    int temp[max];
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    int i;
    for (i = 0; i < max; i++)
    {
        printf("Enter %dth element ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n");
    for (i = 0; i < max; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nSorted array: \n");
    merge_sort(0, 7);
    for (i = 0; i < max; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
