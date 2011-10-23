int main(void)
{
  int a[10];// = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
  int i;
  
  for (i=0; i<10; i++)
  {
    switch(i)
    {
    case 1:
    case 2:
      a[i] *= i;
      break;
      
    case 5:
      a[i] += i;
      break;
      
    default:
      a[i] += 1;
      break;
    }
  }
  
  return 0;
}


