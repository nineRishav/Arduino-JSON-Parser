char *token[] = {"lon", "lat", "temp", "pressure", "humidity", "speed"};
uint8_t noOfVal = sizeof(token) / 2;
float values[sizeof(token) / 2];

void setup()
{
  Serial.begin(4800);
  //Serial.println("------------Started--------------");
  parseMyJson();
}

void parseMyJson()
{
  char str[] = "lat:22.72,lon:75.83,a:2,bad:65,max:temp:23,pressure:1006,humidity:94,wind:speed:2.1, abc:123, cab:132";
  char *saveptr1;
  char *ptr1;

  ptr1 = strtok_r(str, ",", &saveptr1);
  while (ptr1 != NULL)
  {
    //Serial.print(">>  ");
    //Serial.println(ptr1);
    tokenValues(&ptr1);
    ptr1 = strtok_r(NULL, ",", &saveptr1);
    Serial.print("\n");
  }
  displayValues();
}


void tokenValues(char **str)
{
  char *ptr2;
  char *saveptr2;
  uint8_t tokenPos;
  ptr2 = strtok_r(*str, ":", &saveptr2);
  while (ptr2 != NULL)
  {
    tokenPos = tokenPresentAbsent(ptr2);
    if (strcmp(ptr2, token[tokenPos]) == 0)
    {
      Serial.print("Value is : ");
      ptr2 = strtok_r(NULL, ":", &saveptr2);
      Serial.println(ptr2);
      values[tokenPos] = atof(ptr2);
      break;
    }
    ptr2 = strtok_r(NULL, ":", &saveptr2);
  }
}

uint8_t tokenPresentAbsent(char* value)
{
  uint8_t pos = 0;
  if (strcmp(value, token[pos]) == 0)
    return pos;
  else
  {
    while (pos < noOfVal && strcmp(value, token[pos]) != 0)
      pos++;

    return pos;
  }
}

void displayValues()
{
  //Serial.println("\nFinal Answer : ");
  for (uint8_t k = 0; k < noOfVal; k++)
  {
    Serial.print(token[k]);
    Serial.print(" : ");
    Serial.println(values[k]);
  }
  //Serial.println("-----------------------");
}
void loop()
{

}


