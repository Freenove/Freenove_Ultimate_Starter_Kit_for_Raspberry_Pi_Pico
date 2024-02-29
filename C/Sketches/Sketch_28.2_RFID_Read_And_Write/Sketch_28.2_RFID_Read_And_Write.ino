/**********************************************************************
  Filename    : RFID_Read_And_Write
  Description : Read the card number, write new data to the card
  Auther      : www.freenove.com
  Modification: 2021/10/13
**********************************************************************/
#include <SPI.h>
#include <RFID.h>

//pin5:pin of card reader SDA.  pin6:pin of card reader RST
RFID rfid(5, 6);

// 4-byte card serial number, the fifth byte is check byte
unsigned char serNum[5];
unsigned char status;
unsigned char str[MAX_LEN];
unsigned char blockAddr;        //Select the operation block address: 0 to 63

// Write card data you want(within 16 bytes)
unsigned char writeDate[16] = "WelcomeFreenove";

// The A password of original sector: 16 sectors; the length of password in each sector is 6 bytes.
unsigned char sectorKeyA[16][16] = {
  {  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF  } ,
  {  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF  } ,
  {  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF  } ,
  {  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF  } ,
  {  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF  } ,
  {  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF  } ,
  {  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF  } ,
  {  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF  } ,
  {  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF  } ,
  {  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF  } ,
  {  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF  } ,
  {  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF  } ,
  {  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF  } ,
  {  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF  } ,
  {  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF  } ,
  {  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF  } ,
};

void setup()
{
  Serial.begin(115200);
  SPI.setRX(4);
  SPI.setCS(5);
  SPI.setSCK(2);
  SPI.setTX(3);
  SPI.begin();
  rfid.init();
  Serial.println("Please put the card to the induction area...");
}

void loop()
{
  //find the card
  rfid.findCard(PICC_REQIDL, str);
  //Anti-collision detection, read serial number of card
  if (rfid.anticoll(str) == MI_OK) {
    Serial.print("The card's number is  : ");
    //print the card serial number
    for (int i = 0; i < 4; i++) {
      Serial.print(0x0F & (str[i] >> 4), HEX);
      Serial.print(0x0F & str[i], HEX);
    }
    Serial.println("");
    memcpy(rfid.serNum, str, 5);
  }
  //select card and return card capacity (lock the card to prevent multiple read and written)
  rfid.selectTag(rfid.serNum);
  //first, read the data of data block 4
  readCard(4);
  //write data(within 16 bytes) to data block
  writeCard(4);
  //then read the data of data block again
  readCard(4);

  rfid.halt();
}

//write the card
void writeCard(int blockAddr) {
  if (rfid.auth(PICC_AUTHENT1A, blockAddr, sectorKeyA[blockAddr / 4], rfid.serNum) == MI_OK) //authenticate
  {
    //write data
    //status = rfid.write((blockAddr/4 + 3*(blockAddr/4+1)), sectorKeyA[0]);
    Serial.print("set the new card password, and can modify the data of the Sector: ");
    Serial.println(blockAddr / 4, DEC);
    // select block of the sector to write data
    if (rfid.write(blockAddr, writeDate) == MI_OK) {
      Serial.println("Write card OK!");
    }
  }
}

//read the card
void readCard(int blockAddr) {
  if ( rfid.auth(PICC_AUTHENT1A, blockAddr, sectorKeyA[blockAddr / 4], rfid.serNum) == MI_OK) // authenticate
  {
    // select a block of the sector to read its data
    Serial.print("Read from the blockAddr of the card : ");
    Serial.println(blockAddr, DEC);
    if ( rfid.read(blockAddr, str) == MI_OK) {
      Serial.print("The data is (char type display): ");
      Serial.println((char *)str);
      Serial.print("The data is (HEX type display): ");
      for (int i = 0; i < sizeof(str); i++) {
        Serial.print(str[i], HEX);
        Serial.print(" ");
      }
      Serial.println();
    }
  }
}
