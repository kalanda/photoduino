/*
 * This file is part of Photoduino.
 *
 * Photoduino is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Photoduino is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Photoduino.  If not, see <http://www.gnu.org/licenses/>.
 */


// Write a unsigned int (two bytes) value to eeprom
void eeprom_writeInt(unsigned int address, unsigned int value){

  EEPROM.write(address, value % 256); // LSB
  EEPROM.write(address+1, value/256); // MSB

}

// read a unsigned int (two bytes) value from eeprom
unsigned int eeprom_readInt(unsigned int address){

  return EEPROM.read(address)+EEPROM.read(address+1)*256;

}


// increment the value of a variable using minimun and maximun limits (byte version)
void circularList_incrementBy(byte *value, byte minimun, byte maximun, int incrementBy) {

  if (incrementBy>0) {

    if (*value+incrementBy > maximun) *value = minimun; 
    else *value = *value+incrementBy;

  } 
  else {

    if ( (*value < minimun) || (*value < (incrementBy*(-1)) )) *value = maximun;
    else *value = *value+incrementBy;

  }

}

// increment the value of a variable using minimun and maximun limits (unsigned int version)
void circularList_incrementBy(unsigned int *value, unsigned int minimun, unsigned int maximun, int incrementBy) {

  if (incrementBy>0) {

    if (*value+incrementBy > maximun) *value = minimun; 
    else *value = *value+incrementBy;

  } 
  else {

    if ( (*value < minimun) || (*value < (incrementBy*(-1)) )) *value = maximun;
    else *value = *value+incrementBy;

  }
}

// increment the value of a variable using minimun and maximun limits (unsigned int version)
void circularList_matchBy(unsigned int *value, unsigned int targetValue, unsigned int minimun, unsigned int maximun, int offset) {

  if (offset>0) {

    if (targetValue+offset > maximun) *value = maximun; 
    else *value = targetValue+offset;

  } 
  else {

    if ( targetValue < (offset*(-1)) ) *value = minimun;
    else *value = targetValue+offset;

  }  
}






