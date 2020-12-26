int w_clk = 8;
int fq_ud = 9;
int data  = 10;

unsigned int frequency;


void setup() {
  pinMode(w_clk, OUTPUT);
  pinMode(fq_ud, OUTPUT);
  pinMode(data, OUTPUT);
  pinMode(frequency, OUTPUT);
  

}

void loop() {
  frequency = 0x008000000;
  digitalWrite(w_clk, LOW);
  digitalWrite(fq_ud, LOW);

  for (int i = 0; i<= 31; i++)
  {
    if (frequency & ((unsigned long)1 << i))
    {
      digitalWrite(data, HIGH);
    }

    else
    {
      digitalWrite(data, LOW);
    }

    digitalWrite(w_clk, HIGH);
    digitalWrite(w_clk, LOW);
  }

  for (int i =7; i >= 0; i--)
  {
    digitalWrite(data, LOW);
    digitalWrite(w_clk, HIGH);
    digitalWrite(w_clk, LOW);
  }

digitalWrite(fq_ud, HIGH);
digitalWrite(fq_ud, LOW);
while(1);

}
