void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char str[] = "temp:36.87, humidity:5.32, wind:23.1";
  float values[3];
  char *ptr1;
  uint8_t i = 0;

  ptr1 = strtok(str, ",");
  if (ptr1 != NULL)
    values[i] = myParseFloat(ptr1, 5 );

  while (ptr1 != NULL)
  {
    i++;
    ptr1 = strtok(NULL, ",");
    values[i] = myParseFloat(ptr1, 5 );
  }

  for (uint8_t k = 0; k < 3; k++)
  {
    Serial.println(values[k]);
  }
//  memset(values,0,sizeof(values));
  delay(6000);
}


float myParseFloat(char *str, uint8_t digits)
{
  char c[digits];
  uint8_t j = 0;
  for (uint8_t i = 0; i < strlen(str); i++)
  {
    if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '.'))       // saves 10 bytes of if( isDigit(a)) is not used
    {
      c[j++] = str[i];                        //1852/196g bytes used
    }
  }
  return atof(c);
}
