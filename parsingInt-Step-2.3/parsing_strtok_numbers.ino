void setup()
{
  Serial.begin(9600);
}
uint8_t myParseInt(char *str, uint8_t digits)
{
  char c[digits];
  uint8_t j = 0;
  for (uint8_t i = 0; i < strlen(str); i++)
  {
    if (str[i] >= '0' && str[i] <= '9')       // saves 10 bytes of if( isDigit(a))
    {
      c[j++] = str[i];                        //1852/196g bytes used
    }
  }
  return atoi(c);
}
void loop()
{
  char *a = "abc:123";
  int i =  myParseInt(a,3);
  Serial.println(i);
}


