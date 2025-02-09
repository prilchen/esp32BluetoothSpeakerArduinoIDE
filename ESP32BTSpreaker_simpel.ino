#include <DFRobot_MAX98357A.h>

DFRobot_MAX98357A amplifier;   // instantiate an object to control the amplifier

void setup(void)
{
  Serial.begin(115200);

  while( !amplifier.begin(/*btName=*/"prilchensBTBox", /*bclk=*/GPIO_NUM_25, /*lrclk=*/GPIO_NUM_26, /*din=*/GPIO_NUM_27) ){
    Serial.println("Initialize failed !");
    delay(3000);
  }
  Serial.println("Initialize succeed!");
}

void loop(void)
{
//kann leer bleiben
}