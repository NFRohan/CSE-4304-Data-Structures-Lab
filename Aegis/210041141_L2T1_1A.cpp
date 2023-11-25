#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

void bubbleSort(vector<int> &arr)
{
  int n = arr.size();
  bool swapped;
  for (int i = 0; i < n - 1; i++)
  {
    swapped = false;
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if (!swapped)
    {
      break;
    }
  }
}

int binary_search(vector<int> &arr, int target)
{
  int left = 0;
  int right = arr.size() - 1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (arr[mid] <= target)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  return left;
}

int main()
{
  int N, R;
  cin >> N >> R;

  vector<int> sp(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> sp[i];
  }
  bubbleSort(sp);

  for (int i = 0; i < R; ++i)
  {
    int ap;
    cin >> ap;
    int killed_soldiers = binary_search(sp, ap);
    //finds the index of the last soldier killed
    cout << killed_soldiers <<endl;
    cout<<endl;
  }

  return 0;
}
