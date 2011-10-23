int main(void)
{
  int a[10];// = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
  int b[10];// = { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 };
  int i;
  
  for (i=0; i<10; i++)
    b[i] = a[i];
  
  return 0;
}

