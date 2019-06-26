char buffer[400];
int i = 0;
void setup()
{
  Serial.begin(4800);
}

void loop()
{
  filter();
}

void filter()
{
  while (Serial.available() > 0)
  {
    char thisChar = Serial.read();
    if (!thisChar == '[' || thisChar == ']' || thisChar == '{' || thisChar == '}' || thisChar == '"')
    {}
    else
    {
      buffer[i] = thisChar;
      Serial.print(buffer[i]);
      i++;
    }
  }
}
