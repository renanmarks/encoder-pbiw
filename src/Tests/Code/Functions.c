
int Sum(int a, int b)
{
  return a+b;
}

int Sub(int a, int b)
{
  return a-b;
}

int RShift(int a, int b)
{
  return a << b;
}

int main(void)
{
  int a;
  int b;
  
  a = 5;
  b = 2;
  
  return Sum(Sub(a, b), RShift(a,b));
}
